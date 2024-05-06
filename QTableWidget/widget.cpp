#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit_col_name->setPlaceholderText("请输入新增列名");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_add_row_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
}


void Widget::on_pushButton_add_col_clicked()
{
    int colCount = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(colCount);
    const QString &name = ui->lineEdit_col_name->text();
    ui->tableWidget->setHorizontalHeaderItem(colCount, new QTableWidgetItem(name));
}

void Widget::on_pushButton_del_row_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(currentRow);
}


void Widget::on_pushButton_del_col_clicked()
{
    int currentCol = ui->tableWidget->currentColumn();
    ui->tableWidget->removeColumn(currentCol);
}

