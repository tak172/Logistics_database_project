#include "fifth_report.h"
#include "ui_fifth_report.h"

fifth_report::fifth_report(QWidget *parent) : QDialog(parent), ui(new Ui::fifth_report) {

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    query = new QSqlQueryModel;
    err = new QErrorMessage(this);

    err->setModal(true);
    err->resize(500, 100);

}

fifth_report::~fifth_report() {

    delete ui;

}

void fifth_report::open_fifth_rep_w() {

    this->show();

    query->setQuery("select ordering_id, expenses, profit from orders where completed = 1;");

    if (query->rowCount()){
        ui->tableView->setModel(query);
    }
    else {
        this->close();
        err->showMessage("Еще нет выполненных заказов!");
    }

}

void fifth_report::on_pushButton_clicked() {

    this->close();

}
