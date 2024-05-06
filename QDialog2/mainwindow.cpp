#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

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
    Dialog *dialog = new Dialog();
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle("这是一个对话框");
    dialog->resize(400, 300);
    dialog->show();
}
