#include "widget.h"
#include "ui_widget.h"

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
    QString ans = "今天的安排：";
    if (ui->checkBox->isChecked()) {
        ans += "学习 ";
    }
    if (ui->checkBox_2->isChecked()) {
        ans += "吃饭 ";
    }
    if (ui->checkBox_3->isChecked()) {
        ans += "睡觉 ";
    }
    ui->label->setText(ans);
}

