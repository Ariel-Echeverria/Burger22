#include<iostream>
#include<cstdlib>
#include<cstring>
#include <iomanip>
using namespace std;
#include "Pedidos.h"
#include "Fecha.h"
#include "ProductoArchivo.h"
#include "ProductoManager.h"
#include "Detalle.h"
#include "funciones.h"

#include <ctime>

void Detalle::Mostrar(Detalle aux) {
            std::cout //std::setw(5) << aux.getNumero()
              //<< std::setw(5) << aux.getClientePedido().getNombre()
             // << std::setw(20) << aux.getClientePedido().getApellido()
              << std::setw(50)<< left  << aux.getProductoPedido().getnombre()
              << std::setw(50)<< left  << aux.getProductoPedido().getprecio();
//aux.getFechaPedido().Mostrar();
    std::cout << std::endl;
}

int ArchivoDetalle::getCantidadRegistros()
{
    FILE *p = fopen(nombre, "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Detalle);
}



Detalle ArchivoDetalle::leer(int nroRegistro)
{
    Detalle aux;
    FILE *p = fopen(nombre, "rb");
    if (p == NULL)
    {
        return aux;
    }

    fseek(p, nroRegistro * sizeof(Detalle), SEEK_SET);
    fread(&aux, sizeof(Detalle), 1, p);
    fclose(p);
    return aux;
}


void ArchivoDetalle::agregarRegistro(Detalle reg){
   // Detalle reg;
    FILE *pCliente;

	pCliente=fopen(nombre,"ab");///como queremos agregar registros usamos el modo ab

	if(pCliente==NULL){
		return;
	}

    ///reg.Cargar();///variable que contiene los datos que queremos llevar al disco

    int valor=fwrite(&reg, sizeof reg, 1,pCliente);
    fclose(pCliente);
    return;
}













