#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout *hBoxLayout = new QHBoxLayout(this);

    QPushButton *pushButton1 = new QPushButton("按钮 1");
    QPushButton *pushButton2 = new QPushButton("按钮 2");

    QSpacerItem *spacerItem = new QSpacerItem(200, 200);

    hBoxLayout->addWidget(pushButton1);
    hBoxLayout->addSpacerItem(spacerItem);
    hBoxLayout->addWidget(pushButton2);
}

Widget::~Widget()
{
    delete ui;
}
