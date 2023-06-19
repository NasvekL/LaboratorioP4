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
list<DTNotificacion> Usuario:: getNotificaciones(){
    return this->notificaciones;
};
void Usuario::eliminarNotificaciones(){
this->notificaciones.clear();
};
void Usuario:: notificar(DTNotificacion noti){
    notificaciones.push_back(noti);
};
