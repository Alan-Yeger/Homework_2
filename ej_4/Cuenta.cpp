#include <iostream>
#include "Cuenta.hpp"

void CajaDeAhorro::retirar(double monto) {
    monto = (countMostrarInfo < 2) ? monto : monto - 20;
    if (monto > this->balance) return;
    
    this->balance -= monto;
    return;
}

void CajaDeAhorro::mostrarInfo() {
    cout << "Balance: $" << this->balance << endl;
    cout << "Tipo de cuenta: Caja de Ahorro" << endl;
    cout << "Titular de la cuenta: " << this->titularCuenta << endl;
    this->countMostrarInfo ++;
    return;
}

void CuentaCorriente::retirar(double monto) {
    this->balance -= monto;
    return;
}

void CuentaCorriente::mostrarInfo() {
    cout << "Balance: $" << this->balance << endl;
    cout << "Tipo de cuenta: Cuenta Corriente" << endl;
    cout << "Titular de la cuenta: " << this->titularCuenta << endl;
    return;
}