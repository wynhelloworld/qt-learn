#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QTcpSocket>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("服务端");

    tcpServer = new QTcpServer(this);

    connect(tcpServer, &QTcpServer::newConnection, this, &Widget::processNewConnection);

    bool result = tcpServer->listen(QHostAddress::Any, 7777);
    if (!result) {
        QMessageBox::critical(this, "TcpServer 启动失败", tcpServer->errorString());
        exit(-1);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processNewConnection()
{
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    QString log = "[" + clientSocket->peerAddress().toString() + " : " + QString::number(clientSocket->peerPort()) + "] " + "客户端上线啦！";
    ui->listWidget->addItem(log);

    connect(clientSocket, &QTcpSocket::readyRead, this, [=](){
        QString request = clientSocket->readAll();
        const QString &response = process(request);
        clientSocket->write(response.toUtf8());
        QString log = "[" + clientSocket->peerAddress().toString() + " : " + QString::number(clientSocket->peerPort()) + "] "
                      + "request: " + request + "  "
                      + "response: " + response;
        ui->listWidget->addItem(log);
    });

    connect(clientSocket, &QTcpSocket::disconnected, this, [=](){
        clientSocket->deleteLater();
        QString log = "[" + clientSocket->peerAddress().toString() + " : " + QString::number(clientSocket->peerPort()) + "] " + "客户端下线啦！";
        ui->listWidget->addItem(log);
    });
}

QString Widget::process(const QString &request)
{
    return request;
}
