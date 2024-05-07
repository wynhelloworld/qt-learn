#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

const QString &SERVER_IP = "127.0.0.1";
const quint16 SERVER_PORT = 7777;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");

    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead, this, [=](){
        QString response = socket->readAll();
        QString log = "「服务端」 " + response;
        ui->listWidget->addItem(log);
    });

    socket->connectToHost(QHostAddress(SERVER_IP), SERVER_PORT);
    bool result = socket->waitForConnected();
    if (!result) {
        QMessageBox::critical(this, "TcpSocket 连接失败", socket->errorString());
        exit(-1);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    const QString &text = ui->textEdit->toPlainText();
    socket->write(text.toUtf8());
    QString log = "「客户端」 " + text;
    ui->listWidget->addItem(log);
    ui->textEdit->clear();
}

