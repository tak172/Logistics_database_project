#include "ordering_window.h"
#include "ui_ordering_window.h"
#include <QFile>

ordering_window::ordering_window(QWidget *parent) : QDialog(parent), ui(new Ui::ordering_window) {

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    query = new QSqlQueryModel;

    err = new QErrorMessage(this);
    err->setModal(true);
    err->resize(500, 100);

}

ordering_window::~ordering_window() {

    delete ui;

}

void ordering_window::closeEvent(QCloseEvent *bar) {

    emit close_ordering_w(0);
    bar->accept();

}

void ordering_window::open_ordering_w_sl(double val) {

    this->show();
    capit = val;

}

void ordering_window::on_add_Button_clicked() {

    bool fl = false, fl2 = false;

    QString Text = "set @ct_id = (select cargo_type_id from cargo_type where cargo_type = '" + ui->cargo_Edit->text() + "');";
    query->setQuery(Text);

    if (query->lastError().isValid())
        fl = true;

    query->setQuery("select cargo_type_id from cargo_type where cargo_type = '" + ui->cargo_Edit->text() + "';");

    if (!query->rowCount())
        fl = true;

    query->setQuery("select * from truck where cargo_type_id = @ct_id;");

    if (!query->rowCount())
        fl2 = true;

    Text = " set @st_id = (select city_id from city where name_city = '" + ui->start_Edit->text() + "');";

    if (!fl)
        query->setQuery(Text);

    if (query->lastError().isValid())
        fl = true;

    query->setQuery("select city_id from city where name_city = '" + ui->start_Edit->text() + "';");

    if (!query->rowCount())
        fl = true;

    Text =  " set @f_id = (select city_id from city where name_city = '" + ui->finish_Edit->text() + "');";

    if (!fl)
        query->setQuery(Text);

    if (query->lastError().isValid())
        fl = true;

    query->setQuery("select city_id from city where name_city = '" + ui->finish_Edit->text() + "';");

    if (!query->rowCount())
        fl = true;

    Text = " insert into ordering(volume, cargo_type_id, start_city_id, finish_city_id, date_ordering)"
        " values(" + ui->volume_Edit->text() + ", @ct_id, @st_id, @f_id, '" + ui->date_Edit->text() + "');";

    if (!fl)
        query->setQuery(Text);

    if (query->lastError().isValid())
        fl = true;

    if (fl || fl2){
        if (fl)
            err->showMessage("Данные для оформления заказа введены не корректно!");
        else if (fl2)
            err->showMessage("Не существует трактора, способного доставить ваш заказ!");
    }
    else {

        Text = " insert into orders(volume, cargo_type, start_city, finish_city, date_ordering) values("
           + ui->volume_Edit->text() + ", '" + ui->cargo_Edit->text() + "', '" + ui->start_Edit->text() + "', '"
           + ui->finish_Edit->text() + "', '" + ui->date_Edit->text() + "');";

        query->setQuery(Text);

        Text = "update city set sent = sent + " + ui->volume_Edit->text() + " where city_id = @st_id;"
             + "update city set accepted = accepted + " + ui->volume_Edit->text() + " where city_id = @f_id;" +
               "update cargo_type set cargo_popularity = cargo_popularity + " + ui->volume_Edit->text() + " where cargo_type_id = @ct_id";

        query->setQuery(Text);
        query->setQuery("select * from ordering;");

        int x = query->rowCount();

        query->setQuery("set @ord_id = (select max(ordering_id) from orders);");

        while (x != 0){

            Text = "set @t_id = (select truck_id from truck WHERE cargo_type_id = @ct_id"
                   " ORDER BY free_date asc, load_capacity desc LIMIT 1);";

            query->setQuery(Text);

            Text = "update truck set downtime_costs = if (datediff('" + ui->date_Edit->text() +
                   "',free_date) > 0, downtime_costs + datediff('" + ui->date_Edit->text()
                   + "',free_date), downtime_costs), free_date = '" + ui->date_Edit->text() +
                   "' where truck_id = @t_id;";

            query->setQuery(Text);

            Text = "set @d_before_s = (SELECT distance from distance d inner join truck t on t.city_id = d.city1_id"
                   " where truck_id = @t_id and city2_id = @st_id);";

            query->setQuery(Text);

            Text = "update truck set empty_expenses = empty_expenses + @d_before_s, city_id = @st_id where truck_id = @t_id;";

            query->setQuery(Text);

            Text = "set @d_after_s = (select distance from distance where city1_id = @st_id and city2_id = @f_id);";

            query->setQuery(Text);

            Text = "update truck, orders set freight_charges = freight_charges + truck_price * (@d_before_s + @d_after_s),"
                   " city_id = @f_id, free_date = adddate(free_date, @d_before_s + @d_after_s), useful_travel = useful_travel"
                   " + @d_after_s, expenses = expenses + truck_price * (@d_before_s + @d_after_s) where truck_id = @t_id and ordering_id = @ord_id;";

            query->setQuery(Text);

            Text = "update ordering, truck set volume = volume - load_capacity where truck_id = @t_id;";

            query->setQuery(Text);

            Text = "delete from ordering where volume <= 0;";

            query->setQuery(Text);

            query->setQuery("select * from ordering;");

            x = query->rowCount();

        }

        query->setQuery("update orders set profit = (select " + ui->volume_Edit->text() + " * price from cargo_type where cargo_type_id = @ct_id)"
                                                                                          " where ordering_id = @ord_id;");
    }

    query->setQuery("select expenses from orders where ordering_id = @ord_id");

    if (query->data(query->index(0,0)).toDouble() > capit) {

        query->setQuery("delete from truck; insert into truck select * from trucks;");
        emit close_ordering_w(0);
        err->showMessage("Для совершения заказа не хватает средств.");

    }
    else {

        query->setQuery("delete from trucks; insert into trucks select * from truck;");
        query->setQuery("update orders set completed = true where ordering_id = @ord_id;");
        query->setQuery("select profit from orders where ordering_id = @ord_id");

        double x = query->data(query->index(0,0)).toDouble();
        emit close_ordering_w(x);

    }

    ui->cargo_Edit->clear();
    ui->finish_Edit->clear();
    ui->start_Edit->clear();
    ui->volume_Edit->clear();
    ui->date_Edit->clear();

}
void ordering_window::on_close_Button_clicked() {

    emit close_ordering_w(0);
    this->close();

}
