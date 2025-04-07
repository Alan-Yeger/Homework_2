#pragma once
#include <set>
#include "Estudiante.hpp"

using namespace std;

/*
Este ejercicio es el más confuso por decirlo de alguna manera ya que nos piden codear 2 clases, Curso y Estudiante, que se relacionan entre sí.
La relación es de Agregación o has-a en ambos sentidos ya que un curso tiene muchos alumnos y un alumno puede tener muchos cursos pero ninguno
es dueño del otro. Habiendo visto algo de base de datos es como una relación de muchos a muchos.
*/

struct ComparadorEstudiantes {
    // Ya los guardamos en orden alfabético. Es análogo a sobreescribir el comparador del sort pero me resultó más cómodo hacerlo así.
    bool operator()(Estudiante* a, Estudiante* b) const {
        return a->getNombreCompleto() < b->getNombreCompleto(); //Sobreescribimos el comparador del set para guardarlos en orden alfabético.
    }
};

class Curso {
    public:
        Curso(){}; //Constructor default
        Curso(Curso*); //Constructor para copia
        void inscribirEstudiante(Estudiante*);
        void desinscribirEstudiante(Estudiante*);
        bool estudianteInscripto(int legajo);
        bool estaCompleto();
        void mostrarEstudiantesAlfa();
        virtual ~Curso(); //Destructor del curso


    private:
        set<Estudiante*, ComparadorEstudiantes> estudiantes; // Usamos un set con nuestro operador sobreescrito para guardarlos en orden alfabético y no tener problemas con repetidos.
        const int capacidad = 20;
};