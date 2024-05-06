#include "widget.h"
#include "ui_widget.h"

#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QCursor cursor(Qt::WaitCursor);
    // ui->pushButton->setCursor(cursor);

    QPixmap pixmap(":/3.svg");
    pixmap = pixmap.scaled(15, 15);
    QCursor cursor(pixmap);
    ui->pushButton->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}
