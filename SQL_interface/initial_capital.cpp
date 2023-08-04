#include "initial_capital.h"
#include "ui_initial_capital.h"

initial_capital::initial_capital(QWidget *parent) : QDialog(parent), ui(new Ui::initial_capital) {

    ui->setupUi(this);

    this->setWindowFlag(Qt::WindowCloseButtonHint, false);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    ui->lineEdit->setValidator(new QIntValidator);

    err = new QErrorMessage(this);
    err->setModal(true);
    err->resize(500, 100);

}

initial_capital::~initial_capital() {
    delete ui;
}

void initial_capital::open_initial_sl() {
    this->show();
}

void initial_capital::on_pushButton_clicked() {

    double val = ui->lineEdit->text().toDouble();

    if (val <= 0){
        err->showMessage("Не корректно введен капитал! Попробуйте еще раз.");
        ui->lineEdit->clear();
    }
    else {
        emit close_capit(val);
        this->close();
    }

}
