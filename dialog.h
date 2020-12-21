#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qprogressthread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void onProgress1(int i);
    void onProgress2(int i);
    void onProgress3(int i);

    void on_pushButtonStart1_clicked();
    void on_pushButtonStart2_clicked();
    void on_pushButtonStart3_clicked();
    void on_pushButtonStop1_clicked();
    void on_pushButtonStop2_clicked();
    void on_pushButtonStop3_clicked();

private:
    Ui::Dialog *ui;
    QProgressThread t1, t2, t3;
};
#endif // DIALOG_H
