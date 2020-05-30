#include "timer.h"
#include<QtCore>
#include<QDebug>
Timer::Timer()
{
    timer = new QTimer(this); // to delete all the childrens
}

void Timer::myslot()
{
}

