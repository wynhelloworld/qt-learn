#include "label.h"
#include <QMouseEvent>
#include <QDebug>



Label::Label(QWidget *parent)
    : QLabel(parent)
{
    /**
     * @brief setMouseTracking
     * default: false
     *   false, 只有在 press 状态下才追踪
     *   true,  在任何状态下都追踪
     */
    setMouseTracking(true);
}

void Label::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "press: " << event->position();
}

void Label::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "release: " << event->position();
}

void Label::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "double click: " << event->position();
}

void Label::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "move: " << event->position();
}
