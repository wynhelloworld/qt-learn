#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

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
    QDialog *dialog = new QDialog();
    dialog->setWindowTitle("对话框");
    dialog->resize(400, 300);
    dialog->show();

    /* 当关闭 dialog 时，回收资源 */
    dialog->setAttribute(Qt::WA_DeleteOnClose);
}
