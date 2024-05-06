#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Java");
    ui->listWidget->addItem("Python");

    // ui->listWidget->addItem(new QListWidgetItem("C++"));
    // ui->listWidget->addItem(new QListWidgetItem("Java"));
    // ui->listWidget->addItem(new QListWidgetItem("Python"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    const QString &item = ui->lineEdit->text();
    ui->listWidget->addItem(item);
}


void Widget::on_pushButton_2_clicked()
{
    int row = ui->listWidget->currentRow();
    if (row < 0) {
        return;
    }
    ui->listWidget->takeItem(row);
}

void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (current != nullptr) {
        qDebug() << current->text();
    }

    if (previous != nullptr) {
        qDebug() << previous->text();
    }
}
