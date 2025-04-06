#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cuenta {
    public:
        Cuenta(double balanceInicial, string titular): balance(balanceInicial), titularCuenta(titular){};

        void depositar(double monto){ 
            if (monto > 0) balance += monto;
        };
        virtual void retirar(double monto) = 0;
        virtual void mostrarInfo() = 0;
        virtual ~Cuenta();

    protected:
        double balance;
        string titularCuenta;
};

class CajaDeAhorro: public Cuenta {
    CajaDeAhorro(double balanceInicial, string titular): Cuenta(balanceInicial, titular), countMostrarInfo(0){};
    void retirar(double monto) override;
    void mostrarInfo() override;
    friend class CuentaCorriente;

    private:
        int countMostrarInfo;
};

class CuentaCorriente: public Cuenta {
    CuentaCorriente(double balanceInicial, string titular): Cuenta(balanceInicial, titular){};
    virtual void retirar(double monto) override;
    virtual void mostrarInfo() override;
    virtual ~CuentaCorriente();
};