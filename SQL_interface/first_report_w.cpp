#include "first_report_w.h"
#include "ui_first_report_w.h"

first_report_w::first_report_w(QWidget *parent) : QDialog(parent), ui(new Ui::first_report_w) {

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    query1 = new QSqlQueryModel;
    query2 = new QSqlQueryModel;

    err = new QErrorMessage(this);
    err->setModal(true);
    err->resize(500, 100);

}

first_report_w::~first_report_w() {

    delete ui;

}
void first_report_w::open_first_rep_w_sl() {
    query1->setQuery("select truck_id, empty_expenses/useful_travel as 'Коэффициент' from truck;");
    ui->tableView->setModel(query1);

    query2->setQuery("select AVG(avgk) as AVG from (select truck_id, "
                     "empty_expenses/useful_travel as 'avgk' from truck) a;");
    ui->tableView_avg->setModel(query2);

    this->show();

    if (!query1->rowCount()) {
        err->showMessage("Запрос невозможно выполнить! Сначала введите необходимые данные для отчета.");
        this->close();
    }

}
void first_report_w::on_close_Button_clicked(){

    this->close();

}
