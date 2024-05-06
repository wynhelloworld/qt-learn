#include "widget.h"
#include "ui_widget.h"

#include <thread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lcdNumber->display(10);
    int value = ui->lcdNumber->value();
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (value <= 0) {
            break;
        }
        ui->lcdNumber->display(--value);
    }

    /*
     * 注意：
     * 一、无法通过 for 循环 + 休眠/s 的方式进行倒计时，因为这是在 Widget 的构造函数里面
     * 二、无法通过开辟线程，在另外一个线程里通过 for 循环 + 休眠/s 的方式进行倒计时，因为 Qt 为了界面的线程安全，
     * 使得所有对界面进行的操作都必须在主线程中进行，而 ui->lcdNumber->display(--value) 修改了界面，所以 No！
    */
}

Widget::~Widget()
{
    delete ui;
}
