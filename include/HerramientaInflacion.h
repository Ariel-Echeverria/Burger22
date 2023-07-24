#pragma once
#include "Producto.h"
#include "ProductoArchivo.h"
#include "Fecha.h"
#include <cstring>

class Inflacion{
private:
    int porcentajeAnual;
    Fecha comienzo;
public:
// Constructor
Inflacion(int porcentaje, Fecha fechaComienzo) {
porcentajeAnual = porcentaje;
comienzo = fechaComienzo;
}
Inflacion(){
porcentajeAnual=0;

comienzo = Fecha();
}

void setPorcentajeAnual(int porcentaje) {
    porcentajeAnual = porcentaje;
}

void setComienzo(Fecha fechaComienzo) {
    comienzo = fechaComienzo;
}
int getPorcentajeAnual() {
        return porcentajeAnual;
    }

Fecha getComienzo() {
        return comienzo;
    }


};
class ArchivoInflacion{
private:
char nombre[30];

public:
ArchivoInflacion(const char* n) {
strcpy(nombre, n);
}
bool guardarInflacion(Inflacion inflacion) {
    FILE* p;
    p = fopen(nombre, "wb");
    if (p == NULL) {
        return false;
    }

    bool escribio = fwrite(&inflacion, sizeof(Inflacion), 1, p);
    fclose(p);

    return escribio;
}
Inflacion leerInflacion() {
    Inflacion inflacion;
    FILE* p;
    p = fopen(nombre, "rb");
    if (p == NULL) {
        // Manejar el caso de error de apertura de archivo
        // Puedes lanzar una excepción, devolver un valor predeterminado o manejarlo de alguna otra manera
    } else {
        bool leyo = fread(&inflacion, sizeof(Inflacion), 1, p);
        fclose(p);
        if (!leyo) {
               std:: cout<<"no pudo leer";
            // Manejar el caso de error de lectura del archivo
            // Puedes lanzar una excepción, devolver un valor predeterminado o manejarlo de alguna otra manera
        }

      //  std::cout<<inflacion.getPorcentajeAnual();
    }

    // std::cout<<inflacion.getPorcentajeAnual();
 /// inflacion.getComienzo().Mostrar();

    return inflacion;
}



};



void calculoinflacionarreglo();
void menuinflacion ();
