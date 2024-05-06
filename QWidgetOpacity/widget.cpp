#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

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

void Widget::on_pushButton_up_clicked()
{
    double opacity = this->windowOpacity();
    qDebug() << opacity;
    if (opacity >= 1.0) {
        return;
    }
    opacity += 0.1;
    this->setWindowOpacity(opacity);
}


void Widget::on_pushButton_down_clicked()
{
    double opacity = this->windowOpacity();
    qDebug() << opacity;
    if (opacity <= 0.0) {
        return;
    }
    opacity -= 0.1;
    this->setWindowOpacity(opacity);
}

