#include "../Clases/Profesor.h"


void Profesor:: Profesor(string nickname, string nombre, string contrasenia, string descripcion, string instituto,list<idiomas*> idiomas){
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasenia = contrasenia;
    this->descripcion = descripcion;
    this->instituto = instituto;
    while idiomas.size() != 0{
        this->idiomas.push_back(idiomas.front());
        idiomas.pop_front();
    } 
};

void Pofesor:: ~Profesor(){

};

string Profesor:: getInstituto(){
    return this-> instituto;
};

list<DTNotificacion> Profesor:: verNotificaciones(){
        for (auto i : this->notifiaciones) {
		cout << i << ' ';
	}
	return 0;
};

DTProfesor Profesor:: getDTProfesor(){
    
}