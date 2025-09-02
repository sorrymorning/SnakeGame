#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer(int interval_ms = 1000);
    
    // Основные методы
    bool isExpired();
    void reset();
    void update();
    
    // Управление интервалом
    void setInterval(int interval_ms);
    int getInterval() const;
    int getElapsed() const;
    int getTimeLeft() const;


    void pause();
    void resume();
    
private:
    std::chrono::steady_clock::time_point start_time_;
    int interval_ms_;
    bool paused_ = false;
    std::chrono::steady_clock::time_point pause_time_;
};

#endif // TIMER_H