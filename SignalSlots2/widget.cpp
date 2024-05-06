#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    pushButton = new QPushButton(this);
    pushButton->setText("hello wyn");
    pushButton->move(350, 250);

    connect(pushButton, &QPushButton::clicked, this, &Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    if (pushButton->text() == QString("hello wyn")) {
        pushButton->setText("hello cl");
    } else {
        pushButton->setText("hello wyn");
    }
}
