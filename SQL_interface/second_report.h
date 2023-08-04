#ifndef SECOND_REPORT_H
#define SECOND_REPORT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QErrorMessage>

QT_BEGIN_NAMESPACE
namespace Ui { class second_report; }
QT_END_NAMESPACE

class second_report : public QDialog {

    Q_OBJECT

public:

    explicit second_report(QWidget *parent = nullptr);
    ~second_report();

private:

    Ui::second_report *ui;
    QSqlQueryModel *query1;
    QSqlQueryModel *query2;
    QErrorMessage *err;

public slots:

    void open_second_w_sl();

private slots:

    void on_pushButton_clicked();

};

#endif // SECOND_REPORT_H
