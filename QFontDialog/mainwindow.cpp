#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>
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
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    if (ok) {
        ui->textEdit->setFont(font);
    } else {
        qDebug() << ok;
    }
}

