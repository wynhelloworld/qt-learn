#include "pushbutton.h"
#include <QDebug>
#include <cstdlib>

PushButton::PushButton(QWidget *parent)
    : QPushButton(parent)
{
    srand(time(nullptr));
}

void PushButton::setParentWidth(int width)
{
    parent_width = width;
}

void PushButton::setParentHeight(int height)
{
    parent_height = height;
}

void PushButton::enterEvent(QEnterEvent *event)
{
    (void) event;
    QRect rect = geometry();
    int x = rand() % (parent_width - rect.width());
    int y = rand() % (parent_height - rect.height());
    setGeometry(x, y, rect.width(), rect.height());
    // qDebug() << parent_width << parent_height << x << y;
}
