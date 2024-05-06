#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton_yes->setToolTip("This is a 'yes' button!");
    ui->pushButton_yes->setToolTipDuration(3000);

    ui->pushButton_no->setToolTip("This is a 'no' button!");
    ui->pushButton_no->setToolTipDuration(3000);

}

Widget::~Widget()
{
    delete ui;
}
