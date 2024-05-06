#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QFont>
#include <QFile>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , edit(nullptr)
{
    ui->setupUi(this);

    QMenuBar *menuBar = this->menuBar();
    this->setMenuBar(menuBar);

    QMenu *menuFile = new QMenu("File");
    menuBar->addMenu(menuFile);

    QAction *actionOpen = new QAction("Open");
    QAction *actionSave = new QAction("Save");
    menuFile->addAction(actionOpen);
    menuFile->addAction(actionSave);

    edit = new QPlainTextEdit();
    QFont font;
    font.setPixelSize(20);
    edit->setFont(font);
    this->setCentralWidget(edit);

    connect(actionOpen, &QAction::triggered, this, &MainWindow::handleOpenFile);
    connect(actionSave, &QAction::triggered, this, &MainWindow::handleSaveFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleOpenFile()
{
    QString path = QFileDialog::getOpenFileName();

    QStatusBar *statusBar = this->statusBar();
    statusBar->showMessage(path);

    QFile file(path);
    bool result = file.open(QFile::ReadOnly);
    if (!result) {
        statusBar->showMessage(path + " 打开失败!");
        return;
    }
    QString text = file.readAll();
    file.close();
    this->edit->setPlainText(text);
    statusBar->showMessage(path + " 打开成功!");
}

void MainWindow::handleSaveFile()
{
    QString path = QFileDialog::getSaveFileName();

    QStatusBar *statusBar = this->statusBar();
    statusBar->showMessage(path);

    QFile file(path);
    bool result = file.open(QFile::WriteOnly);
    if (!result) {
        statusBar->showMessage(path + " 保存失败!");
        return;
    }
    const QString &text = this->edit->toPlainText();
    file.write(text.toUtf8());
    file.close();
    statusBar->showMessage(path + " 保存成功!");
}
