#include "dialog.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>



Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("这是一个 Label", this);
    QPushButton *button = new QPushButton("关闭", this);
    layout->addWidget(label);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &Dialog::handleClose);
}

void Dialog::handleClose()
{
    this->close();
}
