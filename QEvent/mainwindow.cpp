#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pushbutton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // PushButton *btn_reject = new PushButton(this);
    // btn_reject->move(200, 150);
    // btn_reject->resize(300, 200);
    // btn_reject->setText("拒绝");

    ui->btn_reject->setParentWidth(geometry().width());
    ui->btn_reject->setParentHeight(geometry().height());
}

MainWindow::~MainWindow()
{
    delete ui;
}
