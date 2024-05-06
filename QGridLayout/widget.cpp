#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton *pushButton1 = new QPushButton("按钮 1");
    QPushButton *pushButton2 = new QPushButton("按钮 2");
    QPushButton *pushButton3 = new QPushButton("按钮 3");
    QPushButton *pushButton4 = new QPushButton("按钮 4");
    QPushButton *pushButton5 = new QPushButton("按钮 5");
    QPushButton *pushButton6 = new QPushButton("按钮 6");

    pushButton1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pushButton6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(pushButton1, 0, 0);
    layout->addWidget(pushButton2, 0, 1);
    layout->addWidget(pushButton3, 0, 2);
    layout->addWidget(pushButton4, 1, 0);
    layout->addWidget(pushButton5, 1, 1);
    layout->addWidget(pushButton6, 1, 2);

    this->setLayout(layout);

    // layout->setColumnStretch(0, 1);
    // layout->setColumnStretch(1, 2);
    // layout->setColumnStretch(2, 3);

    layout->setRowStretch(0, 1);
    layout->setRowStretch(1, 2);
}

Widget::~Widget()
{
    delete ui;
}
