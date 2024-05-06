#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this, &Widget::mySignal, this, &Widget::handleMySignal);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleMySignal(const QString &text)
{
    this->setWindowTitle(text);
}

void Widget::on_pushButton_clicked()
{
    emit mySignal(QString("你不花妆"));
}

void Widget::on_pushButton_2_clicked()
{
    emit mySignal(QString("也非常美"));
}

