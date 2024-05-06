#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::moveEvent(QMoveEvent *event)
{
    qDebug() << "move: " << event->pos();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug() << "resize: " << event->size();
}
