#include "Curso.hpp"

using namespace std;

Curso::Curso(Curso* oldCurso) {
    //Copia superficial: compartimos punteros a los mismos estudiantes
    //Justificación: como dijimos que la relación es de agregación similar a una relación de muchos a muchos
    //no necesito duplicar al alumno, me sirve compartir la referencia ya que es el mismo alumno el que pertenece a varios cursos
    for(Estudiante* est: oldCurso->estudiantes){
        this->estudiantes.insert(est);
    }
}

Curso::~Curso() {
    //No liberamos memoria de los Estudiante, ya que no fueron creados dentro de Curso
    //solo limpiamos el set por claridad.
    estudiantes.clear();
}


void Curso::inscribirEstudiante(Estudiante* est) {
    if (!estaCompleto()) estudiantes.insert(est);
}

void Curso::desinscribirEstudiante(Estudiante* est) {
    estudiantes.erase(est);
}

bool Curso::estudianteInscripto(int legajo) {
    for (Estudiante* est: estudiantes) { //Como ordenamos por nombre, debemos realizar una búsqueda lineal para buscar legajos
        if (est->getLegajo() == legajo) return true;
    }
    return false;
}

bool Curso::estaCompleto() {
    return estudiantes.size() >= capacidad;
}

void Curso::mostrarEstudiantesAlfa() {
    for (Estudiante* est : estudiantes) {
        cout << *est << endl;
    }
}