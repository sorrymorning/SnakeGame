#include "timer.h"

Timer::Timer(int interval_ms) 
    : interval_ms_(interval_ms),
      start_time_(std::chrono::steady_clock::now()) {}

bool Timer::isExpired() {
    if (paused_) return false;
    auto elapsed = std::chrono::steady_clock::now() - start_time_;
    return elapsed > std::chrono::milliseconds(interval_ms_);
}

void Timer::reset() {
    start_time_ = std::chrono::steady_clock::now();
}

void Timer::update() {
    reset(); // Алиас для reset
}

void Timer::setInterval(int interval_ms) {
    interval_ms_ = interval_ms;
}

int Timer::getInterval() const {
    return interval_ms_;
}

int Timer::getElapsed() const {
    auto elapsed = std::chrono::steady_clock::now() - start_time_;
    return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
}

int Timer::getTimeLeft() const {
    int elapsed = getElapsed();
    return (elapsed < interval_ms_) ? (interval_ms_ - elapsed) : 0;
}

void Timer::pause() {
        if (!paused_) {
            pause_time_ = std::chrono::steady_clock::now();
            paused_ = true;
        }
    }
    
void Timer::resume() {
    if (paused_) {
        auto pause_duration = std::chrono::steady_clock::now() - pause_time_;
        start_time_ += pause_duration;
        paused_ = false;
    }
}