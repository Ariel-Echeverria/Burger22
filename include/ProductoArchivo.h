#pragma once
#include "Producto.h"

#include <string>

class ProductoArchivo
{
public:
    int getCantidadRegistros();
    bool guardar(Producto reg);
    bool guardar(Producto reg, int posicionAReemplazar);
    //bool leer(Producto &reg, int nroRegistro);
    Producto leer(int nroRegistro);
    int buscar(int ID);
    void ListarProductos();

    ProductoArchivo();
    ProductoArchivo(std::string ruta);
private:
    std::string _ruta;
};
