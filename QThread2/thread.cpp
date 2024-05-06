#include "thread.h"
#include <QMutexLocker>

int Thread::value = 0;
QMutex Thread::mutex;

Thread::Thread(QObject *parent)
    : QThread{parent}
{}

void Thread::run()
{
    for (int i = 0; i < 50000; ++i) {
        // mutex.lock();
        // ++value;
        // mutex.unlock();

        QMutexLocker locker(&mutex);
        ++value;
    }
}
