#include "../include/Clases/Usuario.h"
#include "../include/Clases/Usuario.h"

void Usuario:: setNick(string nick){
    this->nickname = nick;  
};

void Usuario:: setNombre(string nombre){
    this->nombre = nombre;
};

void Usuario:: setContrasenia(string contra){
    this->contrasenia = contra;
};

void Usuario:: setDescripcion(string desripcion){
    this->descripcion = descripcion;
};

list<DTNotificacion> Usuario:: verNotificaciones(){
        for (auto i : this->notifiaciones) {
		cout << i << ' ';
	}
	return 0;
};

string Usuario:: getNick(){
    return this->nick;
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

void Usuario:: ~Usuario(){

};

void Usuario:: notificar(){
    
};
