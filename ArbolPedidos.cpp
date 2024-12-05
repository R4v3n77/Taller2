//
// Created by mrobl on 30-11-2024.
//

#include "ArbolPedidos.h"
#include <iostream>
#include <unordered_map>

// Constructor
ArbolPedidos::ArbolPedidos() : raiz(nullptr) {}

// Destructor
ArbolPedidos::~ArbolPedidos() {
    liberarMemoria(raiz);
}

// Insertar un nuevo pedido
void ArbolPedidos::insertarPedido(Pedido* pedido) {
    insertarNodo(raiz, pedido);
}

void ArbolPedidos::insertarNodo(NodoPedido*& nodo, Pedido* pedido) {
    if (nodo == nullptr) {
        nodo = new NodoPedido(pedido);
    } else if (pedido->getId() < nodo->pedido->getId()) {
        insertarNodo(nodo->izquierdo, pedido);
    } else {
        insertarNodo(nodo->derecho, pedido);
    }
}

// Eliminar un pedido por ID
bool ArbolPedidos::eliminarPedido(int idPedido) {
    return eliminarNodo(raiz, idPedido);
}

bool ArbolPedidos::eliminarNodo(NodoPedido*& nodo, int idPedido) {
    if (nodo == nullptr) return false;

    if (idPedido < nodo->pedido->getId()) {
        return eliminarNodo(nodo->izquierdo, idPedido);
    } else if (idPedido > nodo->pedido->getId()) {
        return eliminarNodo(nodo->derecho, idPedido);
    } else {
        // Nodo encontrado: eliminarlo
        NodoPedido* temp = nodo;

        if (nodo->izquierdo == nullptr) {
            nodo = nodo->derecho;
        } else if (nodo->derecho == nullptr) {
            nodo = nodo->izquierdo;
        } else {
            // Reemplazar con el mínimo del subárbol derecho
            NodoPedido* reemplazo = nodo->derecho;
            while (reemplazo->izquierdo != nullptr) {
                reemplazo = reemplazo->izquierdo;
            }
            nodo->pedido = reemplazo->pedido;
            eliminarNodo(nodo->derecho, reemplazo->pedido->getId());
        }

        delete temp;
        return true;
    }
}

// Mostrar todos los pedidos en orden
void ArbolPedidos::mostrarTodosLosPedidos() const {
    mostrarPedidosRecursivo(raiz);
}

void ArbolPedidos::mostrarPedidosRecursivo(NodoPedido* nodo) const {
    if (nodo == nullptr) return;

    mostrarPedidosRecursivo(nodo->izquierdo);
    nodo->pedido->mostrarPedido();  // Asumiendo que Pedido tiene un método mostrarPedido()
    mostrarPedidosRecursivo(nodo->derecho);
}

// Liberar memoria
void ArbolPedidos::liberarMemoria(NodoPedido* nodo) {
    if (nodo == nullptr) return;

    liberarMemoria(nodo->izquierdo);
    liberarMemoria(nodo->derecho);
    delete nodo->pedido;
    delete nodo;
}

// Obtener el total de pedidos
int ArbolPedidos::obtenerTotalPedidos() const {
    int contador = 0;
    contarPedidos(raiz, contador);
    return contador;
}

void ArbolPedidos::contarPedidos(NodoPedido* nodo, int& contador) const {
    if (nodo == nullptr) return;

    contarPedidos(nodo->izquierdo, contador);
    contador++;
    contarPedidos(nodo->derecho, contador);
}

// Calcular el monto total de todos los pedidos
double ArbolPedidos::obtenerMontoTotal() const {
    double total = 0.0;
    calcularMontoTotal(raiz, total);
    return total;
}

void ArbolPedidos::calcularMontoTotal(NodoPedido* nodo, double& total) const {
    if (nodo == nullptr) return;

    calcularMontoTotal(nodo->izquierdo, total);
    total += nodo->pedido->calcularTotal();  // Asumiendo que Pedido tiene un método calcularTotal()
    calcularMontoTotal(nodo->derecho, total);
}

// Obtener el producto más solicitado
std::string ArbolPedidos::obtenerProductoMasSolicitado() const {
    std::unordered_map<std::string, int> contadorProductos;
    contarProductos(raiz, contadorProductos);

    std::string productoMasSolicitado;
    int maxCantidad = 0;

    for (const auto& par : contadorProductos) {
        if (par.second > maxCantidad) {
            maxCantidad = par.second;
            productoMasSolicitado = par.first;
        }
    }

    return productoMasSolicitado;
}

void ArbolPedidos::contarProductos(NodoPedido* nodo, std::unordered_map<std::string, int>& contadorProductos) const {
    if (nodo == nullptr) return;

    contarProductos(nodo->izquierdo, contadorProductos);
    for (const auto& producto : nodo->pedido->getProductos()) {
        contadorProductos[producto.getNombre()]++;
    }
    contarProductos(nodo->derecho, contadorProductos);
}
