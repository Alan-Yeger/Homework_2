#include <iostream>
#include <vector>
#include <set>


struct ComparadorEstudiantes {
    bool operator()(Estudiante* a, Estudiante* b) const {
        return a->getNombreCompleto() < b->getNombreCompleto(); // Ya los guardamos en orden alfabético. Es análogo a sobreescribir el comparador del sort.
    }
};


class Curso {
    public:
        Curso();
        Curso(Curso*);
        void inscribirEstudiante(Estudiante*);
        void desinscribirEstudiante(Estudiante*);
        bool estudianteInscripto(int legajo);
        void mostrarEstudiantesAlfa();

    private:
        set<Estudiante*, ComparadorEstudiantes> estudiantes; // Usamos un set con nuestro operador sobreescrito para guardarlos en orden alfabético y no tener problemas con repetidos.
        const int capacidad = 20;
};

class Estudiante {
    public:
        string getNombreCompleto();
        int getLegajo();
        float getPromedio();
        friend ostream& operator<<(ostream& os, const Estudiante& est);

    private:
        string nombreCompleto;
        int legajo;
        vector<pair<string, int>> cursos; // Lista de tipo (nombre curso, nota final).
};