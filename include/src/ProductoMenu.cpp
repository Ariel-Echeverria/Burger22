
#include <iostream>
using namespace std;
#include "ProductoMenu.h"
#include "funciones.h"

void ProductoMenu::Mostrar()
{

    int opcion;
    do
    {
         system("cls");
        Producto reg;

cout<<"_______________________________________________________________________________________________________" << endl;
cout << endl;
cout<<"                                     MENU PRODUCTOS"<<endl;
cout<<"_______________________________________________________________________________________________________" << endl;
cout<<"                                1. CARGAR UN PRODUCTO" << endl;
cout<<"                                2. EDITAR" << endl;
cout<<"                                3. LISTAR TODOS" << endl;
cout<<"                                4. LISTAR POR ID" << endl;
cout<<endl;
cout<<"                                0. SALIR" << endl;
cout<<"________________________________________________________________________________________________________" << endl;
cout << endl;
 cout<< "INGRESE OPCION: ";
opcion=getInteger(0,4);

        switch(opcion)
        {
        case 1:
            _productoManager.Cargar();
            break;
        case 2:
			_productoManager.Editar();
            break;
        case 3:
			_productoManager.ListarTodos();
            break;
        case 4:
			_productoManager.ListarXId();
            break;
        }

    }
    while(opcion != 0);
}
