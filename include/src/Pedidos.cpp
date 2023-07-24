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
#include "funciones.h"

#include <ctime>

Pedido ArchivoPedido::leerRegistro(int pos)
{
    Pedido aux;
    FILE *p = fopen("pedidos.dat", "rb");
    if (p == NULL)
    {
        return aux;
    }

    fseek(p, pos * sizeof(Pedido), SEEK_SET);
    fread(&aux, sizeof(Pedido), 1, p);
    fclose(p);
    return aux;
}






bool ArchivoPedido::guardar(Pedido reg, int posicionAReemplazar)
{
    FILE *p = fopen("pedidos.dat", "rb+");

    if (p == NULL)
    {
        return false;
    }

    fseek(p, posicionAReemplazar * sizeof(Pedido), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Pedido), 1, p);
    fclose(p);
    return pudoEscribir;
}






void ArchivoPedido::cocinadoyenvio(){
    int buscar;
    int envio=0;
    int cocinado=0;
    bool encontro=false;

     system("cls");
    cout<<"___________________________________________________________________________________"<<endl;
    cout<<"                    CONFIRMACION DE PREPARADO Y ENVIO DE PEDIDOS"<<endl;
    cout<<"___________________________________________________________________________________"<<endl;
    cout<<endl;
ArchivoPedido aux("pedidos.dat");
Pedido reg;
int contopedido=aux.getCantidadRegistros();
for(int i=0; i<contopedido; i++){
    if(aux.leerRegistro(i).isEnviado()==0){
       reg=aux.leerRegistro(i);
       reg.Mostrar();
    }

}


    cout<<" INGRESE EL ID A BUSCAR: ";
    buscar=getInteger(1,1000000);

reg=aux.leerRegistro(buscar-1);
reg.Mostrar();
do{

 std::cout << "INGRESE 1 SI YA TIENE EL PEDIDO: ";
        cocinado=getInteger(0,1);
        if(cocinado==1){
            reg.setRecibido(cocinado);
        }

    } while (cocinado != 1);
cout<<endl;
      do{
        std::cout << "INGRESE 1 SI YA ENVIO EL PEDIDO: ";
        envio=getInteger(0,1);
if(envio==1){
    reg.setEnviado(envio);
}

    } while (envio != 1);


aux.guardar(reg,buscar-1);

}


void ArchivoPedido::modificarpedido(int buscar){

      Pedido reg;
         int envio=0;
    int cocinado=0;

	 FILE *pCliente;
    int pos=0;

	pCliente=fopen("pedidos.dat","rb");
	if(pCliente==NULL){
		return;
	}
    while(fread(&reg, sizeof reg, 1,pCliente)==1){
        if(reg.getNumero()==buscar){

            fclose(pCliente);
            reg.Mostrar();
            return;
        }





        if(reg.getNumero()==buscar){

        do{
        std::cout << "¿SI YA COCINO EL PEDIDO INGRESE 1: ";
        std::cin >> cocinado;
        if(cocinado==1){
            reg.setRecibido(cocinado);
        }
    } while (cocinado != 1);

      do{
        std::cout << "¿SI YA ENVIO EL PEDIDO INGRESE 1: ";
        std::cin >> envio;
if(envio==1){
    reg.setEnviado(envio);
}

    } while (envio != 1);

fseek(pCliente, buscar*sizeof (Pedido), 0);
fwrite(&reg, sizeof reg, 1,pCliente);
    fclose(pCliente);
    return;


            fclose(pCliente);

            return;
        }

    }
}






