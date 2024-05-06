#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolBar>
#include <QAction>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    /* 创建工具栏 */
    QToolBar *toolBar = new QToolBar(this);

    /* 设置工具栏的初始停靠位置，默认 top */
    this->addToolBar(Qt::LeftToolBarArea, toolBar);

    /* 设置工具栏的允许停靠位置，默认 all */
    toolBar->setAllowedAreas(Qt::AllToolBarAreas);

    /* 设置工具栏的悬浮属性，默认 true */
    toolBar->setFloatable(true);

    /* 设置工具栏的移动属性，默认 true */
    toolBar->setMovable(true);

    /* 创建工具 */
    QAction *actionSave = new QAction("Save");
    QAction *actionExit = new QAction("Exit");
    toolBar->addAction(actionSave);
    toolBar->addAction(actionExit);
    connect(actionSave, &QAction::triggered, this, &MainWindow::handleSave);
    connect(actionExit, &QAction::triggered, this, &MainWindow::handleExit);
    actionSave->setIcon(QIcon(":/save.png"));
    actionExit->setIcon(QIcon(":/exit.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleSave()
{
    qDebug() << "handleSave";
}

void MainWindow::handleExit()
{
    qDebug() << "handleExit";
}
