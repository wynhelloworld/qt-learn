#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_add_row_clicked();

    void on_pushButton_add_col_clicked();

    void on_pushButton_del_row_clicked();

    void on_pushButton_del_col_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
