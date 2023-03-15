#include "Ninio.h"
#include "Objeto.h"
set<string> Ninio::ListarObjetosPrestados() {
    set<string> objetosPrestados;//lista de objetos prestados
    for (Objeto* x : this->objetos_){
        objetosPrestados.insert(x->toString());
    }
    return objetosPrestados;
}

Ninio::Ninio(string nom,int edad,string dir,string tel){
    nombre = nom;
    direccion=dir;
    this->edad = edad;
    telefono=tel;
}

Ninio::~Ninio() {   //destructor
}

string Ninio::getnombre() {
    return nombre;
}

void Ninio::setnombre(string nombre) {
    this->nombre=nombre;
}

string Ninio::getdireccion() {
    return direccion;
}

void Ninio::setdireccion(string direccion) {
    this->direccion=direccion;
}

string Ninio::gettelefono() {
    return telefono;
}

void Ninio::settelefono(string telefono) {
    this->telefono=telefono;
}

int Ninio::getedad() { 
    return edad;
}

void Ninio::setedad(int edad) {
    this->edad=edad;
}
void Ninio:: agregar_objeto(Objeto* objeto){
    objetos_.push_back(objeto);
    objeto->setPrestadoA(this);
    }
list<Objeto*>& Ninio:: objetos(){
    return objetos_;
}
