#include <iostream>
#include "ProductoManager.h"
#include "funciones.h"
#include "ProductoArchivo.h"
#include <iomanip>

using namespace std;
#include "funciones.h"


/*
Cargar
Editar
Listar todos
Listar x ID
*/
void ProductoManager::Cargar()
{
    system("cls");
	string descripcion;
	string nombre;
	int id;
	int dia, mes, anio;
	double precio;
	int stock;
Producto aux;
//ProductoArchivo aux1;
	id=1+_archivo.getCantidadRegistros();

cout<<"__________________________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"                                           CARGA DE PRODUCTO"<<endl;
cout<<"__________________________________________________________________________________________________________"<<endl;
cout<<endl;
	cout << "ID: "<<id<<endl;
	//cin >> id;

	cout << "Ingrese Nombre: ";
    //cin.ignore();
	getline(cin,nombre);
    //cin.ignore();
	cout << "Ingrese la Descripción del Producto: ";

	getline(cin,descripcion);

    cout << "Ingrese el precio: ";
	precio=getIntegerprecio(0,100000000);

    cout << "Ingrese el Stock: ";
	stock=getInteger(0,10000000000);


    aux.setID(id);
	aux.setnombre(nombre);
	aux.setDescripcion(descripcion);
	aux.setprecio(precio);
	aux.setstock(stock);


	if (_archivo.guardar(aux))
	{
		cout << "Producto guardada correctamente" << endl;
	}
	else
	{
		cout << "Ups! Algo salio mal :(" << endl;
	}


	system("pause");
	system("cls");
}

void ProductoManager::ListarTodos()
{
    system("cls");
	int cantidadRegistros = _archivo.getCantidadRegistros();

	for (int i = 0; i<cantidadRegistros; i++)
	{
		Producto reg = _archivo.leer(i);
		Listar(reg);
		cout << endl;
	}
	system("pause");

}

void ProductoManager::ListarXId()
{

	int id;

	cout << "Ingrese el ID: ";
	id=getInteger(1,1000000000);

	int posicion = _archivo.buscar(id);
	if (posicion >= 0)
	{
		Producto reg = _archivo.leer(posicion);
		Listar(reg);
	}
	else
	{
		cout << "No existe el registro con ID #" << id << endl;
	}
	system("pause");
	system("cls");
}
/*
void ProductoManager::Listar(Producto producto)
{
    cout << "-------------------------------------------------------"<< endl;
	cout << "ID          : " << producto.getID() << endl;
	cout << "Nombre      : " << producto.getnombre() << endl;
	cout << "Descripcion : " << producto.getDescripcion() << endl;
    cout << "Precio      : " << producto.getprecio() << endl;
    cout << "Stock       : " <<producto.getstock() << endl;
	cout << "Estado      : " << producto.getDescripcionEstado() << endl;
}
*/
void ProductoManager::Listar(Producto producto) {
   // cout <<"--------------------------------------------------------------------------------" << endl;
    cout <<  setw(5) << left << producto.getID();
    cout <<  setw(35) << left << producto.getnombre();
    cout <<  setw(35) << left << producto.getDescripcion();
    cout << setw(10) << left << producto.getprecio();
    cout << setw(10) << left << producto.getstock();
    //cout << setw(0) << left << "Estado:" << setw(10) << left << producto.getDescripcionEstado();
    cout<< endl<<"--------------------------------------------------------------------------------";
}

void ProductoManager::Editar()
{
    system("cls");
    Producto reg;
    int id, posicion;
    cout << "ID a buscar: ";
    cin >> id;
    cout << endl;

    cin.ignore(); // Descartar el carácter de salto de línea residual después de leer el ID

    posicion = _archivo.buscar(id);
    if (posicion >= 0)
    {
        reg = _archivo.leer(posicion);
        Listar(reg);
        cout << endl;

        string nuevonombre;
        cout << "Ingrese nuevo Nombre: ";
        getline(cin, nuevonombre);
        reg.setnombre(nuevonombre);
        _archivo.guardar(reg, posicion);

        string nuevodescrpcion;
        cout << "Ingrese nuevo Descripcion: ";
        getline(cin, nuevodescrpcion);
        reg.setDescripcion(nuevodescrpcion);
        _archivo.guardar(reg, posicion);

        double nuevoprecio;
        cout << "Ingrese nuevo Precio: ";
        nuevoprecio=getIntegerprecio(0,100000000);
        reg.setprecio(nuevoprecio);
        _archivo.guardar(reg, posicion);

        int nuevostock;
        cout << "Ingrese nuevo Stock: ";
        nuevostock=getInteger(0,100000000);
        reg.setstock(nuevostock);
        _archivo.guardar(reg, posicion);

        int nuevoEstado;
        cout << "Dar de Baja ingrese 0: ";
        nuevoEstado=getInteger(0,1);
        reg.setEstado(nuevoEstado);
        _archivo.guardar(reg, posicion);
    }
    else
    {
        cout << "No existe el registro con ID #" << id << endl;
    }
}

