#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setTextFormat(Qt::PlainText);
    ui->label->setText("This is a PlainText!");

    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setText("<b>This is a RichText!<b>");

    ui->label_3->setTextFormat(Qt::MarkdownText);
    ui->label_3->setText("# This is a MarkdownText!");
}

Widget::~Widget()
{
    delete ui;
}
