#include "qprogressthread.h"

void QProgressThread::run()
{
        for (int i=0; i<=100; i++)
        {
            qDebug("Progress: %d%%", i);
            emit progress(i);
            while(pause){
                qDebug("Progress: %d%% \n Press Start to continue...",i);
            }
            msleep(300);
        }

}
