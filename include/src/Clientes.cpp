# include<iostream>
# include<cstdlib>
# include<cstring>
#include "Clientes.h"
#include "Fecha.h"
#include <string>
#include "funciones.h"

using namespace std;



void cargarCadena(char *pal, int tam) {
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++) {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

///

void Cliente::Mostrar(){
    if(estado==true){
                Persona::Mostrar();
                cout<<"CUIT "<<CUIT<<endl;
                //cout<<"FECHA DE INICIO"<<endl;
               // fechaInicio.Mostrar();
            }
}

        void Cliente::Cargar(){
            Persona::Cargar();
            cout<<"CUIT: ";
            cargarCadena(CUIT,11);
           // cout<<"FECHA DE INICIO"<<endl;
           // fechaInicio.Cargar();
        }

Cliente::~Cliente(){
            ///se ejecuta cuando el objeto cae fuera de su �mbito
           /// cout<<"CHAU OBJETO!!!!"<<endl;
}









Fecha Persona::getFechaNacimiento(){
        return fechaNacimiento;
}

void Persona::Cargar(){
    cout<<"DNI: ";
    cin>>DNI;
    cout<<"Fecha Nacimiento: "<<endl;
    fechaNacimiento.Cargar();
    cout<<"Nombre: ";
    cargarCadena(nombre, 24);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,24);
    cout<<"EMAIL: ";
    cargarCadena(email, 24);
    cout<<"TELEFONO: ";
    cargarCadena(telefono, 19);
    estado=true;
}

void Persona::Mostrar(){
    if(estado==true){
        cout<<"DNI: ";
        cout<<DNI<<endl;
///cout<<"Fecha Nacimiento: "<<endl;
///        fechaNacimiento.Mostrar();
        cout<<"Nombre: ";
        cout<<nombre<<endl;
        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
        cout<<"EMAIL: ";
        cout<<email<<endl;
        cout<<"TELEFONO: ";
        cout<<telefono<<endl;
    }

}




int ArchivoCliente::agregarRegistro(){
    Cliente reg;
    FILE *pCliente;

	pCliente=fopen(nombre,"ab");///como queremos agregar registros usamos el modo ab

	if(pCliente==NULL){
		return -1;
	}

    reg.Cargar();///variable que contiene los datos que queremos llevar al disco

    int valor=fwrite(&reg, sizeof reg, 1,pCliente);
    fclose(pCliente);
    return valor;
}
Cliente ArchivoCliente::almacenaRegistro (int dni){


    ArchivoCliente obj("cliente.dat");
    Cliente reg;

    int pos=obj.buscarDNI(dni);
    if(pos==-1){
        cout<<"NO EXISTE UN CLIENTE CON ESE DNI"<<endl;

    }
    reg=obj.leerRegistro(pos);

    return reg ;

}



int ArchivoCliente::bajaLogica(){
    ///buscar
    int DNI, pos;
    cout<<"INGRESE EL DNI DEL CLIENTE A BORRAR ";
    cin>>DNI;
    pos=buscarDNI(DNI);
    if(pos==-1){
         cout<<"NO HAY CLIENTES CON ESE DNI"<<endl;
         return -1;
    }
    ///leer
    Cliente reg;
    reg=leerRegistro(pos);
    ///cambiar estado
    reg.setEstado(false);

    ///sobreescribir el registro
    sobreEscribirRegistro(reg, pos);

    return 1;
}///BAJA: LOGICA Y FISICA.


