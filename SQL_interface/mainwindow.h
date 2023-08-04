#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <purchase_window.h>
#include <delete_truck_w.h>
#include <ordering_window.h>
#include <reports_window.h>
#include <initial_capital.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_tableselection_activated(int index);
    void on_purchase_button_clicked();
    void on_sale_button_clicked();
    void on_order_button_clicked();
    void on_reports_Button_clicked();

public slots:

    void close_purchase_w_sl();
    void close_delete_tr_sl();
    void close_ordering_w_sl(double val);
    void close_initial_w_sl(double val);

private:

    QSqlDatabase db;

    Ui::MainWindow *ui;
    Purchase_window* pur;
    QSqlQueryModel* dbmodel;
    delete_truck_w* dtw;
    ordering_window* ord;
    Reports_window* rep;
    initial_capital* cap;

    QStringList ls;
    double capit;

signals:

    void open_purchase_w();
    void open_delete_truck_w();
    void open_ordering_w(double val);
    void open_reports_w();
    void open_initial_w();

};

#endif // MAINWINDOW_H
