#pragma once
#include <ctime>
#include <string>

class Fecha{
   private:
   int _dia, _mes, _anio;

   void establecerFechaPorDefecto();
   bool esBisiesto();
   void agregarDia();

   public:
      Fecha();
      Fecha(int dia, int mes, int anio);

      int getDia();
      int getMes();
      int getAnio();


      void agregarDias(int cantidadDias);
      std::string toString(std::string formatoFecha = "DD/MM/YYYY");
      void Cargar();
      void obtenerFechaHoraActual();
      void CargaAutomatico(int& anio, int& mes, int& dia);
      void Mostrar();
      int diferenciaDias(Fecha aux);
};

class Reloj {
private:
    int horas;
    int minutos;

public:
    Reloj() {
        time_t now = time(0);
        struct tm* timeinfo = localtime(&now);
        horas = timeinfo->tm_hour;
        minutos = timeinfo->tm_min;
    }

    Reloj(int h, int m) {
        horas = h;
        minutos = m;
    }


    int getHoras() const {
        return horas;
    }

    int getMinutos() const {
        return minutos;
    }
};



