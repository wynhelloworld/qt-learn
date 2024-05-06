#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setPlaceholderText("请输入要插入的元素名字");
    ui->pushButton_insert_top->setText("添加到顶层元素");
    ui->pushButton_insert_coom->setText("添加到选中元素");
    ui->pushButton_delete->setText("删除选中元素");

    ui->treeWidget->setHeaderLabel("动物");

    QTreeWidgetItem *item1 = new QTreeWidgetItem();
    item1->setText(0, "猫");
    ui->treeWidget->addTopLevelItem(item1);

    QTreeWidgetItem *item2 = new QTreeWidgetItem();
    item2->setText(0, "狗");
    ui->treeWidget->addTopLevelItem(item2);

    QTreeWidgetItem *item3 = new QTreeWidgetItem();
    item3->setText(0, "鸟");
    ui->treeWidget->addTopLevelItem(item3);

    QTreeWidgetItem *item4 = new QTreeWidgetItem();
    item4->setText(0, "橘猫");
    item1->addChild(item4);

    QTreeWidgetItem *item5 = new QTreeWidgetItem();
    item5->setText(0, "暹罗猫");
    item1->addChild(item5);

    QTreeWidgetItem *item6 = new QTreeWidgetItem();
    item6->setText(0, "加菲猫");
    item1->addChild(item6);

    QTreeWidgetItem *item7 = new QTreeWidgetItem();
    item7->setText(0, "黑背");
    item2->addChild(item7);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_insert_top_clicked()
{
    const QString &text = ui->lineEdit->text();
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, text);
    ui->treeWidget->addTopLevelItem(item);
}

void Widget::on_pushButton_insert_coom_clicked()
{
    QTreeWidgetItem *currentItem = ui->treeWidget->currentItem();
    if (currentItem == nullptr) {
        return;
    }
    const QString &text = ui->lineEdit->text();
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, text);
    currentItem->addChild(item);
}

void Widget::on_pushButton_delete_clicked()
{
    QTreeWidgetItem *currentItem = ui->treeWidget->currentItem();
    if (currentItem == nullptr) {
        return;
    }
    QTreeWidgetItem *parentItem = currentItem->parent();
    if (parentItem == nullptr) {
        int idx = ui->treeWidget->indexOfTopLevelItem(currentItem);
        ui->treeWidget->takeTopLevelItem(idx);
    } else {
        parentItem->removeChild(currentItem);
    }
}

