#include "JuegoMesa.h"

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

void JuegoMesa::setEdadRecomendada(int edad){
    this->EdadRecomendada = edad;
}

void JuegoMesa::setCantJugadores(int cant){
    this->EdadRecomendada = cant;
}

int JuegoMesa::getEdadRecomendada(){
    return this->EdadRecomendada;
}

int JuegoMesa::getCantJugadores(){
    return this->CantJugadores;
}

string JuegoMesa::toString(){
    
}