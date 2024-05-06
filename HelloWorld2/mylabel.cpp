#include "mylabel.h"

#include <iostream>
#include <QDebug>

MyLabel::MyLabel(QWidget *parent)
    : QLabel(parent)
{}

MyLabel::~MyLabel()
{
    std::cout << "MyLabel::~MyLabel()" << std::endl;
    qDebug() << "MyLabel::~MyLabel()";
}
