#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(nullptr));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_study_clicked()
{
    ui->label->setText("未来生活新福美满，事业蒸蒸日上");
}


void Widget::on_pushButton_sleep_pressed()
{
    int width = this->geometry().width();
    int height = this->geometry().height();

    int x = rand() % (width - ui->pushButton_sleep->geometry().width());
    int y=  rand() % (height - ui->pushButton_sleep->geometry().height());

    ui->pushButton_sleep->move(x, y);
}

