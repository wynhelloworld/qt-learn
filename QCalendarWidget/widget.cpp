#include "widget.h"
#include "ui_widget.h"

#include <QDate>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label->setFrameShape(QFrame::Box);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_calendarWidget_selectionChanged()
{
    QDate date = ui->calendarWidget->selectedDate();
    ui->label->setText(date.toString());
}
