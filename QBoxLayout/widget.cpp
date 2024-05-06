#include "widget.h"
#include "ui_widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *vlayout = new QVBoxLayout(this);
    QPushButton *pushButton1 = new QPushButton("按钮 1");
    QPushButton *pushButton2 = new QPushButton("按钮 2");
    vlayout->addWidget(pushButton1);
    vlayout->addWidget(pushButton2);


    QHBoxLayout *hlayout = new QHBoxLayout();
    QPushButton *pushButton3 = new QPushButton("按钮 3");
    QPushButton *pushButton4 = new QPushButton("按钮 4");
    hlayout->addWidget(pushButton3);
    hlayout->addWidget(pushButton4);

    vlayout->addLayout(hlayout);
}

Widget::~Widget()
{
    delete ui;
}
