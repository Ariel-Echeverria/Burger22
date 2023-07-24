#include "Fecha.h"
#include "Clientes.h"
#include "Producto.h"
#ifndef DETALLE_H
#define DETALLE_H



class Detalle
{
private:
    int numero;
    Fecha FechaPedido;
    Reloj HoraPedido;
    Cliente ClientePedido;
    Producto ProductoPedido;

public:
    Detalle(int num, Fecha fecha, Reloj hora, Cliente cliente, Producto producto)
        : numero(num), FechaPedido(fecha), HoraPedido(hora), ClientePedido(cliente), ProductoPedido(producto) {}

    Detalle() {}

    void Mostrar(Detalle aux);

    void setProductoPedido(Producto aux) {
        ProductoPedido = aux;
    }

    void setID(int id) {
        numero = id;
    }

    void setFechaPedido(Fecha fecha) {
        FechaPedido = fecha;
    }

    void setHoraPedido(Reloj hora) {
        HoraPedido = hora;
    }

    void setClientePedido(Cliente cliente) {
        ClientePedido = cliente;
    }

    int getNumero() const {
        return numero;
    }

    Fecha getFechaPedido() const {
        return FechaPedido;
    }

    Reloj getHoraPedido() const {
        return HoraPedido;
    }

    Cliente getClientePedido() const {
        return ClientePedido;
    }

    Producto getProductoPedido() const {
        return ProductoPedido;
    }
};



class ArchivoDetalle {
private:
    char nombre[30];

public:
    ArchivoDetalle(const char* n) {
        strcpy(nombre, n);
    }

    const char* getNombre() {
        return nombre;
    }

    void setNombre(const char* n) {
        strcpy(nombre, n);
    }
    int getCantidadRegistros();
    void agregarRegistro(Detalle reg);
    int sobreEscribirRegistro(Detalle reg, int pos);
    int bajaLogica();
    int modificarEmail();
    bool listarArchivo();
    int buscarPedido(int d);

    Detalle leer(int pos);

    bool guardar(Detalle reg, int posicionAReemplazar);
    void mostrarPorFecha(Fecha aux);
    bool VaciarArchivo();

    int menubuscarpedido();
    void cocinadoyenvio();
    void modificarpedido(int buscar);

};





#endif // DETALLE_H
