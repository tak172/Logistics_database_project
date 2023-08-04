#include "fourth_report.h"
#include "ui_fourth_report.h"

fourth_report::fourth_report(QWidget *parent) : QDialog(parent), ui(new Ui::fourth_report) {

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    query = new QSqlQueryModel;

}

fourth_report::~fourth_report(){

    delete ui;

}

void fourth_report::on_pushButton_clicked(){

    this->close();

}

void fourth_report::open_fourth_w_sl(){

    this->show();
    query->setQuery("select cargo_type, cargo_popularity from cargo_type order by 2 desc;");
    ui->tableView->setModel(query);

}
