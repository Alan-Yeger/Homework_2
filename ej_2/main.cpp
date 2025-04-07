#include <iostream>
#include "Curso.hpp"
#include "Estudiante.hpp"

using namespace std;

int main() {
    //Para testear la implementación, creamos un curso y hacemos todo a partir de él, también creamos un vector de Estudiantes 
    //independiente a las clases para poder mantener a los estudiantes vivos y poder inscribirlos, desinscribirlos, buscarlos, etc.
    //Además, si no tuviésemos este vector, tampoco podríamos liberar la memoria al final.
    //Como esta implementación no consigue testear las funciones de los Estudiantes también creé el archivo test.cpp para eso.
    Curso curso;
    vector<Estudiante*> estudiantes;

    while (true) {
        cout << "\n--- MENÚ ---\n";
        cout << "1. Crear estudiante\n";
        cout << "2. Inscribir estudiante\n";
        cout << "3. Desinscribir estudiante\n";
        cout << "4. Ver si está inscrito\n";
        cout << "5. Mostrar estudiantes ordenados alfabéticamente\n";
        cout << "6. Ver si el curso está completo\n";
        cout << "7. Copiar curso y mostrar copia\n";
        cout << "8. Salir\n> ";

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1: { //Creamos un estudiante a partir de su nombre y legajo
                string nombre;
                int legajo;
                cout << "Nombre completo: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Legajo: ";
                cin >> legajo;
                estudiantes.push_back(new Estudiante(nombre, legajo));
                cout << "Estudiante creado.\n";
                break;
            }

            case 2: { //Inscribimos un est al curso a partir de su legajo ya que este es único.
                int legajo;
                cout << "Legajo del estudiante a inscribir: ";
                cin >> legajo;
                for (auto* e : estudiantes) {
                    if (e->getLegajo() == legajo) {
                        curso.inscribirEstudiante(e);
                        cout << "Inscrito.\n";
                        break;
                    }
                }
                break;
            }

            case 3: { //Desinscribimos a un est a partir de su legajo
                int legajo;
                cout << "Legajo del estudiante a desinscribir: ";
                cin >> legajo;
                for (auto* e : estudiantes) {
                    if (e->getLegajo() == legajo) {
                        curso.desinscribirEstudiante(e);
                        cout << "Desinscrito.\n";
                        break;
                    }
                }
                break;
            }

            case 4: { //Verificamos si un est está inscrito a partir de su legajo
                int legajo;
                cout << "Legajo: ";
                cin >> legajo;
                cout << (curso.estudianteInscripto(legajo) ? "Inscrito\n" : "No inscrito\n");
                break;
            }

            case 5: { //Mostramos los est en orden alfabético (por nombre)
                curso.mostrarEstudiantesAlfa();
                break;
            }

            case 6: { //Verificamos si el curso está completo
                cout << (curso.estaCompleto() ? "Curso completo\n" : "Hay lugar\n");
                break;
            }

            case 7: { //Creamos una copia del curso
                Curso copia(&curso);
                cout << "Copia del curso:\n";
                copia.mostrarEstudiantesAlfa();
                break;
            }
            case 8: //Borramos la memoria de todos los estudiantes antes de cerrar el programa
                for (Estudiante* e : estudiantes) delete e;
                return 0;

            default:
                cout << "Opción inválida.\n";
                break;
        }
    }
}
