#include <iostream>
#include <string>
#include <cstring>
#include "Producto.h"
using namespace std;
#include "funciones.h"
Producto::Producto(){
  _ID = 0;
  strcpy(_nombre, "");
  strcpy(_descripcion, "");
  _precio = 0;
  _stock = 0;
  _estado = 1;
}

Producto::Producto(int ID, string nombre, string descripcion, double precio, int stock,bool estado){
   _ID = ID;
   strcpy(_nombre, nombre.c_str());
   strcpy(_descripcion, descripcion.c_str());
   _precio = precio;
   _stock = stock;
   _estado = estado;
}

int Producto::getID(){
   return _ID;
}
std::string Producto::getnombre(){
   std::string nombre;
   nombre = _nombre;
   return nombre;
}
std::string Producto::getDescripcion(){
   std::string descripcion;
   descripcion = _descripcion;
   return descripcion;

}
double Producto::getprecio(){
   return _precio;
}
int Producto::getstock(){
   return _stock;
}


std::string Producto::getDescripcionEstado(){

   if (_estado){
      return "Activo";
   }
   return "Baja";
}






void Producto::setID(int ID){
   _ID = ID;
}
void Producto::setnombre(std::string nombre) {
    strncpy(_nombre, nombre.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';  // Asegurar terminación nula
}

void Producto::setDescripcion(std::string descripcion) {
    strncpy(_descripcion, descripcion.c_str(), sizeof(_descripcion) - 1);
    _descripcion[sizeof(_descripcion) - 1] = '\0';  // Asegurar terminación nula
}


void Producto::setprecio(double precio){
   _precio = precio;
}

void Producto::setstock(int stock){
   _stock = stock;
}
void Producto::setEstado(bool estado){
   _estado = estado;

}
