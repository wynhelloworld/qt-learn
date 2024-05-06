#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    pushButton = new QPushButton(this);
    pushButton->setText("hello world");
    pushButton->move(350, 250);
    pushButton->setEnabled(false);

    connect(pushButton, &QPushButton::clicked, this, &Widget::handleClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClicked()
{
    if (this->windowTitle() == QString("hello chenli")) {
        this->setWindowTitle("hello wangyanan");
    } else {
        this->setWindowTitle("hello chenli");
    }
}


    // if (pushButton->isEnabled() == false) {
    //     pushButton->setEnabled(true);
    // } else {
    //     pushButton->setEnabled(false);
    // }
