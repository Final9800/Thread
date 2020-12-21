#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->progressBar1->setRange(0,100);
    ui->progressBar2->setRange(0,100);
    ui->progressBar3->setRange(0,100);

    ui->progressBar1->setValue(0);
    ui->progressBar2->setValue(0);
    ui->progressBar3->setValue(0);

    connect(&t1, SIGNAL(progress(int)), this, SLOT(onProgress1(int)));
    connect(&t2, SIGNAL(progress(int)), this, SLOT(onProgress2(int)));
    connect(&t3, SIGNAL(progress(int)), this, SLOT(onProgress3(int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onProgress1(int i)
{
    ui->progressBar1->setValue(i);
}

void Dialog::onProgress2(int i)
{
    ui->progressBar2->setValue(i);
}

void Dialog::onProgress3(int i)
{
    ui->progressBar3->setValue(i);
}

void Dialog::on_pushButtonStart1_clicked()
{
    t1.start();
    t1.resume();

}

void Dialog::on_pushButtonStart2_clicked()
{
    t2.start();
    t2.resume();
}

void Dialog::on_pushButtonStart3_clicked()
{
    t3.start();
    t3.resume();
}

void Dialog::on_pushButtonStop1_clicked()
{
    t1.stop();
}

void Dialog::on_pushButtonStop2_clicked()
{
    t2.stop();
}

void Dialog::on_pushButtonStop3_clicked()
{
    t3.stop();
}

