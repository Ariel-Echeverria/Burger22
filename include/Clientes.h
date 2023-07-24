#pragma once

# include<iostream>
# include<cstdlib>
# include<cstring>
# include "Fecha.h"

void cargarCadena(char *pal, int tam);
bool mostrarArchivoClientes();
int cargarClienteArchivo();
void buscarEnArchivo();
void menuprincipal();


class Persona{
protected:
    int DNI;
    Fecha fechaNacimiento;
    char nombre[25];
    char apellido[25];
    char email[25];
    char telefono[20];
    bool estado;
public:
    int getDNI(){return DNI;}
    Fecha getFechaNacimiento();
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}
    bool getEstado(){return estado;}

    void setDNI(const int d){DNI=d;}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setEstado(bool e){estado=e;}

    void Cargar();
    void Mostrar();
};
class Cliente: public Persona{
    private:
        char CUIT[12];
        Fecha fechaInicio;
    public:
        const char *getCUIT(){return CUIT;}
        Fecha getFechaInicio(){return fechaInicio;}

        void setCUIT(const char *c){strcpy(CUIT,c);}
        void setFechaInicio(Fecha i){fechaInicio=i;}
        void Mostrar();
        void Cargar();
        ~Cliente();
};

///CLASE ARCHIVO DE CLIENTES: PARA MANEJAR EL ARCHIVO DE CLIENTES
class ArchivoCliente{
private:
    char nombre[30];
public:
    ArchivoCliente(const char *n){
        strcpy(nombre, n);///ver que otras acciones ser�an interesantes
    }
    const char *getNombre(){ return nombre;}
    void setNombre(const char *n){strcpy(nombre,n);}

    int agregarRegistro();///ALTA

    int sobreEscribirRegistro(Cliente reg, int pos);

    int bajaLogica();///BAJA: LOGICA Y FISICA.
    ///int modificarRegistro();///MODIFICACION: CAMBIAR EL VALOR DE UNO O VARIOS CAMPOS
    void modificarEmail();
    bool listarArchivo();///LISTADO
    int buscarDNI(int d);
    Cliente leerRegistro(int pos);
    void mostrarPorFecha(Fecha aux);
    bool VaciarArchivo();
    Cliente buscarEnArchivoPedido();
    int getCantidadRegistros();
    Cliente almacenaRegistro (int dni);

};
