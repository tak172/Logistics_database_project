#ifndef DELETE_TRUCK_W_H
#define DELETE_TRUCK_W_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QCloseEvent>
#include <QDialog>
#include <QSqlError>
#include <QErrorMessage>

QT_BEGIN_NAMESPACE
namespace Ui { class delete_truck_w; }
QT_END_NAMESPACE

class delete_truck_w : public QDialog {

    Q_OBJECT

public:

    explicit delete_truck_w(QWidget *parent = nullptr);
    ~delete_truck_w();

private:

    Ui::delete_truck_w *ui;
    QSqlQueryModel* query;
    QErrorMessage *err;

    void closeEvent(QCloseEvent *bar);

public slots:

    void open_delete_truck();

private slots:

    void on_delete_button_clicked();
    void on_close_button_clicked();

signals:

    void close_delete_tr();

};

#endif // DELETE_TRUCK_W_H
