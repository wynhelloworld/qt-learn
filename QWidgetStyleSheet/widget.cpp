#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this, &Widget::toggleReadingMode, this, &Widget::handleReadingMode);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if (ui->pushButton->text() == QString("夜间模式")) {
        qDebug() << ui->pushButton->text();
        ui->pushButton->setText("日间模式");
        emit toggleReadingMode("夜间模式");
    } else {
        qDebug() << ui->pushButton->text();
        ui->pushButton->setText("夜间模式");
        emit toggleReadingMode("日间模式");
    }
}

void Widget::handleReadingMode(const QString &text)
{
    qDebug() << text;
    if (text == QString("夜间模式")) {
        this->setStyleSheet("background-color: black;");
        ui->plainTextEdit->setStyleSheet("background-color: black; color: white;");
        ui->pushButton->setStyleSheet("color: white");
    } else {
        this->setStyleSheet("background-color: rgb(240, 240, 240);");
        ui->plainTextEdit->setStyleSheet("background-color: rgb(240, 240, 240); color: black;");
        ui->pushButton->setStyleSheet("color: black");
    }
}
