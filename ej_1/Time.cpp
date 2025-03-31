#include <iostream>
#include "Time.hpp"

using namespace std;

Time::Time() {
    this->hh = 0;
    this->mm = 0;
    this->ss = 0;
    this->isDay = 0;
}
Time::Time(int hh) {
    this->hh = hh;
    this->mm = 0;
    this->ss = 0;
    this->isDay = 0;
}
Time::Time(int hh, int mm) {
    this->hh = hh;
    this->mm = mm;
    this->ss = 0;
    this->isDay = 0;
}
Time::Time(int hh, int mm, int ss) {
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
    this->isDay = 0;
}
Time::Time(int hh, int mm, int ss, bool isDay) {
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
    this->isDay = isDay;
}
void Time::setHour(int hh) {
    this->hh = hh;
}
void Time::setMinute(int mm) {
    this->mm = mm;
}
void Time::setSecond(int ss) {
    this->ss = ss;
}
void Time::setAmPm(bool isDay) {
    this->isDay = isDay;
}
void Time::getHour() {
    cout << "La hora es: " << setw(2) << setfill('0') << this->hh << "h\n";
}
void Time::getMinute() {
    cout << "Los minutos son: " << setw(2) << setfill('0') << this->mm << "h\n";
}
void Time::getSecond() {
    cout << "Los segundos son: " << setw(2) << setfill('0') << this->ss << "h\n";
}
void Time::getAmPm() {
    cout << (this->isDay ? "La hora es pm\n" : "La hora es am\n");
}
void Time::getTime() {
    cout << setw(2) << setfill('0') << this->hh * this->isDay << ":" << setw(2) << setfill('0') << this->mm << ":" << setw(2) << setfill('0') << this->ss << "\n";
}