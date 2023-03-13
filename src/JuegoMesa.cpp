#include "JuegoMesa.h"

//CONS Y DES

JuegoMesa::JuegoMesa(){
    this->CantJugadores = 0;
    this->EdadRecomendada = 0;
}

JuegoMesa::JuegoMesa(int edad, int cantidad){
    this->CantJugadores = cantidad;
    this->EdadRecomendada = edad;
}

JuegoMesa::~JuegoMesa(){
}




//GETTERS Y SETTERS

void JuegoMesa::setEdadRecomendada(int edad){
    this->EdadRecomendada = edad;
}

void JuegoMesa::setCantJugadores(int cant){
    this->EdadRecomendada = cant;
}

int JuegoMesa::getEdadRecomendada(){
    return EdadRecomendada;
}

int JuegoMesa::getCantJugadores(){
    return CantJugadores;
}




//TOSTRING

string JuegoMesa::toString(){
    return "Juego: "

}