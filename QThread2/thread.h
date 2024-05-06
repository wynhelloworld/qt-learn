#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QMutex>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = nullptr);

    void run() override;

public:
    static int value;
    static QMutex mutex;
};


#endif // THREAD_H
