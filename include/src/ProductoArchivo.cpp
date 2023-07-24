#include "ProductoArchivo.h"
#include "funciones.h"
#include <cstdio>


ProductoArchivo::ProductoArchivo()
{
    _ruta = "Productos.dat";
}

ProductoArchivo::ProductoArchivo(std::string ruta)
{
    _ruta = ruta;
}

int ProductoArchivo::getCantidadRegistros()
{
    FILE *p = fopen(_ruta.c_str(), "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Producto);
}

bool ProductoArchivo::guardar(Producto reg)
{
    FILE *p = fopen(_ruta.c_str(), "ab");

    if (p == NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return pudoEscribir;
}

bool ProductoArchivo::guardar(Producto reg, int posicionAReemplazar)
{
    FILE *p = fopen(_ruta.c_str(), "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Producto), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return pudoEscribir;
}

Producto ProductoArchivo::leer(int nroRegistro)
{
    Producto aux;
    FILE *p = fopen(_ruta.c_str(), "rb");
    if (p == NULL)
    {
        return aux;
    }

    fseek(p, nroRegistro * sizeof(Producto), SEEK_SET);
    fread(&aux, sizeof(Producto), 1, p);
    fclose(p);
    return aux;
}



int ProductoArchivo::buscar(int ID)
{
    int i, cantidadRegistros = this->getCantidadRegistros();
    Producto aux;

    for(i=0; i<cantidadRegistros; i++)
    {
        aux = this->leer(i);
        if (aux.getID() == ID)
        {
            return i;
        }
    }
    return -1;
}
