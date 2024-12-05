//
// Created by mrobl on 24-11-2024.
//

#ifndef SISTEMA_PEDIDOS_H
#define SISTEMA_PEDIDOS_H

#include <vector>
#include "Producto.h"
#include "Pedido.h"
#include "ArbolPedidos.h"

class SistemaPedidos {
public:
    SistemaPedidos();
    void mostrarProductos() const;
    void crearPedido();
    void mostrarPedidos() const;
    void cancelarPedido();      // Nueva función para cancelar pedido
    void mostrarEstadisticas(); // Nueva función para mostrar estadísticas

private:
    std::vector<Producto> productos;
    ArbolPedidos arbolPedidos;
};

#endif // SISTEMA_PEDIDOS_H