#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString style = "* { color : blue; }";
    style += "QComboBox::down-arrow { image : url(:/baobao.png); }";
    style += "QPushButton:hover { color : #ff00aa; background: yellow; }";
    style += "QPushButton:pressed { color : red }";
    a.setStyleSheet(style);

    Widget w;
    w.show();
    return a.exec();
}
