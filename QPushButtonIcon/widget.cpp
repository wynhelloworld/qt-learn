#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    QIcon icon(":/button.svg");
    ui->pushButton->setIcon(icon);
    ui->pushButton->setIconSize(QSize(200, 200));
}

Widget::~Widget()
{
    delete ui;
}
