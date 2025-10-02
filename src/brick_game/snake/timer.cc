#include "timer.h"

Timer::Timer(int interval_ms) 
    : base_interval_ms_(interval_ms), interval_ms_(interval_ms),
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
    reset(); 
}

void Timer::setInterval(int interval_ms) {
        if (interval_ms != interval_ms_) {
            past_interval_ms_ = interval_ms_; // Сохраняем текущий интервал
            interval_ms_ = interval_ms;
            reset();
        }
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

bool Timer::getSpeedUp() const {
    return speedUp_;
}


int Timer::getBaseInterval() const {
    return base_interval_ms_;
}

void Timer::toggleSpeedUp() {
    speedUp_ = !speedUp_;
    if (speedUp_) {
        // Speed up - make the interval twice as fast
        interval_ms_ = base_interval_ms_ / 2;
    } else {
        // Return to normal speed
        interval_ms_ = base_interval_ms_;
    }
}

void Timer::returnInterval() {
    interval_ms_ = base_interval_ms_;
    speedUp_ = false;
}


void Timer::setBaseInterval(int interval_ms) {
    base_interval_ms_ = interval_ms;
    // If not in speed up mode, update current interval
    if (!speedUp_) {
        interval_ms_ = base_interval_ms_;
    } else {
        // If in speed up mode, maintain the speed up ratio
        interval_ms_ = base_interval_ms_ / 2;
    }
}