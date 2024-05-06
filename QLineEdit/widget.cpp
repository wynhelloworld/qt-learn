#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QRegularExpressionValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton_submit->setEnabled(false);

    ui->lineEdit_name->setPlaceholderText("请输入姓名");
    ui->lineEdit_name->setClearButtonEnabled(true);

    ui->lineEdit_password->setPlaceholderText("请输入密码");
    ui->lineEdit_password->setClearButtonEnabled(true);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    ui->lineEdit_password_2->setPlaceholderText("请再次输入密码");
    ui->lineEdit_password_2->setClearButtonEnabled(true);
    ui->lineEdit_password_2->setEchoMode(QLineEdit::Password);

    ui->lineEdit_phone->setPlaceholderText("请输入电话");
    ui->lineEdit_phone->setClearButtonEnabled(true);
    // ui->lineEdit_phone->setInputMask("000-0000-0000");
    QRegularExpression regexp("^1\\d{10}$");
    ui->lineEdit_phone->setValidator(new QRegularExpressionValidator(regexp));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_submit_clicked()
{
    QString gender = ui->radioButton_male->isChecked() ? "男" : "女";
    qDebug() << "姓名：" << ui->lineEdit_name->text()
             << "密码：" << ui->lineEdit_password->text()
             << "性别：" << gender
             << "电话：" << ui->lineEdit_phone->text();
}

void Widget::on_lineEdit_phone_textEdited(const QString &arg1)
{
    QString text = arg1;
    int pos = 0;
    if (ui->lineEdit_phone->validator()->validate(text, pos) == QValidator::Acceptable) {
        ui->pushButton_submit->setEnabled(true);
    } else {
        ui->pushButton_submit->setEnabled(false);
    }
}

void Widget::on_lineEdit_password_2_textEdited(const QString &arg1)
{
    (void) arg1;
    QString password1 = ui->lineEdit_password->text();
    QString password2 = ui->lineEdit_password_2->text();
    if (password2 == "") {
        ui->label_password_tip->setText("");
    } else if (password1 != password2) {
        ui->label_password_tip->setText("两次输入密码不一致");
    } else {
        ui->label_password_tip->setText("");
    }
}

void Widget::on_checkBox_toggled(bool checked)
{
    if (checked) {
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
    } else {
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    }
}

