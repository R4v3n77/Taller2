cmake_minimum_required(VERSION 3.29)
project(taller2)

set(CMAKE_CXX_STANDARD 20)

add_executable(taller2 main.cpp
        Producto.cpp
        Producto.h
        Pedido.cpp
        Pedido.h
        AVL.cpp
        AVL.h
        SistemaPedidos.cpp
        SistemaPedidos.h
)
