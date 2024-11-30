//
// Created by mrobl on 24-11-2024.
//
#include "Pedido.h"
#include <iostream>

Pedido::Pedido(int id, const std::string& nombreCliente, const std::string& apellidoCliente, const std::vector<Producto>& productos)
    : id(id), nombreCliente(nombreCliente), apellidoCliente(apellidoCliente), productos(productos) {
    horaPedido = time(nullptr);
}

int Pedido::getId() const { return id; }
std::string Pedido::getNombreCliente() const { return nombreCliente; }
std::string Pedido::getApellidoCliente() const { return apellidoCliente; }
const std::vector<Producto>& Pedido::getProductos() const { return productos; }
time_t Pedido::getHoraPedido() const { return horaPedido; }

void Pedido::mostrarPedido() const {
    std::cout << "ID Pedido: " << id << "\n";
    std::cout << "Cliente: " << nombreCliente << " " << apellidoCliente << "\n";
    std::cout << "Productos:\n";
    for (const auto& producto : productos) {
        producto.mostrarProducto();
    }
    std::cout << "Hora del pedido: " << ctime(&horaPedido) << "\n";
}