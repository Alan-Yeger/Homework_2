#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Time {
    public:
        Time();
        Time(int hh);
        Time(int hh, int mm);
        Time(int hh, int mm, int ss);
        Time(int hh, int mm, int ss, bool isDay);
        void setHour(int hh);
        void setMinute(int mm);
        void setSecond(int ss);
        void setAmPm(bool isDay);
        void getHour();
        void getMinute();
        void getSecond();
        void getAmPm();
        void getTime();
        
        private:
        int hh;
        int mm;
        int ss;
        bool isDay;
};