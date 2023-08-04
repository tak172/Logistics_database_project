#include "delete_truck_w.h"
#include "ui_delete_truck_w.h"

delete_truck_w::delete_truck_w(QWidget *parent) :QDialog(parent), ui(new Ui::delete_truck_w) {

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    query = new QSqlQueryModel;
    err = new QErrorMessage(this);

    err->setModal(true);
    err->resize(500, 100);

}

delete_truck_w::~delete_truck_w() {

    delete ui;

}

void delete_truck_w::closeEvent(QCloseEvent *bar) {

    emit this->close_delete_tr();
    bar->accept();

}
void delete_truck_w::open_delete_truck() {

    this->show();

}

void delete_truck_w::on_delete_button_clicked() {

    query->setQuery("select * from truck;");
    int bef = query->rowCount();

    QString Text = "delete from trucks where truck_id = " + ui->delete_Edit->text() +
                   "; delete from truck where truck_id = " + ui->delete_Edit->text() + ";";
    query->setQuery(Text);

    query->setQuery("select * from truck;");
    int aft = query->rowCount();

    if (query->lastError().isValid()) {
        err->showMessage("Номер грузовика введен не корректно!\nПопробуйте еще раз.");
    }
    else if (bef == aft){
        err->showMessage("Трактора под таким номером не существует!\nПопробуйте еще раз.");
    }

    emit close_delete_tr();
    ui->delete_Edit->clear();

}
void delete_truck_w::on_close_button_clicked() {

    emit close_delete_tr();
    this->close();

}
