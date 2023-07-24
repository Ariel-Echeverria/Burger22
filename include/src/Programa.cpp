#include <iostream>
#include <cstdlib>

using namespace std;
#include "Programa.h"
#include "Clientes.h"
#include "Pedidos.h"
#include "InfoEmpresa.h"
#include "HerramientaInflacion.h"
#include "informes.h"
#include "funciones.h"


string Empresanombre;
void Programa::NombreEmpresa(){



cout<<endl;
cout<<"__________________________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"                          Hola bienvenido a nuestro programa de Gestion                                   "<<endl;
cout<<"__________________________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"                          Ingrese Nombre de la Empresa: ";
getline(cin, Empresanombre);


system("cls");
}






void Programa::ejecutar(){
calculoinflacionarreglo();
	int opcion;
	do{
system("cls");
cout<<endl;
cout<<"                                             "<<endl;
cout<<"___________________________________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"                                                MENU" << endl;
cout<<"___________________________________________________________________________________________________________________"<<endl;
cout<<"                                          1- PRODUCTOS " << endl;
cout<<"                                          2- CLIENTES" << endl;
cout<<"                                          3- PEDIDOS " << endl;
cout<<"                                          4- CONFIGURACION EMPRESA " << endl;
cout<<"                                          5- HERRAMIENTA INFLACION " << endl;
cout<<"                                          6- INFORMES " << endl;

cout<<"____________________________________________________________________________________________________________________"<<endl;
cout<<"                                          0- Salir" << endl << endl;

cout<<"                                          Opcion: ";
opcion=getInteger(0,6);
		switch(opcion){
		case 1:
			_productoMenu.Mostrar();
			break;
        case 2:
            menuprincipal();
            break;
        case 3:
            menuPedido();
            break;
        case 4:
           menuprincipalEmpresa();
            break;
             case 5:
           menuinflacion ();
            break;
           case 6:
           menuinforme();
            break;


		case 0:
			cout << "Gracias por utilizar nuestra aplicacion... :)" << endl;
		}
	}while (opcion != 0);
system("cls");
}

