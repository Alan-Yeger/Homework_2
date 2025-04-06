#include <iostream>
#include "Numero.hpp"

Entero::Entero(int n) {
    this->n = n;
}

void Entero::suma(Numero* x) {
    Entero* sumando = dynamic_cast<Entero*>(x);
    if (sumando) this->n = this->n + sumando->n;
    return;
}
void Entero::resta(Numero* x) {
    Entero* sustraendo = dynamic_cast<Entero*>(x);
    if (sustraendo) this->n = this->n - sustraendo->n;
    return;
}
void Entero::multiplicacion(Numero* x) {
    Entero* factor = dynamic_cast<Entero*>(x);
    if (factor) this->n = this->n * factor->n;
    return;
}
void Entero::division(Numero* x) {
    Entero* divisor = dynamic_cast<Entero*>(x);
    if (divisor && divisor->n) this->n = this->n / divisor->n;
    return;
}
string Entero::toString(Numero* x) {
    Entero* num = dynamic_cast<Entero*>(x);
    return to_string(num->n);
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
    return;
}
string Real::toString(Numero* x) {
    Real* num = dynamic_cast<Real*>(x);
    return to_string(num->r);
}

Complejo::Complejo(float re, float im) {
    this->re = re;
    this->im = im;
}

void Complejo::suma(Numero* x) {
    Complejo* sumando = dynamic_cast<Complejo*>(x);
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
        this->re = this->re * factor->re - this->im * factor->im;
        this->im = this->re * factor->im + this->im * factor->re;
    }
    return;
}
void Complejo::division(Numero* x) {
    Complejo* divisor = dynamic_cast<Complejo*>(x);
    if (divisor && divisor->re) {
        this->re = (this->re * divisor->re + this->im * divisor->im) / (divisor->re * divisor->re + divisor->im * divisor->im);
        this->im = (this->im * divisor->re - this->re * divisor->im) / (divisor->re * divisor->re + divisor->im * divisor->im);
    }
    return;
}
string Complejo::toString(Numero* x) {
    Complejo* num = dynamic_cast<Complejo*>(x);
    return (to_string(num->re) + "+" + to_string(num->im) + "i");
}