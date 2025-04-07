#include <iostream>
#include "Time.hpp"

using namespace std;

int main() {
    int hh, mm, ss, opcion;
    string ampm;
    bool isDay;
    Time t;

    while(true) {
        cout << "\n--- Menú ---\n";
        cout << "1. Crear tiempo sin parámetros\n";
        cout << "2. Crear tiempo con hora\n";
        cout << "3. Crear tiempo con hora y minutos\n";
        cout << "4. Crear tiempo con hora, minutos y segundos\n";
        cout << "5. Crear tiempo completo (hora, minutos, segundos, am/pm)\n";
        cout << "6. Setear tiempo, minutos, segundos o am/pm individualmente\n";
        cout << "7. Mostrar hora\n";;
        cout << "8. Mostrar minutos\n";
        cout << "9. Mostrar segundos\n";
        cout << "10. Mostrar am/pm\n";
        cout << "11. Mostrar tiempo en formato HHh, MMm, SSs am/pm\n";
        cout << "12. Mostrar tiempo en formato 24 horas (HH:MM:SS)\n";
        cout << "13. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                t = Time(); //Se crea el objeto sin parámetros
                break;
            case 2:
                cout << "Ingrese hora (1-12): ";
                cin >> hh;
                if (hh < 1 || hh > 12) { //Verificamos casos inválidos
                    cout << "Hora inválida.\n";
                    continue;
                }
                t = Time(hh); //Se crea el objeto con la hora
                break;
            case 3:
                cout << "Ingrese hora (1-12): ";
                cin >> hh;
                cout << "Ingrese minutos (0-59): ";
                cin >> mm;
                if (hh < 1 || hh > 12 || mm < 0 || mm > 59) { //Verificamos casos inválidos
                    cout << "Valores inválidos.\n";
                    continue;
                }
                t = Time(hh, mm); //Se crea el objeto con hora y minutos
                break;
            case 4:
                cout << "Ingrese hora (1-12): ";
                cin >> hh;
                cout << "Ingrese minutos (0-59): ";
                cin >> mm;
                cout << "Ingrese segundos (0-59): ";
                cin >> ss;
                if (hh < 1 || hh > 12 || mm < 0 || mm > 59 || ss < 0 || ss > 59) { //Verificamos casos inválidos
                    cout << "Valores inválidos.\n";
                    continue;
                }
                t = Time(hh, mm, ss); //Se crea el objeto con hora, minutos y segundos
                break;
            case 5:
                cout << "Ingrese hora (1-12): ";
                cin >> hh;
                cout << "Ingrese minutos (0-59): ";
                cin >> mm;
                cout << "Ingrese segundos (0-59): ";
                cin >> ss;
                cout << "¿Es p.m. o a.m.? (pm/am): ";
                cin >> ampm;
                isDay = (ampm == "pm"); //isDay = true cuando la hora es pm

                if (hh < 1 || hh > 12 || mm < 0 || mm > 59 || ss < 0 || ss > 59 || (ampm != "pm" && ampm != "am")) { //Verificamos casos inválidos
                    cout << "Valores inválidos.\n";
                    continue;
                }

                t = Time(hh, mm, ss, isDay); //Se crea el objeto con hora, minutos, segundos y si es de día o no
                break;
            case 6:
                cout << "Ingrese valores individuales\n";
                cout << "Hora (1-12): "; cin >> hh;
                cout << "Minutos (0-59): "; cin >> mm;
                cout << "Segundos (0-59): "; cin >> ss;
                cout << "¿Es p.m. o a.m.? (pm/am): "; cin >> ampm;
                if (hh < 1 || hh > 12 || mm < 0 || mm > 59 || ss < 0 || ss > 59 || (ampm != "pm" && ampm != "am")) { //Verificamos casos inválidos
                    cout << "Valores inválidos.\n";
                    continue;
                }
                t.setHour(hh); //Seteamos cada parámetro por separado
                t.setMinute(mm);
                t.setSecond(ss);
                t.setAmPm(ampm == "pm");
                break;
            case 7:
                cout << t.getHour() << endl; //Mostramos hora
                break;
            case 8:
                cout << t.getMinute() << endl; //Mostramos minutos
                break;
            case 9:
                cout << t.getSecond() << endl; //Mostramos segundos
                break;
            case 10:
                cout << (t.getAmPm() ? "La hora es pm" : "La hora es am") << endl; //Mostramos si es de día
                break;
            case 11:
                cout << setw(2) << setfill('0') << t.getHour() << ":"; //Imprimimos el tiempo completo
                cout << setw(2) << setfill('0') << t.getMinute() << ":";
                cout << setw(2) << setfill('0') << t.getSecond();
                cout << (t.getAmPm() ? " pm" : " am") << endl;
                break;
            case 12:
                cout << t.getTime() << endl; //Imprimimos el tiempo en formato 24hs
                break;
            case 13:
                cout << "Saliendo del programa...\n"; //Salimos del programa
                return 0;
            default:
                cout << "Opción inválida.\n";
        }
    }

    return 0;
}