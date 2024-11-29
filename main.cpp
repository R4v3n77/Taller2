#include <iostream>
#include "SistemaPedidos.h"




int main() {
    SistemaPedidos sistema;
    int opcion;

    do {
        std::cout << "\nMENU PRINCIPAL:\n";
        std::cout << "1. Crear pedido\n";
        std::cout << "2. Mostrar pedidos\n";
        std::cout << "3. Cancelar pedido\n";     // Nueva opción
        std::cout << "4. Ver estadísticas\n";    // Nueva opción
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                sistema.crearPedido();
            break;
            case 2:
                sistema.mostrarPedidos();
            break;
            case 3:
                sistema.cancelarPedido();
            break;
            case 4:
                sistema.mostrarEstadisticas();
            break;
            case 0:
                std::cout << "Saliendo del sistema.\n";
            break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}