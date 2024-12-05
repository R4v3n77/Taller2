//
// Created by mrobl on 24-11-2024.
//
#include "Pedido.h"
#include <iostream>

#include "ArbolPedidos.h"

Pedido::Pedido(int id, const std::string& nombreCliente, const std::string& apellidoCliente, const std::vector<Producto>& productos)
    : id(id), nombreCliente(nombreCliente), apellidoCliente(apellidoCliente), productos(productos) {}

int Pedido::getId() const {
    return id;
}

std::string Pedido::getNombreCliente() const {
    return nombreCliente;
}

std::string Pedido::getApellidoCliente() const {
    return apellidoCliente;
}

const std::vector<Producto>& Pedido::getProductos() const {
    return productos;
}

// Implementación de calcularTotal
double Pedido::calcularTotal() const {
    double total = 0.0;
    for (const auto& producto : productos) {
        total += producto.getPrecio();
    }
    return total;
}

void Pedido::mostrarPedido() const {
    std::cout << "ID Pedido: " << id << "\n";
    std::cout << "Cliente: " << nombreCliente << " " << apellidoCliente << "\n";
    std::cout << "Productos:\n";
    for (const auto& producto : productos) {
        producto.mostrarProducto();
    }
    std::cout << "Total del pedido: $" << calcularTotal() << "\n";
}
void ArbolPedidos::calcularMontoTotal(NodoPedido* nodo, double& total) {
    if (nodo == nullptr) return;

    total += nodo->pedido->calcularTotal(); // Utiliza calcularTotal de Pedido
    calcularMontoTotal(nodo->izquierdo, total);
    calcularMontoTotal(nodo->derecho, total);
}