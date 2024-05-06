#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QResizeEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QRect windowRect = this->geometry();
    // ui->label->setGeometry(0, 0, windowRect.width(), windowRect.height());
    ui->label->setPixmap(QPixmap(":/baobao.JPG"));
    ui->label->setScaledContents(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
    ui->label->setGeometry(0, 0, event->size().width(), event->size().height());
}
