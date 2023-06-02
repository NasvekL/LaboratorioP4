#include "../include/DTEstudianteSC.h"


string DTEstudianteSC :: getPais(){
    return pais;
}

Fecha DTEstudianteSC:: getNacimineto(){
    return nacimiento;
}

string DTEstudianteSC::getNickname(){
    return nickname;
}

string DTEstudianteSC::getDescripcion(){
    return descripcion;
}

string DTEstudianteSC(){
    return nombre;
}

DTEstudianteSC ::~DTEstudianteSC() {

}

DTEstudianteSC::DTEstudianteSC(string nickname, string nombre, string descripcion, string pais, Fecha nacimiento){
    this->nickname = getNickname;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->pais = pais;
    this->nacimiento = nacimiento;
}