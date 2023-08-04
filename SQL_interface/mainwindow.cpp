#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName("root");
    db.setHostName("localhost");
    db.setDatabaseName("");
    db.setPassword("");
    db.open();

    pur = new Purchase_window(this);
    pur->setModal(true);

    dbmodel = new QSqlQueryModel;
    dtw = new delete_truck_w(this);
    dtw->setModal(true);

    ord = new ordering_window(this);
    ord->setModal(true);

    rep = new Reports_window(this);
    rep->setModal(true);

    cap = new initial_capital(this);
    cap->setModal(true);

    dbmodel->setQuery("Delete from truck; Delete from trucks; Delete from orders; Delete from ordering; "
                      "ALTER TABLE truck AUTO_INCREMENT = 1; ALTER TABLE orders AUTO_INCREMENT = 1; "
                      "ALTER TABLE ordering AUTO_INCREMENT = 1; update city set sent = 0;"
                      " update city set accepted = 0; update cargo_type set cargo_popularity = 0; "
                      "ALTER TABLE trucks AUTO_INCREMENT = 1;");

    ls = db.tables();
    ls.erase(ls.begin() + 3);
    ls.erase(ls.begin() + 4);

    dbmodel->setQuery("select * from " + ls.first() + ";");
    ui->tableView->setModel(dbmodel);
    ui->tableselection->addItems(ls);

    connect(this, &MainWindow::open_purchase_w, pur, &Purchase_window::open_purchase_w_sl);
    connect(this, &MainWindow::open_delete_truck_w, dtw, &delete_truck_w::open_delete_truck);
    connect(this, &MainWindow::open_ordering_w, ord, &ordering_window::open_ordering_w_sl);
    connect(this, &MainWindow::open_reports_w, rep, &Reports_window::open_reports_w_sl);
    connect(this, &MainWindow::open_initial_w, cap, &initial_capital::open_initial_sl);

    connect (pur, &Purchase_window::close_purchase_w, this, &MainWindow::close_purchase_w_sl);
    connect (dtw, &delete_truck_w::close_delete_tr, this, &MainWindow::close_delete_tr_sl);
    connect (ord, &ordering_window::close_ordering_w, this, &MainWindow::close_ordering_w_sl);
    connect(cap, &initial_capital::close_capit, this, &MainWindow::close_initial_w_sl);

    emit open_initial_w();

}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::on_tableselection_activated(int index) {

    dbmodel->setQuery("select * from " + ls.at(index) + ";");

}

void MainWindow::on_purchase_button_clicked() {

    emit open_purchase_w();

}

void MainWindow::on_sale_button_clicked() {

    emit open_delete_truck_w();

}

void MainWindow::on_order_button_clicked() {

    emit open_ordering_w(capit);

}

void MainWindow::on_reports_Button_clicked() {

    emit open_reports_w();

}

void MainWindow::close_purchase_w_sl() {

    dbmodel->setQuery("select * from truck;");
    ui->tableselection->setCurrentIndex(4);

}

void MainWindow::close_delete_tr_sl() {

    dbmodel->setQuery("select * from truck;");
    ui->tableselection->setCurrentIndex(4);

}

void MainWindow::close_ordering_w_sl(double val) {

    dbmodel->setQuery("select * from orders;");
    ui->tableselection->setCurrentIndex(3);
    capit+=val;
    ui->capit_label->setNum(capit);

}

void MainWindow::close_initial_w_sl(double val) {

    capit = val;
    ui->capit_label->setNum(capit);

}
