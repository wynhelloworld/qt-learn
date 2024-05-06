#include "widget.h"
#include "ui_widget.h"

#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel *label = new QLabel(this);
    label->setText("hello world");
    label->move(300, 200);

    QFont font;
    font.setFamily("PT Mono");
    font.setPixelSize(30);
    font.setBold(true);
    font.setItalic(true);
    font.setUnderline(true);
    font.setStrikeOut(true);

    label->setFont(font);
}

Widget::~Widget()
{
    delete ui;
}
