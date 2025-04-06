#include <iostream>
#include <sstream>
#include "Time.hpp"

using namespace std;

Time::Time() { // Inicializa todo en 0
    this->hh = 0;
    this->mm = 0;
    this->ss = 0;
    this->isDay = 0;
}
Time::Time(int hh) { // Inicializa la hora y el resto en 0
    this->hh = hh;
    this->mm = 0;
    this->ss = 0;
    this->isDay = 0;
}
Time::Time(int hh, int mm) { // Inicializa hora y minutos y el resto en 0
    this->hh = hh;
    this->mm = mm;
    this->ss = 0;
    this->isDay = 0;
}
Time::Time(int hh, int mm, int ss) { // Inicializa hora, minutos y segundos pero no am/pm
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
    this->isDay = 0;
}
Time::Time(int hh, int mm, int ss, bool isDay) { // Inicializa con todos los parámetros
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
    this->isDay = isDay;
}
void Time::setHour(int hh) { //Seteamos hora
    this->hh = hh;
}
void Time::setMinute(int mm) { //Seteamos minutos
    this->mm = mm;
}
void Time::setSecond(int ss) { //Seteamos segundos
    this->ss = ss;
}
void Time::setAmPm(bool isDay) { //Seteamos si es am o pm
    this->isDay = isDay;
}
int Time::getHour() { // Devolvemos hora
    return hh;
}
int Time::getMinute() { //Devolvemos minutos
    return mm;    
}
int Time::getSecond() { // Devolvemos segundos
    return ss;
}
bool Time::getAmPm() { //Devolvemos si es de día o no
    return isDay;
}
string Time::getTime() { //Devolvemos la hora en formato de 24 horas
    int hora24 = hh;
    if (isDay && hh != 12) hora24 += 12; // Si la hora es pm distinta de 12 se le suma 12
    if (!isDay && hh == 12) hora24 = 0; // 12am = 00

    stringstream s; // Usamos un stringstream para devolver la hora
    s << setw(2) << setfill('0') << hora24 << ":" // Usamos 2 dígitos y rellenamos con ceros si es necesario para cada parámetro
      << setw(2) << setfill('0') << mm << ":"
      << setw(2) << setfill('0') << ss;
    return s.str(); //Devolvemos el string
}