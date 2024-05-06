#include "widget.h"
#include "ui_widget.h"
#include <QShortcut>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QShortcut *shortCutUp = new QShortcut(this);
    QShortcut *shortCutDown = new QShortcut(this);
    QShortcut *shortCutLeft = new QShortcut(this);
    QShortcut *shortCutRight = new QShortcut(this);
    shortCutUp->setKey(QKeySequence(Qt::Key_Up));
    shortCutDown->setKey(QKeySequence(Qt::Key_Down));
    shortCutLeft->setKey(QKeySequence(Qt::Key_Left));
    shortCutRight->setKey(QKeySequence(Qt::Key_Right));
    connect(shortCutUp, &QShortcut::activated, this, &Widget::handleUp);
    connect(shortCutDown, &QShortcut::activated, this, &Widget::handleDown);
    connect(shortCutLeft, &QShortcut::activated, this, &Widget::handleLeft);
    connect(shortCutRight, &QShortcut::activated, this, &Widget::handleRight);

    ui->horizontalSlider->setMinimum(160);
    ui->horizontalSlider->setMaximum(1200);
    ui->horizontalSlider->setValue(800);
    ui->horizontalSlider->setSingleStep(50);

    ui->verticalSlider->setMinimum(120);
    ui->verticalSlider->setMaximum(800);
    ui->verticalSlider->setValue(600);
    ui->verticalSlider->setSingleStep(50);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_horizontalSlider_valueChanged(int value)
{
    const QRect &rect = this->geometry();
    this->setGeometry(rect.x(), rect.y(), value, rect.height());
}

void Widget::on_verticalSlider_valueChanged(int value)
{
    const QRect &rect = this->geometry();
    this->setGeometry(rect.x(), rect.y(), rect.width(), value);
}

void Widget::handleUp()
{
    qDebug() << "handleUp";
    int value = ui->verticalSlider->value();
    ui->verticalSlider->setValue(value - 5);
}

void Widget::handleDown()
{
    qDebug() << "handleDown";
    int value = ui->verticalSlider->value();
    ui->verticalSlider->setValue(value + 5);
}

void Widget::handleLeft()
{
    qDebug() << "handleLeft";
    int value = ui->horizontalSlider->value();
    ui->horizontalSlider->setValue(value - 5);
    // const QRect &rect = this->geometry();
    // this->setGeometry(rect.x(), rect.y(), rect.width() - 5, rect.height());
}

void Widget::handleRight()
{
    qDebug() << "handleRight";
    int value = ui->horizontalSlider->value();
    ui->horizontalSlider->setValue(value + 5);
    // const QRect &rect = this->geometry();
    // this->setGeometry(rect.x(), rect.y(), rect.width() + 5, rect.height());
}
