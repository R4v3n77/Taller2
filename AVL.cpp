//
// Created by mrobl on 24-11-2024.
//

#include "AVL.h"
#include <iostream>

AVL::Nodo::Nodo(Pedido* pedido)
    : pedido(pedido), izquierda(nullptr), derecha(nullptr), altura(1) {}

AVL::AVL() : raiz(nullptr) {}

AVL::~AVL() {
    liberar(raiz);
}

int AVL::obtenerAltura(Nodo* nodo) const {
    return nodo ? nodo->altura : 0;
}

int AVL::obtenerBalance(Nodo* nodo) const {
    return nodo ? obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha) : 0;
}

AVL::Nodo* AVL::rotarDerecha(Nodo* y) {
    Nodo* x = y->izquierda;
    Nodo* T2 = x->derecha;
    x->derecha = y;
    y->izquierda = T2;
    actualizarAltura(y);
    actualizarAltura(x);
    return x;
}

AVL::Nodo* AVL::rotarIzquierda(Nodo* x) {
    Nodo* y = x->derecha;
    Nodo* T2 = y->izquierda;
    y->izquierda = x;
    x->derecha = T2;
    actualizarAltura(x);
    actualizarAltura(y);
    return y;
}

void AVL::actualizarAltura(Nodo* nodo) {
    nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));
}

AVL::Nodo* AVL::insertar(Nodo* nodo, Pedido* pedido) {
    if (!nodo) return new Nodo(pedido);

    if (pedido->getId() < nodo->pedido->getId())
        nodo->izquierda = insertar(nodo->izquierda, pedido);
    else if (pedido->getId() > nodo->pedido->getId())
        nodo->derecha = insertar(nodo->derecha, pedido);

    actualizarAltura(nodo);
    int balance = obtenerBalance(nodo);

    if (balance > 1 && pedido->getId() < nodo->izquierda->pedido->getId())
        return rotarDerecha(nodo);
    if (balance < -1 && pedido->getId() > nodo->derecha->pedido->getId())
        return rotarIzquierda(nodo);
    if (balance > 1 && pedido->getId() > nodo->izquierda->pedido->getId()) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }
    if (balance < -1 && pedido->getId() < nodo->derecha->pedido->getId()) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void AVL::liberar(Nodo* nodo) {
    if (!nodo) return;
    liberar(nodo->izquierda);
    liberar(nodo->derecha);
    delete nodo->pedido;
    delete nodo;
}

void AVL::insertarPedido(Pedido* pedido) {
    raiz = insertar(raiz, pedido);
}

void AVL::mostrarPedidos(Nodo* nodo) const {
    if (!nodo) return;
    mostrarPedidos(nodo->izquierda);
    nodo->pedido->mostrarPedido();
    mostrarPedidos(nodo->derecha);
}

void AVL::mostrarTodosLosPedidos() const {
    mostrarPedidos(raiz);
}
