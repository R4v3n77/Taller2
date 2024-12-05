//
// Created by mrobl on 30-11-2024.
//

#ifndef ARBOL_PEDIDOS_H
#define ARBOL_PEDIDOS_H

#include <vector>
#include <string>
#include <unordered_map>

#include "Pedido.h"

class NodoPedido {
public:
    Pedido* pedido;
    NodoPedido* izquierdo;
    NodoPedido* derecho;

    NodoPedido(Pedido* p) : pedido(p), izquierdo(nullptr), derecho(nullptr) {}
};

class ArbolPedidos {
public:
    ArbolPedidos();
    ~ArbolPedidos();

    void insertarPedido(Pedido* pedido);
    bool eliminarPedido(int idPedido);
    void mostrarTodosLosPedidos() const;

    // Métodos para estadísticas
    int obtenerTotalPedidos() const;
    double obtenerMontoTotal() const;
    std::string obtenerProductoMasSolicitado() const;

    void calcularMontoTotal(NodoPedido *nodo, double &total);

private:
    NodoPedido* raiz;

    // Métodos auxiliares
    void insertarNodo(NodoPedido*& nodo, Pedido* pedido);
    bool eliminarNodo(NodoPedido*& nodo, int idPedido);
    void mostrarPedidosRecursivo(NodoPedido* nodo) const;
    void liberarMemoria(NodoPedido* nodo);

    // Métodos para estadísticas
    void contarPedidos(NodoPedido* nodo, int& contador) const;
    void calcularMontoTotal(NodoPedido* nodo, double& total) const;
    void contarProductos(NodoPedido* nodo, std::unordered_map<std::string, int>& contadorProductos) const;
};

#endif // ARBOL_PEDIDOS_H
