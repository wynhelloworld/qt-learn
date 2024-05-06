#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置对齐方式
    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    ui->label->setText("这是一段文本");

    // 设置自动换行
    ui->label_2->setText("这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本");
    ui->label_2->setWordWrap(true);

    // 设置缩进
    ui->label_3->setText("这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本");
    ui->label_3->setWordWrap(true);
    ui->label_3->setIndent(50);// 50px

    // 设置边距————四个方向都会同时设置
    ui->label_4->setText("这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本");
    ui->label_4->setWordWrap(true);
    ui->label_4->setMargin(50);// 50px
}

Widget::~Widget()
{
    delete ui;
}
