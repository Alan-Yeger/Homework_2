#include <iostream>
#include <string>

using namespace std;

class Numero {
    public:
        virtual void suma(Numero* num) = 0;
        virtual void resta(Numero* num) = 0;
        virtual void multiplicacion(Numero* num) = 0;
        virtual void division(Numero* num) = 0;
        virtual string toString(Numero* num) = 0;
};

class Entero: public Numero {
    public:    
        Entero(int n);
        virtual void suma(Numero* x) override;
        virtual void resta(Numero* x) override;
        virtual void multiplicacion(Numero* x) override;
        virtual void division(Numero* x) override;
        virtual string toString(Numero* x) override;

    private:
        int n;
};

class Real: public Numero {
    public:
        Real(float r);
        virtual void suma(Numero* x) override;
        virtual void resta(Numero* x) override;
        virtual void multiplicacion(Numero* x) override;
        virtual void division(Numero* x) override;
        virtual string toString(Numero* x) override;

    private:
        float r;
};

class Complejo: public Numero {
    public:
        Complejo(float a, float b);
        virtual void suma(Numero* x) override;
        virtual void resta(Numero* x) override;
        virtual void multiplicacion(Numero* x) override;
        virtual void division(Numero* x) override;
        virtual string toString(Numero* x) override;
    
    private:
        float re;
        float im;
};