#pragma once

#include "Fecha.h"
#include "Clientes.h"
#include "Producto.h"
#include "Detalle.h"

void menuPedido();

class Pedido : public Detalle{
private:
    int numero;
    Fecha FechaPedido;
    Reloj HoraPedido;
    Cliente ClientePedido;
    Detalle ProductoPedido;
    //Producto ProductoPedido;
    double total;
    bool Enviado;
    bool Recibido;

public:
    // Constructor
    Pedido(int numero, const Fecha& fechaPedido, const Reloj& HoraPedido, const Cliente& clientePedido,
           const Detalle& productoPedido, double total, bool enviado, bool recibido)
        : numero(numero), FechaPedido(fechaPedido), HoraPedido(HoraPedido), ClientePedido(clientePedido), Detalle(ProductoPedido),
          total(total), Enviado(enviado), Recibido(recibido) {

    }

    Pedido()
        : numero(0), FechaPedido(), HoraPedido(), ClientePedido(), total(0.0),
          Enviado(false), Recibido(false) {
    }

    // Getters
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



    double getTotal() const {
        return total;
    }

    bool isEnviado() const {
        return Enviado;
    }

    bool isRecibido() const {
        return Recibido;
    }

    // Setters
    void setNumero(int numero) {
        this->numero = numero;
    }

    void setFechaPedido(const Fecha& fechaPedido) {
        FechaPedido = fechaPedido;
    }

    void setHoraPedido(const Reloj& horaPedido) {
        HoraPedido = horaPedido;
    }

    void setClientePedido(const Cliente& clientePedido) {
        ClientePedido = clientePedido;
    }



    void setTotal(double total) {
        this->total = total;
    }

    void setEnviado(bool enviado) {
        Enviado = enviado;
    }

    void setRecibido(bool recibido) {
        Recibido = recibido;
    }

    void Cargar();
    void Mostrar();
};

class ArchivoPedido {
private:
    char nombre[30];

public:
    ArchivoPedido(const char* n) {
        strcpy(nombre, n);
    }

    const char* getNombre() {
        return nombre;
    }

    void setNombre(const char* n) {
        strcpy(nombre, n);
    }

    int agregarRegistro();
    int sobreEscribirRegistro(Cliente reg, int pos);
    int bajaLogica();
    int modificarEmail();
    bool listarArchivo();
    int buscarPedido(int d);

    Pedido leerRegistro(int pos);

    bool guardar(Pedido reg, int posicionAReemplazar);
    void mostrarPorFecha(Fecha aux);
    bool VaciarArchivo();
    int getCantidadRegistros();
    int menubuscarpedido();
    void cocinadoyenvio();
    void modificarpedido(int buscar);

};
