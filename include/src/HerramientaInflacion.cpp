#include <iostream>
using namespace std;
#include "ProductoManager.h"
#include "funciones.h"
#include "ProductoArchivo.h"
#include "Producto.h"
#include "ProductoMenu.h"
#include "HerramientaInflacion.h"
#include "Fecha.h"













void menuinflacion (){
  system("cls");
int inflacion;
int contadorDias=0;
Inflacion nuevo;
ArchivoInflacion aux("Inflacion.dat");

Fecha fechaActual;
cout<<"HERRAMIENTA INFLACION:"<<endl;
cout<<"FECHA: ";
fechaActual.obtenerFechaHoraActual();
cout<<"INGRESE LA ESTIMADA ANUAL %";
inflacion=getInteger(0,1000);
nuevo.setPorcentajeAnual(inflacion);


nuevo.setComienzo(fechaActual);

aux.guardarInflacion(nuevo);
cout<<"NUESTRO ALGORITMO PONE EL PLAN DE MODIFICAR DIARIAMENTE EL PRECIO EN AUTOMATICO"<<endl;
cout<<"ASI TODOS LOS DIAS VAS A TENER AUMENTOS CRECIENTES"<<endl;

calculoinflacionarreglo();
system("pause");
}
void calculoinflacionarreglo() {
    float calculo;



    ArchivoInflacion aux("Inflacion.dat");
    Inflacion guardada = aux.leerInflacion();
    Fecha cant;
    Fecha fechaActual;
    fechaActual.obtenerFechaHoraActual();
    //Fecha anterios(24,5,2023);

    //int cantidadDias = (anterios.diferenciaDias(anterios))*-1;//PRUEBAS PARA CHEQUEAR EL FUNCIONAMIENTO
    int cantidadDias = (cant.diferenciaDias(guardada.getComienzo()))*-1; // ESTA ES LA QUE VA


    float infdiario = static_cast<float>(guardada.getPorcentajeAnual()) / 365.0;
    //guardada.getComienzo().Mostrar();

    ProductoArchivo proc("Productos.dat");
    Producto producto;

    int totalinflacion=infdiario*cantidadDias;
    float precioActualizado;
    int can=proc.getCantidadRegistros();
    if(cantidadDias>0){
    for(int i=0; i<can; i++){
    producto=proc.leer(i);
    calculo=producto.getprecio();
    precioActualizado = producto.getprecio() * (1 + ((infdiario  * cantidadDias)/100));
    producto.setprecio(precioActualizado);
    proc.guardar(producto, i);
    }


cout<<"ACTUALIZACION DE PRECIO EN AUTOMATICO: "<<endl;
cout<<"Cantidad de dias acumulados: "<<cantidadDias<<endl;
cout<<"Inflacion configurada "<<guardada.getPorcentajeAnual()<<"%"<<endl;
cout<<"Inflacion diario "<<infdiario<<"%"<<endl;

guardada.setComienzo(fechaActual);
aux.guardarInflacion(guardada);


    }
    else{
      cout<<"NO SE ACTUALIZARON LOS PRECIO EN AUTOMATICO FALTA UN DIA: "<<endl;
    cout<<"Cantidad de dias acumulados; "<<cantidadDias<<endl;
    }


system("pause");
///
}
