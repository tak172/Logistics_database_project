#ifndef INITIAL_CAPITAL_H
#define INITIAL_CAPITAL_H

#include <QDialog>
#include <QErrorMessage>
#include <QIntValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class initial_capital; }
QT_END_NAMESPACE

class initial_capital : public QDialog {

    Q_OBJECT

public:

    explicit initial_capital(QWidget *parent = nullptr);
    ~initial_capital();

private:

    Ui::initial_capital *ui;
    QErrorMessage *err;

public slots:

    void open_initial_sl();

private slots:

    void on_pushButton_clicked();

signals:

    void close_capit(double val);

};

#endif // INITIAL_CAPITAL_H
