#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    QStringList items;
    items.push_back("111");
    items.push_back("222");
    items.push_back("333");
    items.push_back("444");
    QString val = QInputDialog::getItem(this, "条目对话框", "请输入条目", items);
    qDebug() << val;
}


void MainWindow::on_pushButton_2_clicked()
{
    double val = QInputDialog::getDouble(this, "浮点数对话框", "请输入浮点数：");
    qDebug() << val;
}


void MainWindow::on_pushButton_clicked()
{
    int val = QInputDialog::getInt(this, "整数对话框", "请输入整数：");
    qDebug() << val;
}

