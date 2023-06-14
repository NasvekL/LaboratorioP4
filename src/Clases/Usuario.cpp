#include "../../include/Clases/Usuario.h"

void Usuario:: setNick(string nick){
    this->nickname = nick;  
};

void Usuario:: setNombre(string nombre){
    this->nombre = nombre;
};

void Usuario:: setContrasenia(string contra){
    this->contrasenia = contra;
};

void Usuario:: setDescripcion(string descripcion){
    this->descripcion = descripcion;
};

list<DTNotificacion> Usuario:: verNotificaciones(){

};

string Usuario:: getNick(){
    return this->nickname;
};

string Usuario:: getNombre(){
    return this->nombre;
};

string Usuario:: getContrasenia(){
    return this->contrasenia;
};

string Usuario:: getDescripcion(){
    return this->descripcion;
};

void Usuario:: notificar(){
    
};
