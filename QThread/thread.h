#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QWidget>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();

    void run() override;

signals:
    void notify();
};

#endif // THREAD_H
