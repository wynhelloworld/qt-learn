#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton_target->setIcon(QIcon(":/images/baobao.JPG"));
    ui->pushButton_target->setIconSize(QSize(270, 270));

    ui->pushButton_up->setIcon(QIcon(":/images/upa.png"));
    ui->pushButton_up->setIconSize(QSize(75, 75));

    ui->pushButton_down->setIcon(QIcon(":/images/downa.png"));
    ui->pushButton_down->setIconSize(QSize(75, 75));

    ui->pushButton_left->setIcon(QIcon(":/images/lefta.png"));
    ui->pushButton_left->setIconSize(QSize(75, 75));

    ui->pushButton_right->setIcon(QIcon(":/images/righta.png"));
    ui->pushButton_right->setIconSize(QSize(75, 75));


    // 设置快捷键
    ui->pushButton_up->setShortcut(QKeySequence(Qt::Key_W));
    ui->pushButton_down->setShortcut(QKeySequence(Qt::Key_S));
    ui->pushButton_left->setShortcut(QKeySequence(Qt::Key_A));
    ui->pushButton_right->setShortcut(QKeySequence(Qt::Key_D));

    // 设置鼠标连击
    ui->pushButton_up->setAutoRepeat(true);
    ui->pushButton_down->setAutoRepeat(true);
    ui->pushButton_left->setAutoRepeat(true);
    ui->pushButton_right->setAutoRepeat(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_up_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x(), rect.y() - 5, rect.width(), rect.height());
}

void Widget::on_pushButton_down_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x(), rect.y() + 5, rect.width(), rect.height());
}

void Widget::on_pushButton_left_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x() - 5, rect.y(), rect.width(), rect.height());
}

void Widget::on_pushButton_right_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x() + 5, rect.y(), rect.width(), rect.height());
}
