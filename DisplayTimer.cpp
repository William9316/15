#include "DisplayTimer.h"
using namespace std;
DisplayTimer::DisplayTimer() : running(false) {}

void DisplayTimer::start() {                   //�ɶ��}�l
    if (!running) {
        startTime = chrono::steady_clock::now();
        running = true;
    }
}

void DisplayTimer::stop() {                    //�ɶ��Ȱ�
    if (running) {
        endTime = chrono::steady_clock::now();
        running = false;
    }
}

void DisplayTimer::reset() {                   //���m�p�ɾ�
    startTime = chrono::steady_clock::now();
    endTime = startTime;
}

double DisplayTimer::elapsedSeconds() {       //���o�g�L���ɶ�
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
