#include <iostream>
#include "Cuenta.hpp"


Cuenta::~Cuenta() { //Destructor vacío. No alocamos memoria dinámica.
}

void CajaDeAhorro::retirar(double monto) {
    if (monto > this->balance) { //Si el monto supera el balance no se efectúa la transacción.
        cout << "No hay fondos suficientes en la cuenta\n";
        return;
    }
    
    this->balance -= monto;
    return;
}

void CajaDeAhorro::mostrarInfo() {
    cout << "Balance: $" << this->balance << endl;
    cout << "Tipo de cuenta: Caja de Ahorro" << endl;
    cout << "Titular de la cuenta: " << this->titularCuenta << endl;
    this->countMostrarInfo ++;
    if (this->countMostrarInfo > 2 && this->balance >= 20) { //Cada 3 invocaciones se retiran $20 del balance
        this->balance -= 20;
        cout << "$20 descontados por mostrar tantas veces la info." << endl;
        this->countMostrarInfo = 0; //Reiniciamos el contador
    }
    return;
}

void CuentaCorriente::retirar(double monto) {
    if (monto <= this->balance) this->balance -= monto;
    else if (respaldo && monto <= (this->balance + respaldo->balance)) { //Si entre la cuenta corriente y el respaldo tienen plata usamos lo que hay de la cuenta corriente y el resto del respaldo.
        double usoAhorro = monto - this->balance;
        this->balance = 0;
        respaldo->balance -= usoAhorro;
        cout << "Se usaron $" << usoAhorro << " de la Caja de Ahorro como respaldo." << endl;
    } else {
        cout << "Estás sequísimo, ni la caja de ahorro te pudo ayudar." << endl;
    }
    return;
}

void CuentaCorriente::mostrarInfo() {
    cout << "Balance: $" << this->balance << endl;
    cout << "Tipo de cuenta: Cuenta Corriente" << endl;
    cout << "Titular de la cuenta: " << this->titularCuenta << endl;
    return;
}