#include <iostream>
#include <iomanip>
#include "Numero.hpp"

Entero::Entero(int n) {
    this->n = n;
}

void Entero::suma(Numero* x) {
    Entero* sumando = dynamic_cast<Entero*>(x); //Suma normal de enteros
    if (sumando) this->n = this->n + sumando->n;
    return;
}
void Entero::resta(Numero* x) {
    Entero* sustraendo = dynamic_cast<Entero*>(x); //Resta normal de enteros
    if (sustraendo) this->n = this->n - sustraendo->n;
    return;
}
void Entero::multiplicacion(Numero* x) {
    Entero* factor = dynamic_cast<Entero*>(x); //Multiplicación normal de enteros
    if (factor) this->n = this->n * factor->n;
    return;
}
void Entero::division(Numero* x) {
    Entero* divisor = dynamic_cast<Entero*>(x);
    if (divisor && divisor->n) this->n = this->n / divisor->n; //Si el divisor es distinto de 0 dividimos
    else if (!divisor->n) cout << "No se puede dividir por 0. El número mantiene su valor\n";
    return;
}
string Entero::toString() {
    return to_string(this->n);
}

Real::Real(float r) {
     this->r = r;
}

void Real::suma(Numero* x) {
    Real* sumando = dynamic_cast<Real*>(x);
    if (sumando) this->r = this->r + sumando->r;
    return;
}
void Real::resta(Numero* x) {
    Real* sustraendo = dynamic_cast<Real*>(x);
    if (sustraendo) this->r = this->r - sustraendo->r;
    return;
}
void Real::multiplicacion(Numero* x) {
    Real* factor = dynamic_cast<Real*>(x);
    if (factor) this->r = this->r * factor->r;
    return;
}
void Real::division(Numero* x) {
    Real* divisor = dynamic_cast<Real*>(x);
    if (divisor && divisor->r) this->r = this->r / divisor->r;
    else if(!divisor->r) cout << "No se puede dividir por 0. El número mantiene su valor\n";
    return;
}
string Real::toString() {
    stringstream s;
    s << fixed << setprecision(2) << r; //Restringimos a 2 decimales para imprimir
    return s.str();
}

Complejo::Complejo(float re, float im) {
    this->re = re;
    this->im = im;
}

void Complejo::suma(Numero* x) {
    Complejo* sumando = dynamic_cast<Complejo*>(x); //Las operaciones son como en complejos
    if (sumando) { 
        this->re = this->re + sumando->re;
        this->im = this->im + sumando->im; 
    }
    return;
}
void Complejo::resta(Numero* x) {
    Complejo* sustraendo = dynamic_cast<Complejo*>(x);
    if (sustraendo) {
        this->re = this->re - sustraendo->re;
        this->im = this->im - sustraendo->im;
    }
    return;
}
void Complejo::multiplicacion(Numero* x) {
    Complejo* factor = dynamic_cast<Complejo*>(x);
    if (factor) {
        float nuevo_re = this->re * factor->re - this->im * factor->im; // si tenemos (a+bi)*(c+di) expandiendo nos queda (ac + (ad + bc)i + bd i^2)
        float nuevo_im = this->re * factor->im + this->im * factor->re; // que es lo mismo que (ac-bd + (ad+bc)i)

        this->re = nuevo_re;
        this->im = nuevo_im;
    }
    return;
}
void Complejo::division(Numero* x) {
    Complejo* divisor = dynamic_cast<Complejo*>(x);
    if (divisor && (divisor->re || divisor->im)) {
        float nuevo_re = (this->re * divisor->re + this->im * divisor->im) / (divisor->re * divisor->re + divisor->im * divisor->im); //si tenemos (a+bi)*(c+di) multiplicamos y dividimos por el conjugado
        float nuevo_im = (this->im * divisor->re - this->re * divisor->im) / (divisor->re * divisor->re + divisor->im * divisor->im); //y nos queda (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)i

        this->re = nuevo_re;
        this->im = nuevo_im;
    }
    return;
}
string Complejo::toString() {
    stringstream s;
    s << fixed << setprecision(2) << re; //Restringimos a 2 decimales para imprimir
    if (im >= 0) s << "+";
    s << fixed << setprecision(2) << im << "i";
    return s.str();
}