#include<iostream>
#include<cstdlib>
#include<cstring>
#include <iomanip>

using namespace std;
#include "Pedidos.h"
#include "Fecha.h"
#include "ProductoArchivo.h"
#include "ProductoManager.h"
#include "Detalle.h"
#include "informes.h"
#include "funciones.h"

void menuinforme(){

int opcion;
	do{
system("cls");
cout<<endl;

cout<<"___________________________________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"                                            MENU INFORME" << endl;
cout<<"___________________________________________________________________________________________________________________"<<endl;
cout<<"                                          1- PRODUCTOS MAS VENDIDOS " << endl;
cout<<"                                          2- CLIENTES QUE MAS COMPRO" << endl;
cout<<"                                          3- FILTRAR POR MES " << endl;
cout<<"                                          4- TOTAL VENTAS ANUAL " << endl;
cout<<"                                                                                                                   "<< endl;

cout<<"____________________________________________________________________________________________________________________"<<endl;
cout<<"                                          0- Salir" << endl << endl;

cout<<"                                          Opcion:";
opcion=getInteger(0,4);

		switch(opcion){
		case 1:
			informeProductomasvendido();
			break;
        case 2:
            informeclientequemascompro();
            break;
        case 3:
            informeperiodomes();
            break;
        case 4:
           informetotalanual();
            break;




			cout << "Gracias por utilizar nuestra aplicacion... :)" << endl;
		}
	}while (opcion != 0);
system("cls");










}

void informeProductomasvendido() {
    system("cls");
    ArchivoDetalle archivoDetalle("Detalle.dat");
    ProductoArchivo productoArchivo;
    int contoProducto = productoArchivo.getCantidadRegistros();
    int contoArchivoDetalle = archivoDetalle.getCantidadRegistros();

    int *contadorProductos = new int[contoProducto];
    int *contadorProductosIndice = new int[contoProducto];

    if (contadorProductos == nullptr || contadorProductosIndice == nullptr) {
        cout << "No se pudo asignar memoria dinámica!!!" << endl;
        return;
    }

    for (int i = 0; i < contoProducto; i++) {
        contadorProductos[i] = 0;
        contadorProductosIndice[i] = i; // Inicializar con los índices iniciales
    }

    for (int i = 0; i < contoArchivoDetalle; i++) {
        Detalle detalle = archivoDetalle.leer(i);
        Producto producto = detalle.getProductoPedido();
        contadorProductos[producto.getID() - 1]++;
    }

    for (int i = 0; i < contoProducto - 1; i++) {
        for (int x = i + 1; x < contoProducto; x++) {
            if (contadorProductos[i] > contadorProductos[x]) {
                int aux = contadorProductos[i];
                contadorProductos[i] = contadorProductos[x];
                contadorProductos[x] = aux;


                int auxIndice = contadorProductosIndice[i];
                contadorProductosIndice[i] = contadorProductosIndice[x];
                contadorProductosIndice[x] = auxIndice;
            }
        }
    }

    cout << "RANKING DE PRODUCTOS MAS VENDIDOS" << endl;
    for (int i = contoProducto - 1; i >= 0; i--) {  // Imprimir en orden descendente
        int indiceProducto = contadorProductosIndice[i];
        cout << contoProducto - i << ") " << productoArchivo.leer(indiceProducto).getnombre() << endl;
    }

    delete[] contadorProductos;
    delete[] contadorProductosIndice;
    system("pause");
}
//////////
void informeclientequemascompro() {
    system("cls");
    ArchivoCliente archivoCliente("cliente.dat");
    ArchivoPedido archivoPedido("pedidos.dat");
    int contoCliente = archivoCliente.getCantidadRegistros();
    int contoPedidos = archivoPedido.getCantidadRegistros();
    const int DNI = 2;

    int **clientesContados = new int*[contoCliente];
    for (int i = 0; i < contoCliente; i++){
            clientesContados[i] = new int[DNI];


    }

    for (int i = 0; i < contoCliente; i++) {
        clientesContados[i][0] = 0;
        Cliente cliente = archivoCliente.leerRegistro(i);
        clientesContados[i][1] = cliente.getDNI();
    }

    for (int i = 0; i <contoCliente; i++) {

        //Cliente cliente = archivoPedido.leerRegistro(i).getClientePedido();
        for (int a = 0; a < contoPedidos; a++) {

        Pedido pedido = archivoPedido.leerRegistro(a);
        //cout<<pedido.getClientePedido().getDNI()<<endl;
        //cout<<clientesContados[i][1]<<endl;
            if (clientesContados[i][1] == pedido.getClientePedido().getDNI()) {
                clientesContados[i][0]++;
            }
        }
    }

    for (int i = 0; i < contoCliente - 1; i++) {
        int aux = clientesContados[i][0];
        int auxIndice = clientesContados[i][1];

        for (int x = i + 1; x < contoCliente - 1; x++) {
            if (aux < clientesContados[x][0]) {
                clientesContados[i][0] = clientesContados[x][0];
                clientesContados[i][1] = clientesContados[x][1];
                clientesContados[x][0] = aux;
                clientesContados[x][1] = auxIndice;
                aux = clientesContados[i][0];
                auxIndice = clientesContados[i][1];
            }
        }
    }

        cout << "RANKING CLIENTES QUE MAS COMPRARON" << endl;
    for (int i=0 ;  i<contoCliente;  i++) {  // Imprimir en orden descendente
        int indiceCliente = clientesContados[i][1];
        Cliente auxiliar ;
        auxiliar = archivoCliente.almacenaRegistro(indiceCliente) ;
        cout <<  i +1 << ") " <<indiceCliente<<"  "<<auxiliar.getNombre()<<" "<<auxiliar.getApellido()<<endl;
    }




//cout<<"llego";



    for (int i = 0; i<contoCliente; i++){
        delete[] clientesContados[i];
    }
    delete[] clientesContados;



system("pause");


}

void informeperiodomes(){
system("cls");

ArchivoPedido archivoPedido("pedidos.dat") ;
ArchivoCliente ArchivoCliente("clientes.dat") ;
double totalVentas = 0.0 ;
int cantidadVentas = 0 ;
Fecha fecha, fecha2;

int mes;
int contoPedido= archivoPedido.getCantidadRegistros();

cout<<"IMFORME DE VENTA MESUAL: "<<endl;
cout<<endl;
cout<<"Ingrese el mes que desea saber: ";
cin>>mes;

for (int i = 0 ; i<contoPedido; i++){
if( archivoPedido.leerRegistro(i).getFechaPedido().getMes() == mes )
totalVentas += archivoPedido.leerRegistro(i).getTotal() ;
cantidadVentas ++;
}

std::cout<<"El total de ventas de este mes es de : "<<cantidadVentas<<" por $"<<totalVentas<<std::endl;


system("pause");




}
void informetotalanual(){
system("cls");
   ArchivoPedido archivoPedido("pedidos.dat");
   int contoPedidos = archivoPedido.getCantidadRegistros();
   double acumulo=0;
   int anio;
   cout<<"INFORME ANUAL"<<endl;
   cout<<endl;
   cout<<"Ingrese el año para el total: ";
   cin>>anio;

   for(int i=0; i<contoPedidos; i++){
    if(archivoPedido.leerRegistro(i).getFechaPedido().getAnio()==anio){
            //cout<<"llego"<<archivoPedido.leerRegistro(i).getTotal()<<endl;

        acumulo+=archivoPedido.leerRegistro(i).getTotal();
    }


   }

   cout<<"El total del año Facturado fue: "<<acumulo<<endl;



system("pause");









}
