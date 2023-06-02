#include "../include/DTLeccion.h"

int getNumero();
        int getCantidadDe1Ejercicios();
        string getObjetivo

int DTLeccion ::getCantidadDe1Ejercicios(){
    return cantidadDeEjercicios;
}

int DTLeccion::getNumero(){
    return numero;
}

string DTLeccion::getTema(){
    return tema;
}

string DTLeccion::getObjetivoAprendizaje(){
    return objetivoAprendizaje;
}

DTLeccion:: ~DTLeccion(){

}

DTLeccion:: DTLeccion(int numero,int cantidadDeEjercicios,string objetivoAprendizaje,string tema){
    this->numero = numero;
    this->cantidadDeEjercicios = cantidadDeEjercicios;
    this->objetivoAprendizaje = objetivoAprendizaje;
    this->tema = tema;
}
