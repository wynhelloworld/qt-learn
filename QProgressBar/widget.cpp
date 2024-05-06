#include "widget.h"
#include "ui_widget.h"

#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
    ui->progressBar->setStyleSheet("QProgressBar::chunk {background: red}");

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::handle);
    timer->start(100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    int value = ui->progressBar->value();
    if (value >= 100) {
        timer->stop();
        return;
    }
    ui->progressBar->setValue(value + 1);
}
