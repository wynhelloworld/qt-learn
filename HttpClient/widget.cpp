#include "widget.h"
#include "ui_widget.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");
    ui->lineEdit->setPlaceholderText("Please enter a URL");

    manager = new QNetworkAccessManager(this);
}

Widget::~Widget()
{
    delete ui;
}



