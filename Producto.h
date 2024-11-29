//
// Created by mrobl on 24-11-2024.
//


#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>

class Producto {
private:
    int id;
    std::string nombre;
    int precio;

public:
    Producto(int id, const std::string& nombre, int precio);
    int getId() const;
    std::string getNombre() const;
    int getPrecio() const;
    void mostrarProducto() const;
};

#endif // PRODUCTO_H