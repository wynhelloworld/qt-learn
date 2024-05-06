#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "thread.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Thread t1;
    Thread t2;

    t1.start();
    t2.start();

    t1.wait();
    t2.wait();

    qDebug() << Thread::value;

}

MainWindow::~MainWindow()
{
    delete ui;
}
