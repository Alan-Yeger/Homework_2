#include <iostream>
#include <string>

using namespace std;

/*
Este punto es tranqui también. Acá creamos una interfaz Numero que nos permite generar clases derivadas que heredan los métodos pero los implemento según el tipo de número que son
*/

class Numero {
    public: //Interfaz número, vemos que todos son métodos virtuales puros
        virtual void suma(Numero* num) = 0;
        virtual void resta(Numero* num) = 0;
        virtual void multiplicacion(Numero* num) = 0;
        virtual void division(Numero* num) = 0;
        virtual string toString() = 0;
};

class Entero: public Numero {
    public:    
        Entero(int n); //El resto de las clases sobreescriben los métodos de la interfaz
        virtual void suma(Numero* x) override;
        virtual void resta(Numero* x) override;
        virtual void multiplicacion(Numero* x) override;
        virtual void division(Numero* x) override;
        virtual string toString() override;

    private:
        int n; //Entero n para enteros
};

class Real: public Numero {
    public:
        Real(float r);
        virtual void suma(Numero* x) override;
        virtual void resta(Numero* x) override;
        virtual void multiplicacion(Numero* x) override;
        virtual void division(Numero* x) override;
        virtual string toString() override;

    private:
        float r; // float r para reales
};

class Complejo: public Numero {
    public:
        Complejo(float a, float b);
        virtual void suma(Numero* x) override;
        virtual void resta(Numero* x) override;
        virtual void multiplicacion(Numero* x) override;
        virtual void division(Numero* x) override;
        virtual string toString() override;
    
    private:
        float re; // float para parte real
        float im; //float para parte imaginaria
};