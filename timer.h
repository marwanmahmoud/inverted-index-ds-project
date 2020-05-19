#ifndef TIMER_H
#define TIMER_H
#include<QtCore>

class Timer : public QObject // timer ihnerts form Qobject
{
    Q_OBJECT // important to use signal and slots


public:
    Timer();
    QTimer *timer;
public slots:
    void myslot();
};

#endif // TIMER_H
