#include "third_report_w.h"
#include "ui_third_report_w.h"

third_report_w::third_report_w(QWidget *parent) : QDialog(parent), ui(new Ui::third_report_w) {

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    query = new QSqlQueryModel;

}

third_report_w::~third_report_w() {

    delete ui;

}

void third_report_w::open_third_w_sl() {

    this->show();
    query->setQuery("select name_city, sent, accepted from city order by 2 desc, 3 desc;");
    ui->tableView->setModel(query);

}

void third_report_w::on_pushButton_clicked() {

    this->close();

}
