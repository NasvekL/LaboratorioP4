#include "../../include/DTs/DTFecha.h"


DTFecha :: DTFecha(int dia, int mes, int anio) {
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;

}

DTFecha::~DTFecha(){
}
DTFecha::DTFecha(){
}

      
int DTFecha:: getDia() {
    return dia;
}

int DTFecha:: getMes() {
    return mes;
}

int DTFecha:: getAnio() {
    return anio;
}
string DTFecha::toString(){
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}
