#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
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

void MainWindow::on_pushButton_clicked()
{
    QString name = QFileDialog::getOpenFileName(this);
    qDebug() << name;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString name = QFileDialog::getSaveFileName(this);
    qDebug() << name;
}

