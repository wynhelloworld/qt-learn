#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QNetworkDatagram>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("服务端");

    socket = new QUdpSocket(this);

    connect(socket, &QUdpSocket::readyRead, this, &Widget::processRequest);

    bool result = socket->bind(QHostAddress::Any, 9999);
    if (!result) {
        QMessageBox::critical(this, "UdpServer 启动失败", socket->errorString());
        exit(-1);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processRequest()
{
    // 1. 接受请求
    const QNetworkDatagram &requestDatagram = socket->receiveDatagram();
    QString request = requestDatagram.data();

    // 2. 处理请求 -> 得到响应
    const QString &response = process(request);

    // 3. 返回响应
    QNetworkDatagram responseDatagram(response.toUtf8(), requestDatagram.senderAddress(), requestDatagram.senderPort());
    socket->writeDatagram(responseDatagram);

    // 4. 处理 UI
    QString log = "[" + requestDatagram.senderAddress().toString() + ":"
                  + QString::number(requestDatagram.senderPort()) + "] "
                  + "request: " + request + "  "
                  + "response: " + response;
    ui->listWidget->addItem(log);
}


