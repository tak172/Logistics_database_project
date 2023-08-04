#include "purchase_window.h"
#include "qevent.h"
#include "ui_purchase_window.h"

Purchase_window::Purchase_window(QWidget *parent) : QDialog(parent), ui(new Ui::Purchase_window) {

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    query = new QSqlQueryModel;
    err = new QErrorMessage(this);
    err->setModal(true);
    err->resize(500, 100);

}

Purchase_window::~Purchase_window() {

    delete ui;

}

void Purchase_window::closeEvent(QCloseEvent *bar) {

    emit close_purchase_w();
    bar->accept();

}

void Purchase_window::open_purchase_w_sl() {

    this->show();

}

void Purchase_window::on_add_button_clicked() {

    QString Text = "insert into truck (load_capacity, truck_price, downtime_costs, freight_charges, empty_expenses, cargo_type_id, city_id, free_date) "
                   "select " + ui->capacity_Edit->text() + ", " + ui->price_Edit->text() +
                   ", 0, 0, 0, cargo_type_id, city_id, '2020-01-01' from cargo_type inner join city "
                   "where cargo_type = '" + ui->cargo_type_Edit->text() + "' and name_city = '" + ui->city_Edit->text() + "';";

    query->setQuery(Text);
    Text = "insert into trucks (load_capacity, truck_price, downtime_costs, freight_charges, empty_expenses, cargo_type_id, city_id, free_date) "
           "select " + ui->capacity_Edit->text() + ", " + ui->price_Edit->text() +
           ", 0, 0, 0, cargo_type_id, city_id, '2020-01-01' from cargo_type inner join city "
           "where cargo_type = '" + ui->cargo_type_Edit->text() + "' and name_city = '" + ui->city_Edit->text() + "';";

    query->setQuery(Text);

    if (query->lastError().isValid()) {
        err->showMessage("Данные для добавления грузовика введены не корректно! Попробуйте еще раз.");
    }

    emit close_purchase_w();

    ui->capacity_Edit->clear();
    ui->cargo_type_Edit->clear();
    ui->price_Edit->clear();
    ui->city_Edit->clear();

}

void Purchase_window::on_close_button_clicked() {

    emit close_purchase_w();
    this->close();

}
