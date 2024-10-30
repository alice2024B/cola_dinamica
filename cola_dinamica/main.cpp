#include <iostream>
#include "Cola.h"

void mostrarMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Dar de alta la solicitud de un alumno\n";
    std::cout << "2. Elaborar una constancia\n";
    std::cout << "3. Salir\n";
    std::cout << "Elige una opcion: ";
}

int main() {
    Cola MiCola;
    persona x;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: // Dar de alta la solicitud
                std::cin >> x;  // Ingresar datos del alumno
                MiCola.enqueue(x);  // Encolar la solicitud
                std::cout << "Solicitud de " << x.getNombre() << " ha sido registrada.\n";
                break;
            case 2: // Elaborar una constancia
                if (MiCola.vacia()) {
                    std::cout << "No hay solicitudes en la cola.\n";
                } else {
                    std::cout << "Generando constancia:\n";
                    std::cout << MiCola.dequeue();  // Desencolar y mostrar constancia
                }
                break;
            case 3: // Salir
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion no valida. Por favor, intenta de nuevo.\n";
        }
    } while (opcion != 3);

    return 0;
}


