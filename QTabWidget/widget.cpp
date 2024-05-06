#include "widget.h"
#include "ui_widget.h"

#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel *label1 = new QLabel(ui->tab);
    label1->setText("标签页 1");
    label1->move(335, 240);

    QLabel *label2 = new QLabel(ui->tab_2);
    label2->setText("标签页 2");
    label2->move(335, 240);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    int count = ui->tabWidget->count();
    QWidget *widget = new QWidget();
    ui->tabWidget->addTab(widget, QString("Tab ") + QString::number(count + 1));

    QLabel *label = new QLabel(widget);
    label->setText(QString("标签页 ") + QString::number(count + 1));
    label->move(335, 240);

    ui->tabWidget->setCurrentIndex(count);
}

void Widget::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}
