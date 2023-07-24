#pragma once

# include<iostream>
# include<cstdlib>
# include<cstring>

void Pantalladeinicio();

void pantallaEmpresa();

void menuprincipalEmpresa();

class Empresa {
private:
    char nombre[30];
    char direccion[30];
    char telefono[15];
    char cuit[30];
    char email[30];
    bool activo;

public:
    Empresa() {
        strcpy(nombre, "");
        strcpy(direccion, "");
        strcpy(telefono, "");
        strcpy(cuit, "");
        strcpy(email, "");
        activo = false;
    }

    // Getters
    const char* getNombre() const {
        return nombre;
    }

    const char* getDireccion() const {
        return direccion;
    }

    const char* getTelefono() const {
        return telefono;
    }

    const char* getCuit() const {
        return cuit;
    }

    const char* getEmail() const {
        return email;
    }

    bool getActivo() const {
        return activo;
    }

    // Setters
    void setNombre(const char* nuevoNombre) {
        strcpy(nombre, nuevoNombre);
    }

    void setDireccion(const char* nuevaDireccion) {
        strcpy(direccion, nuevaDireccion);
    }

    void setTelefono(const char* nuevoTelefono) {
        strcpy(telefono, nuevoTelefono);
    }

    void setCuit(const char* nuevoCuit) {
        strcpy(cuit, nuevoCuit);
    }

    void setEmail(const char* nuevoEmail) {
        strcpy(email, nuevoEmail);
    }

    void setActivo(bool nuevoActivo) {
        activo = nuevoActivo;
    }

    void Cargar();
    void Mostrar();






};


///
class ArchivoEmpresa{
private:
    char nombre[30];
public:
    ArchivoEmpresa(const char *n){
        strcpy(nombre, n);
    }
    const char *getNombre(){ return nombre;}
    void setNombre(const char *n){strcpy(nombre,n);}

    int agregarRegistro();
    bool listarArchivo();
    bool VaciarArchivo();
    int getCantidadRegistros();
};



