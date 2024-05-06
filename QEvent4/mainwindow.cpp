#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimerEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->timerId = this->startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() != this->timerId) {
        return;
    }
    int val = ui->lcdNumber->value();
    if (val <= 0) {
        this->killTimer(this->timerId);
        return;
    }
    ui->lcdNumber->display(val - 1);
}
