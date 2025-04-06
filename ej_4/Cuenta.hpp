#pragma once
#include <iostream>
#include <string>

using namespace std;

/*
En este ejercicio creamos la clase abstracta Cuenta y a partir de ella derivamos las clases CajaDeAhorro y CuentaCorriente
Hacemos que CajaDeAhorro sea friend de CuentaCorriente para que CajaDeAhorro pueda usarse como respaldo.
En este archivo están especificadas las elecciones de public, private y protected.
*/

class Cuenta {
    public:
        //Constructor público para poder crear objetos de las clases derivadas
        Cuenta(double balanceInicial, string titular): balance(balanceInicial), titularCuenta(titular){};

        //Métodos públicos ya que son los que necesita utilizar el usuario
        void depositar(double monto){ 
            if (monto > 0) balance += monto;
        };
        virtual void retirar(double monto) = 0;
        virtual void mostrarInfo() = 0;
        virtual ~Cuenta();

    protected:
        double balance; // Para estos atributos usamos protected en vez de private ya que queremos que las clases derivadas puedan acceder a ellos pero no las clases externas.
        string titularCuenta;
};

class CajaDeAhorro: public Cuenta {
    public:
        //Constructor y métodos públicos para que interactúe el usuario
        CajaDeAhorro(double balanceInicial, string titular): Cuenta(balanceInicial, titular), countMostrarInfo(0){};
        void retirar(double monto) override;
        void mostrarInfo() override;
        //Las clases friend se declaran como públicas porque justamente estamos haciendo que una clase tenga acceso a atributos/métodos de otra de manera pública
        friend class CuentaCorriente;

    private:
        int countMostrarInfo; //countMostrarInfo es privado y no protected porque esta clase no tiene subclases y no queremos que el usuario modifique su valor
};

class CuentaCorriente: public Cuenta {
    public:
        //Constructor y métodos públicos para que interactúe el usuario
        CuentaCorriente(double balanceInicial, string titular, CajaDeAhorro* respaldo): Cuenta(balanceInicial, titular), respaldo(respaldo){};
        void retirar(double monto) override;
        void mostrarInfo() override;

    private:
        //El usuario no debe tener acceso ni modificar la caja de ahorro desde acá, solo se usa desde la lógica de la implementación por lo que es privado.
        CajaDeAhorro* respaldo;
};