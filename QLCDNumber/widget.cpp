#include "widget.h"
#include "ui_widget.h"

#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lcdNumber->display(10);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::handle);
    timer->start(1000); // 每 1000 ms触发一次信号
}

Widget::~Widget()
{
    delete ui;
}


