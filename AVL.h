//
// Created by mrobl on 24-11-2024.
//
#ifndef AVL_H
#define AVL_H

#include "Pedido.h"

class AVL {
private:
    struct Nodo {
        Pedido* pedido;
        Nodo* izquierda;
        Nodo* derecha;
        int altura;

        Nodo(Pedido* pedido);
    };

    Nodo* raiz;

    int obtenerAltura(Nodo* nodo) const;
    int obtenerBalance(Nodo* nodo) const;
    Nodo* rotarDerecha(Nodo* y);
    Nodo* rotarIzquierda(Nodo* x);
    void actualizarAltura(Nodo* nodo);
    Nodo* insertar(Nodo* nodo, Pedido* pedido);
    void liberar(Nodo* nodo);
    void mostrarPedidos(Nodo* nodo) const;

public:
    AVL();
    ~AVL();
    void insertarPedido(Pedido* pedido);
    void mostrarTodosLosPedidos() const;
};

#endif // AVL_H