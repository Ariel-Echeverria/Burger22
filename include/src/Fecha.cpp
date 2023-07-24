#include <iostream>
#include <string>
#include <ctime>
using namespace std;
#include "Fecha.h"
void Fecha::obtenerFechaHoraActual() {
  std::time_t ahora = std::time(nullptr);
  std::tm* fechaHora = std::localtime(&ahora);

  int anio=fechaHora->tm_year + 1900;
  int mes=fechaHora->tm_mon + 1;
  int dia=fechaHora->tm_mday;
  cout<<dia<<" "<<mes<<" "<<anio<<endl;
/*
  hora = fechaHora->tm_hour;
  minuto = fechaHora->tm_min;
  segundo = fechaHora->tm_sec;
  */
  _dia=dia;
  _mes=mes;
  _anio=anio;



}



 void Fecha::Cargar(){
    cout<<"DIA: ";
    cin>>_dia;
    cout<<"MES: ";
    cin>>_mes;
    cout<<"ANIO: ";
    cin>>_anio;
}

int Fecha::diferenciaDias(Fecha aux) {
   Fecha actual;
   actual.obtenerFechaHoraActual();

   // Convertir ambas fechas a time_t
   std::tm fecha1 = {0};
   fecha1.tm_year = actual.getAnio() - 1900;
   fecha1.tm_mon = actual.getMes() - 1;
   fecha1.tm_mday = actual.getDia();
   std::time_t time1 = std::mktime(&fecha1);

   std::tm fecha2 = {0};
   fecha2.tm_year = aux.getAnio() - 1900;
   fecha2.tm_mon = aux.getMes() - 1;
   fecha2.tm_mday = aux.getDia();
   std::time_t time2 = std::mktime(&fecha2);

   // Calcular la diferencia en segundos
   std::time_t diferencia = std::difftime(time2, time1);

   // Calcular la diferencia en d�as
   int diferenciaDias = static_cast<int>(diferencia) / (60 * 60 * 24);

   return diferenciaDias;
}







void Fecha::Mostrar(){
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}


void Fecha::establecerFechaPorDefecto(){
   _dia = 1;
   _mes = 1;
   _anio = 1900;
}

bool Fecha::esBisiesto(){
    if ((_anio % 4 == 0 && _anio % 100 != 0) || _anio % 400 == 0){
      return true;
    }
    return false;
}

void Fecha::agregarDia(){
   int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   if (esBisiesto()){
      dias[1]++;
   }

   _dia++;
   if (_dia > dias[_mes-1]){
      _dia = 1;
      _mes++;
      if (_mes > 12){
         _mes = 1;
         _anio++;
      }
   }
}

void Fecha::agregarDias(int cantidadDias){

   if (cantidadDias > 0){
      for(int i=0; i<cantidadDias; i++){
         agregarDia();
      }
   }

}

Fecha::Fecha(){
   establecerFechaPorDefecto();
}

Fecha::Fecha(int dia, int mes, int anio){
   _dia = dia;
   _mes = mes;
   _anio = anio;

   if (_dia <= 0 || _mes <= 0 || _anio <= 0 || _mes > 12){
      establecerFechaPorDefecto();
   }
   else{
      int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
      if (esBisiesto()){
         dias[1]++;
      }

      if (_dia > dias[_mes-1]){
         establecerFechaPorDefecto();
      }
   }
}

int Fecha::getDia(){
   return _dia;
}
int Fecha::getMes(){
   return _mes;
}
int Fecha::getAnio(){
   return _anio;
}



std::string Fecha::toString(std::string formatoFecha){
   std::string fechaFormateada = "";

   std::string DD = std::to_string(_dia);
   std::string MM = std::to_string(_mes);
   std::string YYYY = std::to_string(_anio);
   // DD/MM/YYYY
   if (_dia < 10){
      DD = "0" + std::to_string(_dia);
   }
   if (_mes < 10){
      MM = "0" + std::to_string(_mes);
   }

   if (formatoFecha == "DD/MM/YYYY"){
      fechaFormateada = DD + "/" + MM + "/" + YYYY;
   }
   else if (formatoFecha == "YYYY/MM/DD"){
      fechaFormateada = YYYY + "/" + MM + "/" + DD;
   }
   else{
      fechaFormateada = DD + "/" + MM + "/" + YYYY;
   }

   return fechaFormateada;
}

