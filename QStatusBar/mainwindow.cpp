#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStatusBar>
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStatusBar *statusBar = this->statusBar();
    this->setStatusBar(statusBar);

    // statusBar->showMessage("this is a status.");

    QPushButton *pushButton = new QPushButton("按钮");
    QLabel *label = new QLabel("标签");
    statusBar->addWidget(label);
    statusBar->addPermanentWidget(pushButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}
