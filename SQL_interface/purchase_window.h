#ifndef PURCHASE_WINDOW_H
#define PURCHASE_WINDOW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QCloseEvent>
#include <QDialog>
#include <QSqlError>
#include <QErrorMessage>

QT_BEGIN_NAMESPACE
namespace Ui { class Purchase_window; }
QT_END_NAMESPACE

class Purchase_window :  public QDialog {

    Q_OBJECT

public:

    explicit Purchase_window(QWidget *parent = nullptr);
    ~Purchase_window();

private:

    Ui::Purchase_window *ui;
    QSqlQueryModel *query;
    QErrorMessage *err;

    void closeEvent(QCloseEvent *bar);

public slots:

    void open_purchase_w_sl();

private slots:

    void on_add_button_clicked();
    void on_close_button_clicked();

signals:

    void close_purchase_w();

};

#endif // PURCHASE_WINDOW_H
