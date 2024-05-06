#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenuBar>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // this->setWindowIcon(QIcon(":/baobao.icns")); // 行不通


    /* 创建菜单栏 */
    // QMenuBar *menubar = new QMenuBar(); // 如果创建工程的时候 ui 文件自动生成了，那么此时新建 menubar 的时候会把原有的 menubar 给挤掉，导致内存泄漏
    QMenuBar *menubar = this->menuBar(); // 若 ui 文件自动生成了，获取原有的 menubar；若 ui 文件没有自动生成，则自动创建一个 menubar，并获取该 menubar
    this->setMenuBar(menubar);

    /* 创建菜单并将菜单添加到菜单栏中 */
    QMenu *menuFile = new QMenu("File");
    QMenu *menuEdit = new QMenu("Edit");
    QMenu *menuView = new QMenu("View");
    QMenu *menuTools = new QMenu("Tools");
    menubar->addMenu(menuFile);
    menubar->addMenu(menuEdit);
    menubar->addMenu(menuView);
    menubar->addMenu(menuTools);


    /* 创建菜单项并将菜单项添加到菜单 menuFile 中*/
    QAction *actionNewProject = new QAction("New Project...");
    QAction *actionNewFile = new QAction("New File...");
    QAction *actionOpenFileOrProject = new QAction("Open File or Project...");
    QAction *actionClose = new QAction("Close");
    menuFile->addAction(actionNewProject);
    menuFile->addAction(actionNewFile);
    menuFile->addAction(actionOpenFileOrProject);
    /* 添加分割线 */
    menuFile->addSeparator();
    menuFile->addAction(actionClose);
    /* 给菜单项 actionNewProject 添加 Icon */
    actionNewProject->setIcon(QIcon(":/baobao.icns"));
    /* 给菜单项 actionClose 添加槽函数并且设置快捷键 */
    connect(actionClose, &QAction::triggered, this, &MainWindow::close);
    actionClose->setShortcut(QKeySequence(Qt::Key_Q));


    /* 创建菜单项并将菜单项添加到菜单 menuEdit 中*/
    QAction *actionUndo = new QAction("Undo");
    QAction *actionRedo = new QAction("Redo");
    menuEdit->addAction(actionUndo);
    menuEdit->addAction(actionRedo);


    /* 创建菜单项并将菜单项添加到菜单 menuView 中*/
    QAction *actionShowLeftSidebar = new QAction("Show Left Sidebar");
    menuView->addAction(actionShowLeftSidebar);


    /* 创建菜单项并将菜单项添加到菜单 menuGit 中*/
    QMenu *menuGit = new QMenu("Git");
    menuTools->addMenu(menuGit);
    QAction *actionCurrentFile = new QAction("Current File");
    QAction *actionCurrentProject = new QAction("Current Project");
    menuGit->addAction(actionCurrentFile);
    menuGit->addAction(actionCurrentProject);

}

MainWindow::~MainWindow()
{
    delete ui;
}
