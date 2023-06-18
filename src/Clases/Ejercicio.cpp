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

void Ejercicio:: conseguirInfoEjercicio(list<string> &infoEjercicio){
    string datosDelEjercicio = "Descripcion del ejercicio: " + descripcion + "\n" + "Letra del ejercicio: " + letra + "\n" + "Id del ejercicio: " + to_string(idEjercicio) + "\n" + "\n";
    infoEjercicio.push_back(datosDelEjercicio);
}

string Ejercicio:: mostrarEjercicio(){
    string datosDelEjercicio = "Descripcion del ejercicio: " + descripcion + "\n" + "Letra del ejercicio: " + letra + "\n";
    return datosDelEjercicio;
}