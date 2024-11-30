#include "SistemaPedidos.h"
#include <iostream>

int main() {
    SistemaPedidos sistema;
    bool corriendo = true;

    while (corriendo) {
        std::cout << "\n--- Menu Principal ---\n";
        std::cout << "1. Crear Pedido\n2. Mostrar Pedidos\n3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                sistema.crearPedido();
            break;
            case 2:
                sistema.mostrarPedidos();
            break;
            case 3:
                corriendo = false;
            std::cout << "Cerrando sistema...\n";
            break;
            default:
                std::cout << "Opción invalida. Intente nuevamente.\n";
        }
    }

    return 0;
}