#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDockWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    /* 创建 DockWidget，并添加到 window 中 */
    QDockWidget *dockWidget = new QDockWidget("这是一个 Dock");
    this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);


    /* 创建 QWidget，添加到 DockWidget 中 */
    QWidget * qWidget = new QWidget();
    dockWidget->setWidget(qWidget);


    /* 创建 Layout，添加到 qWidget 中*/
    QVBoxLayout *vBoxLayout = new QVBoxLayout();
    qWidget->setLayout(vBoxLayout);


    /* 创建其它控件，添加到 vBoxLayout 中 */
    QLabel *label = new QLabel("这是一个 Label");
    QPushButton *pushButton = new QPushButton("这是一个 PushButton");
    vBoxLayout->addWidget(label);
    vBoxLayout->addWidget(pushButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}
