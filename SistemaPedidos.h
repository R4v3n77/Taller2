//
// Created by mrobl on 24-11-2024.
//

#ifndef SISTEMAPEDIDOS_H
#define SISTEMAPEDIDOS_H

#include "AVL.h"
#include "Producto.h"
#include <vector>

class SistemaPedidos {
private:
    AVL arbolPedidos;
    std::vector<Producto> productos;

public:
    SistemaPedidos();
    void mostrarProductos() const;
    void crearPedido();
    void mostrarPedidos() const;
};

#endif // SISTEMAPEDIDOS_H