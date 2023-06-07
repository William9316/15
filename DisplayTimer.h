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
    void start();   //時間開始
    void stop();    //時間暫停
    void reset();   //時間重置
    double elapsedSeconds(); //返回已用時間
};

#endif  
