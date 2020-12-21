#ifndef QPROGRESSTHREAD_H
#define QPROGRESSTHREAD_H
#define QT_THREAD_SUPPORT

#include <QThread>
#include "qwaitcondition.h"
#include "qmutex.h"
class QProgressThread : public QThread
{
    Q_OBJECT

private:
    QMutex sync;
    QWaitCondition pauseCond;
    bool pause;

public:
    QProgressThread():QThread(0){};
    void resume()
    {
        sync.lock();
        pause = false;
        sync.unlock();
        pauseCond.wakeAll();
    }

    void stop()
    {
        sync.lock();
        pause = true;
        sync.unlock();
    }

signals:
    void progress(int i);

protected:
    void run();
};

#endif // QPROGRESSTHREAD_H
