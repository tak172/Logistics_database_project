#ifndef THIRD_REPORT_W_H
#define THIRD_REPORT_W_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class third_report_w; }
QT_END_NAMESPACE

class third_report_w : public QDialog {

    Q_OBJECT

public:

    explicit third_report_w(QWidget *parent = nullptr);
    ~third_report_w();

private:

    Ui::third_report_w *ui;
    QSqlQueryModel *query;

public slots:

    void open_third_w_sl();

private slots:

    void on_pushButton_clicked();

};

#endif // THIRD_REPORT_W_H
