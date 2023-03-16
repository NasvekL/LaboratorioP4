#include "../include/JuegoMesa.h"

//CONS Y DES

JuegoMesa::JuegoMesa(){
    this->CantJugadores = 0;
    this->EdadRecomendada = 0;
}

JuegoMesa::JuegoMesa(int edad, int cantidad, string Nombre, int AnioComprado, state estado){
    this->CantJugadores = cantidad;
    this->EdadRecomendada = edad;
    this->setNombre(Nombre);
    this->setAnioComprado(AnioComprado);
    this->setEstado(estado);
    this->setPrestadoA(nullptr);
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
    string estadito;
        switch(getEstado()){
            case nuevo:
                estadito = "Nuevo";
                break;
            case bienConservado:
                estadito = "BienConservado";
                break;
            case roto:
                estadito = "Roto";
                break;
        }


    return "Juego: " + getNombre() + ", "+std::to_string(getAnioComprado())+", "+estadito + ", "+std::to_string(getEdadRecomendada())+", "+std::to_string(getCantJugadores());

}