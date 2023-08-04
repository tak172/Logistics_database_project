#ifndef FOURTH_REPORT_H
#define FOURTH_REPORT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class fourth_report; }
QT_END_NAMESPACE

class fourth_report : public QDialog {

    Q_OBJECT

public:

    explicit fourth_report(QWidget *parent = nullptr);
    ~fourth_report();

private slots:

    void on_pushButton_clicked();

private:

    Ui::fourth_report *ui;
    QSqlQueryModel *query;

public slots:

    void open_fourth_w_sl();

};

#endif // FOURTH_REPORT_H
