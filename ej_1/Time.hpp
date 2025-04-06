#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

/*
Este ejercicio es bastante tranqui. Solo nos piden implementar una clase Time con algunos métodos.
*/

class Time {
    public:
        Time(); // Sobrecargamos el constructor para poder inicializar el objeto dada cualquier cantidad de parámetros.
        Time(int hh);
        Time(int hh, int mm);
        Time(int hh, int mm, int ss);
        Time(int hh, int mm, int ss, bool isDay);
        void setHour(int hh);
        void setMinute(int mm);
        void setSecond(int ss);
        void setAmPm(bool isDay);
        int getHour();
        int getMinute();
        int getSecond();
        bool getAmPm();
        string getTime();
        
    private:
        int hh; //Atributos privados para no ser modificados desde fuera de la clase.
        int mm;
        int ss;
        bool isDay;
};