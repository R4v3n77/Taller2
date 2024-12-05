//
// Created by mrobl on 24-11-2024.
//
#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include "Producto.h"

class Pedido {
private:
    int id;
    std::string nombreCliente;
    std::string apellidoCliente;
    std::vector<Producto> productos;

public:
    Pedido(int id, const std::string& nombreCliente, const std::string& apellidoCliente, const std::vector<Producto>& productos);

    int getId() const;
    std::string getNombreCliente() const;
    std::string getApellidoCliente() const;
    const std::vector<Producto>& getProductos() const;

    // Declarar calcularTotal
    double calcularTotal() const;

    void mostrarPedido() const;
};

#endif // PEDIDO_H
