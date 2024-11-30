//
// Created by mrobl on 24-11-2024.
//
#include "Producto.h"

Producto::Producto(int id, const std::string& nombre, int precio)
    : id(id), nombre(nombre), precio(precio) {}

int Producto::getId() const { return id; }
std::string Producto::getNombre() const { return nombre; }
int Producto::getPrecio() const { return precio; }

void Producto::mostrarProducto() const {
    std::cout << "ID: " << id << " - " << nombre << " ($" << precio << ")\n";
}

