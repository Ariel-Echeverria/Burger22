#pragma once
#include "Producto.h"
#include "Fecha.h"
#include <string>

class Producto
{
private:
  int _ID;
  char _nombre[30];
  char _descripcion[30];
  double _precio;
  int _stock;
  bool _estado;

public:
  Producto();
  Producto(int ID,std::string nombre ,std::string descripcion, double precio, int stock ,bool estado=0);


  int getID();
  std::string getnombre();
  std::string getDescripcion();
  double getprecio();
  int getstock();
  std::string getDescripcionEstado();

  void setID(int ID);
  void setnombre(std::string nombre);
  void setDescripcion(std::string descripcion);
  void setprecio(double precio);
  void setstock(int stock);
  void setEstado(bool estado);
};
