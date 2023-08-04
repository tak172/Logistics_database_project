#include "reports_window.h"
#include "ui_reports_window.h"

Reports_window::Reports_window(QWidget *parent) : QDialog(parent), ui(new Ui::Reports_window) {

    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    f_r = new first_report_w(this);
    s_r = new second_report(this);
    th_r = new third_report_w(this);
    four_r = new fourth_report(this);
    fif_r = new fifth_report(this);

    fif_r->setModal(true);
    four_r->setModal(true);
    th_r->setModal(true);
    s_r->setModal(true);
    f_r->setModal(true);

    connect(this, &Reports_window::open_first_rep_w, f_r, &first_report_w::open_first_rep_w_sl);
    connect(this, &Reports_window::open_second_rep_w, s_r, &second_report::open_second_w_sl);
    connect(this, &Reports_window::open_third_rep_w, th_r, &third_report_w::open_third_w_sl);
    connect(this, &Reports_window::open_fourth_rep_w, four_r, &fourth_report::open_fourth_w_sl);
    connect(this, &Reports_window::open_fifth_rep_w, fif_r, &fifth_report::open_fifth_rep_w);

}
Reports_window::~Reports_window() {

    delete ui;

}

void Reports_window::open_reports_w_sl() {

    this->show();

}

void Reports_window::on_first_button_clicked() {

    emit open_first_rep_w();

}

void Reports_window::on_second_button_clicked() {

    emit open_second_rep_w();

}

void Reports_window::on_third_button_clicked() {

    emit open_third_rep_w();

}

void Reports_window::on_fourth_button_clicked() {

    emit open_fourth_rep_w();

}

void Reports_window::on_fifth_button_clicked() {

    emit open_fifth_rep_w();

}

