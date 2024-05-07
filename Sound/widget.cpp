#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QUrl>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    soundEffect = new QSoundEffect(this);
    soundEffect->setSource(QUrl::fromLocalFile(":/a.wav"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked() {
    soundEffect->play();
}

