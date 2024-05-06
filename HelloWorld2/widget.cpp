#include "widget.h"
#include "ui_widget.h"

#include "mylabel.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QLabel *label = new QLabel(this);

    // MyLabel *label = new MyLabel(this);
    // label->setText("hello world");

    MyLabel label(this);
    label.setText("hello world");
}

Widget::~Widget()
{
    delete ui;
}
