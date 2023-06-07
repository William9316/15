#ifndef DISPLAYTIMER_H
#define DISPLAYTIMER_H
#include <chrono>
using namespace std;

class DisplayTimer {
private:
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;
    bool running;

public:
    DisplayTimer();
    void start();   //�ɶ��}�l
    void stop();    //�ɶ��Ȱ�
    void reset();   //�ɶ����m
    double elapsedSeconds(); //��^�w�ήɶ�
};

#endif  