int ArchivoPedido::getCantidadRegistros()
{
    FILE *p = fopen("Pedidos.dat", "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Pedido);
}
int ArchivoPedido::menubuscarpedido(){
    int buscar;
     system("cls");

    cout<<"___________________________________________________________________________________"<<endl;
    cout<<"                              BUSCADOR DE PEDIDOS"<<endl;
    cout<<"___________________________________________________________________________________"<<endl;
    cout<<endl;
    cout<<" INGRESE EL ID A BUSCAR: ";
    buscar=getInteger(1,1000000);


    buscarPedido(buscar);


}


int ArchivoPedido::buscarPedido(int d){
    Pedido reg;
    FILE *pCliente;
    int pos=0;

	pCliente=fopen("pedidos.dat","rb");
	if(pCliente==NULL){
		return -2;
	}
    while(fread(&reg, sizeof reg, 1,pCliente)==1){
        if(reg.getNumero()==d){

            fclose(pCliente);
            reg.Mostrar();
            return pos;
        }

        pos++;
    }
cout<<"                              NO SE ENCONTRO EL PEDIDO";
    fclose(pCliente);
    return -1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
void Pedido::Cargar() {
    ArchivoPedido archivoPedido("pedidos.dat");

    int id = 0;
    int busDNI;
    int busID;
    Reloj relojActual;
    int horas1 = relojActual.getHoras();
    int minutos1 = relojActual.getMinutos();
    id = 1 + archivoPedido.getCantidadRegistros();
    setNumero(id);


    cout << "___________________________________________________________________________________" << endl;
    cout << "                              GESTION DE PEDIDOS" << endl;
    cout << "___________________________________________________________________________________" << endl;
    cout << endl;

    cout << "Numero de Pedido: " << id << endl;
    cout << "Fecha: ";
    FechaPedido.obtenerFechaHoraActual();
    cout << "Hora del pedido: " << horas1 << ":" << minutos1 << endl;
    setFechaPedido(FechaPedido);
    // Buscar cliente por DNI
    ArchivoCliente archivoCliente("clientes.dat");
    ClientePedido = archivoCliente.buscarEnArchivoPedido();
    ArchivoDetalle archivoDetalle("Detalle.dat");
    Detalle ProductoPedido;

    double acumulo=0;
    ProductoManager _productoManager;
    _productoManager.ListarTodos();

    int numProductos = 0;

    int respuesta;
    do {
        int busID;
        std::cout << "Elija un producto ID y con el 0 'cero' salis: ";
        busID=getInteger(0,1000000);
        respuesta = busID;
        if (respuesta != 0) {
            // Supongamos que tienes una función llamada "buscar" en la clase "ProductoArchivo" que busca el producto por ID
            ProductoArchivo PedArc("Productos.dat");
            Producto producto = PedArc.leer(PedArc.buscar(busID));
            ProductoPedido.setProductoPedido(producto);
            ProductoPedido.setID(id);
            ProductoPedido.setClientePedido(ClientePedido);
            ProductoPedido.setFechaPedido(FechaPedido);
            ProductoPedido.setHoraPedido(relojActual);
            archivoDetalle.agregarRegistro(ProductoPedido);
            acumulo+=producto.getprecio();

            numProductos++;
        }
    } while (respuesta != 0);
        setTotal(acumulo);
    // Mostrar los productos agregados
        int contoDetalle = archivoDetalle.getCantidadRegistros();

   for(int i=0; i<contoDetalle; i++){
        if(archivoDetalle.leer(i).getNumero()== id){
        Detalle detalle = archivoDetalle.leer(i);
        detalle.Mostrar(detalle);
        }
   }
}

///////////////





int ArchivoPedido::agregarRegistro(){
    Pedido reg;
    FILE *pCliente;

	pCliente=fopen("pedidos.dat","ab");///como queremos agregar registros usamos el modo ab

	if(pCliente==NULL){
		return -1;
	}

    reg.Cargar();///variable que contiene los datos que queremos llevar al disco
    reg.Mostrar();

    int valor=fwrite(&reg, sizeof reg, 1,pCliente);
    fclose(pCliente);
    return valor;
}

void menuPedido(){
    ArchivoPedido aux("Pedidos.dat");
    int opc;

    while(true){
        system("cls");
        cout<<"_____________________________________________________________________________________________________"<<endl;
        cout<<endl;
        cout<<"                                       CARGAR UN PEDIDO"<<endl;
        cout<<"_____________________________________________________________________________________________________"<<endl;
        cout<<"                                        1 - CARGAR ORDENES "<<endl;
        cout<<"                                        2 - MOSTRAR TODO"<<endl;
        cout<<"                                        3 - BUSCAR PEDIDO"<<endl;
        cout<<"                                        4 - PREPARADO Y ENVIO "<<endl;
        cout<<"                                        0 - VOLVER"<<endl;
        cout<<"_____________________________________________________________________________________________________"<<endl;
	cout<<endl;
        cout<<"                                       INGRESE UNA OPCION: ";
        opc=getInteger(0,4);
        system("cls");
        switch(opc){
            case 1:
                if(aux.agregarRegistro()!=1){
                    cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                }
                else{
                    cout<<"REGISTRO AGREGADO"<<endl;
                }
                break;
            case 2:
                aux.listarArchivo();
                break;
            case 3:
               aux.menubuscarpedido();
                break;
            case 4:
                aux.cocinadoyenvio();
                break;
            case 5:
                // aux.modificarEmail();
                break;
            case 0:
                return;
                break;
        }
        cout<<endl;
        system("pause");
    }
}

void Pedido::Mostrar() {
ArchivoDetalle archivoDetalle("Detalle.dat");
   cout << "________________________________________________________________________" << endl;
    cout<<"                                       PEDIDO"<<endl;
   cout << "________________________________________________________________________" << endl;
    cout << "Numero de Pedido: " << numero << endl;
    cout << "Fecha: ";
    FechaPedido.Mostrar(); // Asumiendo que tienes un método "mostrarFecha" en la clase Fecha
    cout << "Hora del pedido: " << HoraPedido.getHoras() << ":" << HoraPedido.getMinutos() << endl;
    cout << "Cliente: " << ClientePedido.getNombre() << " " << ClientePedido.getApellido() << endl;
   double acumu=0;

    int contoDetalle = archivoDetalle.getCantidadRegistros();
    std::cout <<


              std::setw(50)<< left << "Nombre Producto "
              << std::setw(50)<< left <<"Precio: "

              << std::endl;
   for(int i=0; i<contoDetalle; i++){
        if(archivoDetalle.leer(i).getNumero()== numero){
        Detalle detalle = archivoDetalle.leer(i);
        acumu+=detalle.getProductoPedido().getprecio();
        detalle.Mostrar(detalle);

        }
   }

    cout << "Total: " << acumu << endl;
    cout << "Enviado: " << (Enviado ? "Si" : "No") << endl;
    cout << "Recibido: " << (Recibido ? "Si" : "No") << endl;
}


bool ArchivoPedido::listarArchivo(){
    Pedido reg;
    FILE *pCliente;

	pCliente=fopen("pedidos.dat","rb");
	if(pCliente==NULL){
		return false;
	}
    while(fread(&reg, sizeof reg, 1,pCliente)==1){
        reg.Mostrar();
        cout<<endl;
    }

    fclose(pCliente);///cierra la conexi�n entre el programa y el archivo f�sico

    return true;

}
