#include "widget.h"
#include "ui_widget.h"

#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QDateTime dateTimeOld = ui->dateTimeEdit->dateTime();
    QDateTime dateTimeNew = ui->dateTimeEdit_2->dateTime();

    int seconds = dateTimeOld.secsTo(dateTimeNew);
    int hours = (seconds / 3600) % 24;
    int days = (seconds / 3600) / 24;

    ui->label->setText(QString("爱你已经持续了 ") + QString::number(days) + " 天零 " + QString::number(hours) + " 小时");
}

