#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->display(10);

    connect(&thread, &Thread::notify, this, &MainWindow::handle);

    thread.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle()
{
    int value = ui->lcdNumber->value();
    ui->lcdNumber->display(value - 1);
}
