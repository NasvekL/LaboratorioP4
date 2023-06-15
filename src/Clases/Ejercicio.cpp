#include "../../include/Clases/Ejercicio.h"

void Ejercicio:: setIdEjercicio(int idEjercicio){
    this->idEjercicio= idEjercicio;
}

void Ejercicio:: setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

void Ejercicio:: setLetra(string letra){
    this->letra= letra;
}

void Ejercicio:: setLeccion(Leccion* lec){
    this->leccion = lec;
}

int Ejercicio:: getIdEjercicio(){
    return idEjercicio;
}

string Ejercicio:: getDescripcion(){
    return descripcion;
}

string Ejercicio:: getLetra(){
    return letra;
}

Leccion* Ejercicio:: getLeccion(){
    return leccion;
}

Ejercicio:: ~Ejercicio(){

}
