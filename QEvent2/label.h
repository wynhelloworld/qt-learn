#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QWidget>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // LABEL_H
