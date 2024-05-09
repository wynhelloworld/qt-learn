#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton *btn = new QPushButton(this);
    btn->setGeometry(0, 0, 100, 100);
    btn->setText("按钮");

    btn->setStyleSheet("QPushButton { border: 5px solid red; margin-top: 50px; padding-left: 20px; }");
}

Widget::~Widget()
{
    delete ui;
}
