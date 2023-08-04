#ifndef FIRST_REPORT_W_H
#define FIRST_REPORT_W_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QErrorMessage>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class first_report_w; }
QT_END_NAMESPACE

class first_report_w : public QDialog {

    Q_OBJECT

public:

    explicit first_report_w(QWidget *parent = nullptr);
    ~first_report_w();

private:

    Ui::first_report_w *ui;
    QSqlQueryModel *query1;
    QSqlQueryModel *query2;
    QErrorMessage *err;

public slots:

    void open_first_rep_w_sl();

private slots:

    void on_close_Button_clicked();

};

#endif // FIRST_REPORT_W_H
