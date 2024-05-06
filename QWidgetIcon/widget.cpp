#include "widget.h"
#include "ui_widget.h"

#include <QIcon>
#include <QDir>
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

void Widget::on_pushButton_clicked()
{
    // QIcon icon("/Users/wyn/Pictures/baobao.JPG");
    QIcon icon(":/baobao.JPG");
    this->setWindowIcon(icon);
    qDebug() << "icon";
}

