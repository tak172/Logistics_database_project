#ifndef FIFTH_REPORT_H
#define FIFTH_REPORT_H

#include <QDialog>
#include <QSqlError>
#include <QErrorMessage>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class fifth_report; }
QT_END_NAMESPACE

class fifth_report : public QDialog {

    Q_OBJECT

public:

    explicit fifth_report(QWidget *parent = nullptr);
    ~fifth_report();

private:

    Ui::fifth_report *ui;
    QSqlQueryModel *query;
    QErrorMessage *err;

public slots:

    void open_fifth_rep_w();

private slots:

    void on_pushButton_clicked();

};

#endif // FIFTH_REPORT_H
