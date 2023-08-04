#ifndef REPORTS_WINDOW_H
#define REPORTS_WINDOW_H

#include <QWidget>
#include <first_report_w.h>
#include <second_report.h>
#include <third_report_w.h>
#include <fourth_report.h>
#include <fifth_report.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Reports_window; }
QT_END_NAMESPACE

class Reports_window : public QDialog {

    Q_OBJECT

public:

    explicit Reports_window(QWidget *parent = nullptr);
    ~Reports_window();

private:

    Ui::Reports_window *ui;
    first_report_w *f_r;
    second_report *s_r;
    third_report_w *th_r;
    fourth_report *four_r;
    fifth_report *fif_r;

public slots:

    void open_reports_w_sl();

private slots:

    void on_first_button_clicked();
    void on_second_button_clicked();
    void on_third_button_clicked();
    void on_fourth_button_clicked();
    void on_fifth_button_clicked();

signals:

    void open_first_rep_w();
    void open_second_rep_w();
    void open_third_rep_w();
    void open_fourth_rep_w();
    void open_fifth_rep_w();

};

#endif // REPORTS_WINDOW_H
