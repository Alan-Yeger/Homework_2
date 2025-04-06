#include <iostream>
#include "Numero.hpp"

using namespace std;

int main() {
    // Tests para Entero
    Entero a(10), b(5), c(0);
    a.suma(&b);
    cout << "Entero: 10 + 5 = " << a.toString() << endl;
    a.resta(&b);
    cout << "Entero: 15 - 5 = " << a.toString() << endl;
    a.multiplicacion(&b);
    cout << "Entero: 10 * 5 = " << a.toString() << endl;
    a.division(&b);
    cout << "Entero: 50 / 5 = " << a.toString() << endl;
    a.division(&c);
    cout << "Entero: 10 / 0 = " << a.toString() << endl;

    // Tests para Real
    Real r1(10.5), r2(2.5), r3(0.0);
    r1.suma(&r2);
    cout << "Real: 10.5 + 2.5 = " << r1.toString() << endl;
    r1.resta(&r2);
    cout << "Real: 13 - 2.5 = " << r1.toString() << endl;
    r1.multiplicacion(&r2);
    cout << "Real: 10.5 * 2.5 = " << r1.toString() << endl;
    r1.division(&r2);
    cout << "Real: 26.25 / 2.5 = " << r1.toString() << endl;
    r1.division(&r3);
    cout << "Real: 10.5 / 0 = " << r1.toString() << endl;

    // Tests para Complejo
    Complejo c1(2, 3), c2(1, -1);
    c1.suma(&c2);
    cout << "Complejo: (2+3i) + (1-1i) = " << c1.toString() << endl;
    c1.resta(&c2);
    cout << "Complejo: (3+2i) - (1-1i) = " << c1.toString() << endl;
    c1.multiplicacion(&c2);
    cout << "Complejo: (2+3i)*(1-1i) = " << c1.toString() << endl;
    c1.division(&c2);
    cout << "Complejo: resultado final tras / (1-1i): " << c1.toString() << endl;

    return 0;
}
