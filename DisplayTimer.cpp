#include "DisplayTimer.h"
using namespace std;
DisplayTimer::DisplayTimer() : running(false) {}

void DisplayTimer::start() {                   //時間開始
    if (!running) {
        startTime = chrono::steady_clock::now();
        running = true;
    }
}

void DisplayTimer::stop() {                    //時間暫停
    if (running) {
        endTime = chrono::steady_clock::now();
        running = false;
    }
}

void DisplayTimer::reset() {                   //重置計時器
    startTime = chrono::steady_clock::now();
    endTime = startTime;
}

double DisplayTimer::elapsedSeconds() {       //取得經過的時間
    if (running) {
        auto current = chrono::steady_clock::now();
        chrono::duration<double> elapsed = current - startTime;
        return elapsed.count();
    }
    else {
        chrono::duration<double> elapsed = endTime - startTime;
        return elapsed.count();
    }
}
