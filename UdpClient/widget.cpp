#include "widget.h"
#include "ui_widget.h"

const QString &SERVER_IP = "127.0.0.1";
const quint16 SERVER_PORT = 9999;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");

    socket = new QUdpSocket(this);

    connect(socket, &QUdpSocket::readyRead, this, &Widget::processResponse);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 获取文本
    const QString &text = ui->lineEdit->text();

    // 构造请求
    QNetworkDatagram requestDatagram(text.toUtf8(), QHostAddress(SERVER_IP), SERVER_PORT);
    socket->writeDatagram(requestDatagram);

    // 处理 UI
    ui->listWidget->addItem("「客户端 」" + text);
    ui->lineEdit->clear();
}

void Widget::processResponse()
{
    // 获取响应
    const QNetworkDatagram &responseDatagram = socket->receiveDatagram();
    QString response = responseDatagram.data();

    // 处理 UI
    ui->listWidget->addItem("「服务端」 " + response);
}
