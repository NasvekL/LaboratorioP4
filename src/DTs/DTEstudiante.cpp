#include "../include/DTEstudiante.h"


string DTEstudiante :: getPais(){
    return pais;
}

string DTEstudiante ::getContrasenia(){
    return contrasenia;
}

Fecha DTEstudiante:: getNacimineto(){
    return nacimiento;
}

string DTEstudiante::getNickname(){
    return nickname;
}

string DTEstudiante::getDescripcion(){
    return descripcion;
}

string DTEstudiante(){
    return nombre;
}

DTEstudiante ::~DTEstudiante() {

}

DTEstudiante::DTEstudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, Fecha nacimiento){
    this->nickname = getNickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->pais = pais;
    this->nacimiento = nacimiento;
}