#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFileInfo>
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
    QString path = QFileDialog::getOpenFileName(this);
    QFileInfo info(path);

    qDebug() << info.fileName() << "\n"
             << info.suffix()   << "\n"
             << info.path()     << "\n"
             << info.size()     << "\n"
             << info.isFile()   << "\n"
             << info.isDir();
}
