#include "Estudiante.hpp"

string Estudiante::getNombreCompleto() const {
    return this->nombreCompleto;
}

int Estudiante::getLegajo() const {
    return this->legajo;
}

float Estudiante::getPromedio() const {
    if (cursos.empty()) return 0;

    float suma = 0;
    for (const pair<string, int>& par : cursos) { //Sumamos todas las notas
        suma += par.second;
    }
    return suma / cursos.size(); //Dividimos por la cantidad de notas
}


void Estudiante::agregarNota(string curso, int nota) {
    cursos.emplace_back(curso, nota);
}

//Sobreescribimos el operador << para mostrar legajo - nombreCompleto - promedio
ostream& operator<<(ostream& os, const Estudiante& est) {
    os << est.getLegajo() << " - " << est.getNombreCompleto() << " - Promedio: " << est.getPromedio();
    return os;
}