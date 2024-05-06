#ifndef PUSH_BUTTON_H
#define PUSH_BUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QEvent>

class PushButton : public QPushButton
{
    Q_OBJECT

public:
    PushButton(QWidget *parent = nullptr);

    void setParentWidth(int width);
    void setParentHeight(int height);

    void enterEvent(QEnterEvent *event);

private:
    int parent_width;
    int parent_height;
};

#endif // PUSH_BUTTON_H
