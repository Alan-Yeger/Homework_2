#include "Cuenta.hpp"

int main() {
    //Creamos caja de ahorro y cuenta corriente
    CajaDeAhorro ahorro(500, "Alan");
    CuentaCorriente corriente(200, "Alan", &ahorro); //Usamos ahorro como respaldo

    ahorro.depositar(100);
    ahorro.mostrarInfo(); // 1ra vez
    ahorro.mostrarInfo(); // 2da vez
    ahorro.mostrarInfo(); // 3ra vez: debería descontar $20 y reiniciar el contador a 0

    cout << "\nIntentando retirar $600 de la caja de ahorro (debería fallar):" << endl;
    ahorro.retirar(600);

    cout << "\nIntentando retirar $100 de la caja de ahorro (debería funcionar):" << endl;
    ahorro.retirar(100);
    ahorro.mostrarInfo(); //1ra vez

    cout << "\nIntentando retirar $250 de la cuenta corriente (usa respaldo):" << endl;
    corriente.retirar(250);
    corriente.mostrarInfo();
    ahorro.mostrarInfo(); // para ver si se usó correctamente el respaldo. 2da vez

    cout << "\nIntentando retirar $1000 de la cuenta corriente (debería fallar):" << endl;
    corriente.retirar(1000);
    ahorro.mostrarInfo(); //3ra vez: debería descontar $20 y reiniciar el contador a 0

    return 0;
}
