//
// Created by mrobl on 24-11-2024.
//
#include "SistemaPedidos.h"
#include <iostream>
#include <algorithm> // Se incluye el encabezado necesario para std::find_if

SistemaPedidos::SistemaPedidos() {
    productos = {
        Producto(1, "Hamburguesa Clasica", 6500),
        Producto(2, "Hamburguesa Doble", 7500),
        Producto(3, "Hamburguesa BBQ", 8000),
        Producto(4, "Papas Fritas Grandes", 3000),
        Producto(5, "Papas Fritas Medianas", 1500),
        Producto(6, "Nuggets de Pollo (10 piezas)", 2000),
        Producto(7, "Ensalada Cesar", 5500),
        Producto(8, "Agua Mineral", 2000),
        Producto(9, "Gaseosa (350 ml)", 1500),
        Producto(10, "Gaseosa (500 ml)", 2500),
        Producto(11, "Batido de Vainilla", 2500),
        Producto(12, "Batido de Chocolate", 2500),
        Producto(13, "Batido de Fresa", 2500)
    };
}

void SistemaPedidos::mostrarProductos() const {
    std::cout << "Productos disponibles:\n";
    for (const auto& producto : productos) {
        producto.mostrarProducto();
    }
}

void SistemaPedidos::crearPedido() {
    std::string nombre, apellido;
    std::cout << "Nombre del cliente: ";
    std::cin >> nombre;
    std::cout << "Apellido del cliente: ";
    std::cin >> apellido;

    mostrarProductos();

    std::vector<Producto> productosPedido;
    int idProducto;
    std::cout << "Seleccione productos por ID (0 para terminar): ";
    while (true) {
        std::cin >> idProducto;
        if (idProducto == 0) break;

        auto it = std::find_if(productos.begin(), productos.end(),
                               [idProducto](const Producto& p) { return p.getId() == idProducto; });

        if (it != productos.end()) {
            productosPedido.push_back(*it);
            std::cout << "Producto agregado: " << it->getNombre() << "\n";
        } else {
            std::cout << "Producto no encontrado. Intente de nuevo.\n";
        }
    }

    if (productosPedido.empty()) {
        std::cout << "No se seleccionaron productos. Pedido cancelado.\n";
        return;
    }

    static int idPedido = 1;
    Pedido* nuevoPedido = new Pedido(idPedido++, nombre, apellido, productosPedido);
    arbolPedidos.insertarPedido(nuevoPedido);
    std::cout << "Pedido creado exitosamente.\n";
}

void SistemaPedidos::mostrarPedidos() const {
    arbolPedidos.mostrarTodosLosPedidos();
}