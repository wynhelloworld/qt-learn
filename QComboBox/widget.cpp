#include "widget.h"
#include "ui_widget.h"

#include <fstream>
#include <QDebug>
#include <QComboBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // ui->comboBox->addItem("麦辣鸡腿堡");
    // ui->comboBox->addItem("巨无霸");
    // ui->comboBox->addItem("培根蔬萃双层牛堡");

    // ui->comboBox_2->addItem("中薯条");
    // ui->comboBox_2->addItem("麦乐鸡块");
    // ui->comboBox_2->addItem("麦辣鸡翅");

    // ui->comboBox_3->addItem("可乐");
    // ui->comboBox_3->addItem("雪碧");

    loadResource(ui->comboBox, "/Users/wyn/Dev/QtProjects/QComboBox/hamburgers.txt");
    loadResource(ui->comboBox_2, "/Users/wyn/Dev/QtProjects/QComboBox/snacks.txt");
    loadResource(ui->comboBox_3, "/Users/wyn/Dev/QtProjects/QComboBox/drinks.txt");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::loadResource(QComboBox *comboBox, const QString &path)
{
    std::fstream file(path.toStdString());
    if (!file.is_open()) {
        qDebug() << "file open error!";
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        comboBox->addItem(QString::fromStdString(line));
    }
    file.close();
}
