#ifndef ORDERING_WINDOW_H
#define ORDERING_WINDOW_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDialog>
#include <QCloseEvent>
#include <QSqlError>
#include <QErrorMessage>

QT_BEGIN_NAMESPACE
namespace Ui { class ordering_window; }
QT_END_NAMESPACE

class ordering_window : public QDialog {

    Q_OBJECT

public:

    explicit ordering_window(QWidget *parent = nullptr);
    ~ordering_window();

private:

    Ui::ordering_window *ui;
    QSqlQueryModel *query;

    void closeEvent(QCloseEvent *bar);

    QErrorMessage *err;
    double capit;

public slots:

    void open_ordering_w_sl(double val);

private slots:

    void on_add_Button_clicked();
    void on_close_Button_clicked();

signals:

    void close_ordering_w(double val);

};

#endif // ORDERING_WINDOW_H
