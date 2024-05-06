#include "widget.h"
#include "ui_widget.h"

#include <QFormLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFormLayout *formLayout = new QFormLayout(this);
    // this->setLayout(formLayout);

    QLabel *label1 = new QLabel("姓名");
    QLabel *label2 = new QLabel("年龄");
    QLabel *label3 = new QLabel("电话");

    QLineEdit *lineEdit1 = new QLineEdit();
    QLineEdit *lineEdit2 = new QLineEdit();
    QLineEdit *lineEdit3 = new QLineEdit();

    QPushButton *pushButton = new QPushButton("提交");

    formLayout->addRow(label1, lineEdit1);
    formLayout->addRow(label2, lineEdit2);
    formLayout->addRow(label3, lineEdit3);
    formLayout->addRow(nullptr, pushButton);

}

Widget::~Widget()
{
    delete ui;
}
