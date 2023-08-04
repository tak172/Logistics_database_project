#include "second_report.h"
#include "ui_second_report.h"

second_report::second_report(QWidget *parent) : QDialog(parent), ui(new Ui::second_report) {

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    query1 = new QSqlQueryModel;
    query2 = new QSqlQueryModel;

    err = new QErrorMessage(this);
    err->setModal(true);
    err->resize(500, 100);

}

second_report::~second_report() {

    delete ui;

}

void second_report::open_second_w_sl() {

    query1->setQuery("select truck_id, downtime_costs/(empty_expenses + useful_travel) as 'Коэффициент' from truck;");
    ui->tableView->setModel(query1);

    query2->setQuery("select AVG(k) from (select truck_id, downtime_costs/(empty_expenses + useful_travel) as 'k' from truck) a");
    ui->tableView_avg->setModel(query2);

    this->show();

    if (!query1->rowCount()) {
        err->showMessage("Запрос невозможно выполнить! Сначала введите необходимые данные для отчета.");
        this->close();
    }

}
void second_report::on_pushButton_clicked() {

    this->close();

}
