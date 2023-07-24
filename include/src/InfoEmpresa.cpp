
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
#include "InfoEmpresa.h"
#include "Clientes.h"

void Pantalladeinicio(){

cout<<"___________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"                     BIENVENIDO A NUESTRO PROGRAMA DE GESTION"
<<endl;
cout<<endl;
cout<<"___________________________________________________________________________________"<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
system("pause");

}











void Empresa::Cargar(){
system("cls");
        cout<<"___________________________________________________________________"<<endl;
        cout<<endl;
        cout<<"                     DATOS DE LA EMPRESA"<<endl;
        cout<<endl;
        cout<<"___________________________________________________________________"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;

        cout<<"NOMBRE DE LA EMPRESA: ";
        cargarCadena(nombre, 24);
        cout<<endl;
        cout<<"DIRECCION DE LA EMPRESA: ";
        cargarCadena(direccion,30);
        cout<<endl;
        cout<<"TELEFONO DE LA EMPRESA: ";
        cargarCadena(telefono,15);
        cout<<endl;
        cout<<"CUIT DE LA EMPRESA: ";
        cargarCadena(cuit,15);
        cout<<endl;
        cout<<"EMAIL DE LA EMPRESA: ";
        cargarCadena(email,30);
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;




system("pause");

}



void Empresa::Mostrar(){
    //system("cls");


cout<<"_________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"               LA EMPRESA ESTA REGISTRADA A: "<<endl;
cout<<endl;
cout<<"__________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"NOMBRE DE LA EMPRESA: "<<nombre<<endl;

cout<<endl;
cout<<"DIRECCION DE LA EMPRESA: "<<direccion<<endl;

cout<<endl;
cout<<"TELEFONO DE LA EMPRESA: "<<telefono<<endl;

cout<<endl;
cout<<"CUIT DE LA EMPRESA: "<<cuit<<endl;
cout<<endl;
cout<<"EMAIL DE LA EMPRESA: "<<email<<endl;



system("pause");
}



int ArchivoEmpresa::getCantidadRegistros(){
    Empresa reg;
    FILE *p = fopen(nombre, "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Empresa);
}


int ArchivoEmpresa::agregarRegistro(){
    Empresa reg;
    FILE *pCliente;

	pCliente=fopen(nombre,"wb");///como queremos agregar registros usamos el modo ab

	if(pCliente==NULL){
		return -1;
	}

    reg.Cargar();///variable que contiene los datos que queremos llevar al disco

    int valor=fwrite(&reg, sizeof reg, 1,pCliente);
    fclose(pCliente);
    return valor;
}

bool ArchivoEmpresa::listarArchivo(){
    Empresa reg;
    FILE *pCliente;

	pCliente=fopen(nombre,"rb");
	if(pCliente==NULL){
		return false;
	}
    fread(&reg, sizeof reg, 1,pCliente);
        reg.Mostrar();



    fclose(pCliente);///cierra la conexi�n entre el programa y el archivo f�sico

    return true;

}





bool ArchivoEmpresa::VaciarArchivo(){
    char opc;
    cout<<"ESTA ACCION ELIMINARA LOS REGISTROS EXISTENTES EN EL ARCHIVO"<<endl;
    cout<<"ESTA SEGURO/A DE CONTINUAR: (S/N) ";
    cin>>opc;

    if(opc=='S' || opc=='s'){
        FILE *pCliente;

        pCliente=fopen(nombre,"wb");
        if(pCliente==NULL){
            return false;
        }
        fclose(pCliente);
        return true;
    }
    cout<<"EL ARCHIVO NO FUE MODIFICADO"<<endl;
    return true;
}

void menuprincipalEmpresa(){


 ArchivoEmpresa aux("empresa.dat");
    ///aux.VaciarArchivo();
    int opc;
    while(true){
        system("cls");
cout<<"_____________________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"                                       CONFIGURACION DE LA EMPRESA"<<endl;
cout<<"_____________________________________________________________________________________________________"<<endl;
cout<<"                              1 - CARGAR/EDITAR DATOS"<<endl;
cout<<"                              2 - MOSTRAR EMPRESA"<<endl;
cout<<"                              3 - ELIMINAR REGISTRO DE LA EMPRESA ARCHIVO"<<endl;
cout<<"                              4 - REPORTES"<<endl;
cout<<"                              0 - VOLVER"<<endl;           ///SI NO HAY UN REGISTRO CON ESE DNI INFORMARLO
cout<<"______________________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"                                    INGRESE UNA OPCION: ";
        cin>>opc;
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
            if(aux.listarArchivo()==false){
                cout<<"NO SE PUDO LISTAR EL ARCHIVO"<<endl;
            }
            break;
        case 3:
           aux.VaciarArchivo();
                break;
        case 4:
            //aux.modificarEmail();
                break;

        case 0:
            return;
            break;
        }
        cout<<endl;
        system("pause");




    }





}







