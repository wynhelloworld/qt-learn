#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
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
    /* 一 */
    // QMessageBox *box = new QMessageBox();
    // // box->setWindowTitle("这是一个 Message Box");
    // box->setText("Hello World");
    // // box->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    // box->setStandardButtons(QMessageBox::Cancel);
    // // box->show();
    // box->exec();
    // // box->setAttribute(Qt::WA_DeleteOnClose);
    // delete box;


    /* 二 */
    // QMessageBox box;
    // box.setWindowTitle("这是一个 Message Box");
    // box.setText("Hello World");
    // // box.setStandardButtons(QMessageBox::Ok);
    // box.exec();

    /* 三 */
    int result =  QMessageBox::warning(this, "title", "text", QMessageBox::Cancel, QMessageBox::No);
    if (result == QMessageBox::Cancel) {
        qDebug() << "Cancel: " << result;
    } else if (result == QMessageBox::No) {
        qDebug() << "No: " << result;
    }
}

