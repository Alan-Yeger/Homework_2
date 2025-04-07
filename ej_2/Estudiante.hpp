#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estudiante {
    public:
        //Constructor del Estudiante
        Estudiante(string nombreCompleto, int legajo) : nombreCompleto(nombreCompleto), legajo(legajo) {};
        string getNombreCompleto() const;
        int getLegajo() const;
        float getPromedio() const;
        void agregarNota(string curso, int nota);

        friend ostream& operator<<(ostream& os, const Estudiante& est); //Sobreescribimos el << para mostrar la info completa a nuestro gusto

    private:
        string nombreCompleto;
        int legajo;
        vector<pair<string, int>> cursos; // Lista de tipo (curso, nota final).
};