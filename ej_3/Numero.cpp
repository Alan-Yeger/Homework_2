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

// Real::Real(float r) {
//     this->r = r;
// }



// Complejo::Complejo(float re, float im) {
//     this->re = re;
//     this->im = im;
// }