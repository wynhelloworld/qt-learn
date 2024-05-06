#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QColor>

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
    // QColorDialog *log = new QColorDialog();
    // log->exec();
    // delete log;

    QColor color = QColorDialog::getColor();
    char style[1024] = { 0 };
    sprintf(style, "background-color: rgb(%d, %d, %d);", color.red(), color.green(), color.black());
    this->setStyleSheet(style);
}