int ArchivoCliente::sobreEscribirRegistro(Cliente reg, int pos){
    FILE *pCliente;

	pCliente=fopen(nombre,"rb+");///como queremos agregar registros usamos el modo ab

	if(pCliente==NULL){
		return -1;
	}
    fseek(pCliente, pos*sizeof (Cliente), 0);
    int valor=fwrite(&reg, sizeof reg, 1,pCliente);
    fclose(pCliente);
    return valor;
}
/*
int ArchivoCliente::modificarEmail(){




    return 1;
}///MODIFICACION: CAMBIAR EL VALOR DE UNO O VARIOS CAMPOS
*/
bool ArchivoCliente::listarArchivo(){
    Cliente reg;
    FILE *pCliente;

	pCliente=fopen(nombre,"rb");
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
/*
void ArchivoCliente::buscarDNIpedido(int d){
    Cliente reg;
    FILE *pCliente;
    int pos=0;

	pCliente=fopen(nombre,"rb");
	if(pCliente==NULL){
		C
	}
    while(fread(&reg, sizeof reg, 1,pCliente)==1){
        if(reg.getDNI()==d){
            fclose(pCliente);
            return pos;
        }
        pos++;
    }

    fclose(pCliente);
    return reg;
}
*/
int ArchivoCliente::buscarDNI(int d){
    Cliente reg;
    FILE *pCliente;
    int pos=0;

	pCliente=fopen(nombre,"rb");
	if(pCliente==NULL){
		return -2;
	}
    while(fread(&reg, sizeof reg, 1,pCliente)==1){
        if(reg.getDNI()==d){
            fclose(pCliente);
            return pos;
        }
        pos++;
    }

    fclose(pCliente);
    return -1;
}


void ArchivoCliente::mostrarPorFecha(Fecha aux){
    Cliente reg;
    FILE *pCliente;

	pCliente=fopen(nombre,"rb");
	if(pCliente==NULL){
		return;
	}
    while(fread(&reg, sizeof reg, 1,pCliente)==1){
        if(reg.getFechaInicio().getDia()==aux.getDia())
            if(reg.getFechaInicio().getMes()==aux.getMes())
                if(reg.getFechaInicio().getAnio()==aux.getAnio())
                    reg.Mostrar();
    }

    fclose(pCliente);

}

bool ArchivoCliente::VaciarArchivo(){
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

/*Cliente ArchivoCliente::leerRegistro(int posP){
    Cliente reg;
    reg.setDNI(-2);
    FILE *pCliente;
    int pos=0;

	pCliente=fopen(nombre,"rb");
	if(pCliente==NULL){
		return reg;
	}
    while(fread(&reg, sizeof reg, 1,pCliente)==1){
        if(pos==posP){
            fclose(pCliente);
            return reg;
        }
        pos++;
    }

    fclose(pCliente);
    reg.setDNI(-3);
    return reg;

}*/


Cliente ArchivoCliente::leerRegistro(int posP){
    Cliente reg;
    reg.setDNI(-2);
    FILE *pCliente;

	pCliente=fopen(nombre,"rb");
	if(pCliente==NULL){
		return reg;
	}
    fseek(pCliente,posP*sizeof reg,0);
    ///fseek(puntero FILE sobre el que se abrio el archivo, cantidad de bytes a desplazarse, desde donde desplazarse)
    ///desde donde 0 SEEK_SET el desplazamiento va desde el principio del archivo
    ///desde donde 1 SEEK_CUR el desplazamiento va desde donde se encuentra de indicardor del punto FILE
    ///desde donde 2 SEEK_END el desplazamiento va desde el FINAL del archivo
    FILE *pCli=pCliente;
    int leyo=fread(&reg, sizeof reg, 1, pCli);
    fclose(pCliente);
    if(leyo==0)reg.setDNI(-3);
    return reg;

}
void menuprincipal(){


 ArchivoCliente aux("cliente.dat");
    ///aux.VaciarArchivo();
    int opc;
    while(true){
        system("cls");
cout<<"_____________________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"                                       CARGA DE LOS CLIENTES"<<endl;
cout<<"_____________________________________________________________________________________________________"<<endl;
cout<<"                              1 - CARGAR REGISTRO DE CLIENTE EN ARCHIVO"<<endl;
cout<<"                              2 - MOSTRAR ARCHIVO CLIENTES"<<endl;
cout<<"                              3 - BUSCAR CLIENTE EN EL ARCHIVO"<<endl;///LA FUNCI�N TIENE QUE PEDIR UN DNI Y MOSTRAR EL REGISTRO QUE CONTIENE ESE DNI
cout<<"                              4 - ELIMINAR REGISTRO DE CLIENTE EN EL ARCHIVO"<<endl;
cout<<"                              5 - MODIFICAR EL EMAIL DE CLIENTE EN EL ARCHIVO"<<endl;
cout<<"                              0 - VOLVER"<<endl;           ///SI NO HAY UN REGISTRO CON ESE DNI INFORMARLO
cout<<"______________________________________________________________________________________________________"<<endl;
cout<<endl;
cout<<"                                    INGRESE UNA OPCION: ";
        opc=getInteger(0,5);
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
        case 3: buscarEnArchivo();
                break;
        case 4: aux.bajaLogica();
                break;
        case 5: aux.modificarEmail();
                break;
        case 0:
            return;
            break;
        }
        cout<<endl;
        system("pause");




    }





}
Cliente ArchivoCliente::buscarEnArchivoPedido(){
    int DNI;
    ArchivoCliente obj("cliente.dat");
    Cliente reg;
    cout<<"INGRESE EL DNI DEL CLIENTE A BUSCAR ";
    cin>>DNI;
    int pos=obj.buscarDNI(DNI);
    if(pos==-1){
        cout<<"NO EXISTE UN CLIENTE CON ESE DNI"<<endl;
        //return ;
    }
    reg=obj.leerRegistro(pos);
    //reg.Mostrar();
    return reg;
}

int ArchivoCliente::getCantidadRegistros()
{
    FILE *p = fopen(nombre, "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Cliente);
}


void ArchivoCliente::modificarEmail() {
    ArchivoCliente archivoCliente("cliente.dat");
    Cliente aux;
   char email[25];
    int dni, id;

    cout << "MODIFICAR EMAIL" << endl;
    archivoCliente.listarArchivo();

    cout << "Ingrese el DNI a modificar: ";
    cin >> dni;

    id = archivoCliente.buscarDNI(dni);
    if (id == -1) {
        cout << "No se encontró un cliente con el DNI ingresado." << endl;
        return;
    }

    aux = archivoCliente.leerRegistro(id);

    cin.ignore(); // Ignorar el salto de línea pendiente del ingreso anterior

    cout << "Ingrese el email nuevo: ";
    cargarCadena(email,25);

    aux.setEmail(email);

    archivoCliente.sobreEscribirRegistro(aux, id);

    cout << "Se guardo el nuevo email: " << archivoCliente.leerRegistro(id).getEmail() << endl;
}



void buscarEnArchivo(){
    int DNI;
    ArchivoCliente obj("cliente.dat");
    Cliente reg;
    cout<<"INGRESE EL DNI DEL CLIENTE A BUSCAR ";
    cin>>DNI;
    int pos=obj.buscarDNI(DNI);
    if(pos==-1){
        cout<<"NO EXISTE UN CLIENTE CON ESE DNI"<<endl;
        return;
    }
    reg=obj.leerRegistro(pos);
    reg.Mostrar();
}
