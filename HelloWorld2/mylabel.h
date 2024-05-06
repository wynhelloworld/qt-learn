#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
public:
    MyLabel(QWidget *parent = nullptr);
    ~MyLabel();
};

#endif // MYLABEL_H
