#include <cassert>
#include <sstream>
#include "Curso.hpp"
#include "Estudiante.hpp"

void testEstudiante() {
    Estudiante e("Juan Pérez", 123);
    assert(e.getNombreCompleto() == "Juan Pérez"); //Verificamos nombre, legajo y promedio
    assert(e.getLegajo() == 123);
    assert(e.getPromedio() == 0);

    e.agregarNota("Matemática", 8); //Agregamos notas y verificamos promedio
    e.agregarNota("Historia", 6);
    assert(e.getPromedio() == 7); // (8+6)/2

    stringstream ss;
    ss << e;
    string salida = ss.str();
    assert(salida.find("Juan Pérez") != string::npos); //Verificamos la sobrecarga del operador <<
    assert(salida.find("123") != string::npos);
    assert(salida.find("7") != string::npos);
}

void testCurso() {
    Estudiante* e1 = new Estudiante("Ana", 1);
    Estudiante* e2 = new Estudiante("Carlos", 2);
    Estudiante* e3 = new Estudiante("Bruno", 3);

    e1->agregarNota("Matemática", 9);
    e1->agregarNota("Física", 7);
    e3->agregarNota("Química", 8);

    Curso curso;
    curso.inscribirEstudiante(e1);
    curso.inscribirEstudiante(e2);
    curso.inscribirEstudiante(e3);

    assert(curso.estudianteInscripto(1)); //Verificamos si los estudiantes están inscritos
    assert(curso.estudianteInscripto(2));
    assert(curso.estudianteInscripto(3));
    assert(!curso.estudianteInscripto(4));

    curso.desinscribirEstudiante(e2);
    assert(!curso.estudianteInscripto(2)); //Verificamos que ande desinscribir

    assert(!curso.estaCompleto()); //Verificamos que no está completo

    // Probar orden alfabético
    cout << "Estudiantes ordenados:\n";
    curso.mostrarEstudiantesAlfa(); // Ana y Bruno deberían aparecer en orden

    // Probar copia
    Curso copia(&curso);
    assert(copia.estudianteInscripto(1)); //Probamos que los estudiantes se copien bien
    assert(copia.estudianteInscripto(3));
    assert(!copia.estudianteInscripto(2));

    delete e1; //Liberamos la memoria
    delete e2;
    delete e3;
}

void testCursoCompleto() {
    Curso curso;
    vector<Estudiante*> ests;
    for (int i = 0; i < 20; ++i) {
        Estudiante* e = new Estudiante("Est" + to_string(i), i);
        curso.inscribirEstudiante(e);
        ests.push_back(e);
    }
    assert(curso.estaCompleto()); //Creamos 20 estudiantes y verificamos que está completo

    // No debería inscribir al estudiante 21
    Estudiante* extra = new Estudiante("Extra", 999);
    curso.inscribirEstudiante(extra);
    assert(!curso.estudianteInscripto(999));

    for (Estudiante* e : ests) delete e; //Liberamos la memoria
    delete extra;
}

int main() {
    testEstudiante();
    testCurso();
    testCursoCompleto();
    cout << "Todos los tests pasaron correctamente.\n";
    return 0;
}
