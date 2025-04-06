#include <iostream>
#include "Curso.hpp"

using namespace std;


ostream& operator<<(ostream& os, Estudiante& est) {
    os << est.getLegajo() << " - " << est.getNombreCompleto(); // o como quieras mostrarlo
    return os;
}

Curso::Curso(Curso* oldCurso) {
    for(Estudiante* est: oldCurso->estudiantes){
        this->estudiantes.insert(est);
    }
}


void Curso::inscribirEstudiante(Estudiante* est) {
    estudiantes.insert(est);
}

void Curso::desinscribirEstudiante(Estudiante* est) {
    estudiantes.erase(est);
}

bool Curso::estudianteInscripto(int legajo) {
    for (Estudiante* est: estudiantes) {
        if (est->getLegajo() == legajo) return true;
    }
    return false;
}

void Curso::mostrarEstudiantesAlfa() {
    for (Estudiante* est : estudiantes) {
        cout << est << endl;
    }
}

string Estudiante::getNombreCompleto() {
    return this->nombreCompleto;
}

int Estudiante::getLegajo() {
    return this->legajo;
}

float Estudiante::getPromedio() {
    if (cursos.empty()) return 0;
    
    float prom = 0;
    for (pair<string, int>& par: cursos) {
        prom += (par.second / cursos.size());
    }

    
    return prom;
}