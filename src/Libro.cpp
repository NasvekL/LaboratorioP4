#include "Libro.h"
//Constructores
Libro::Libro(/* args */){}
Libro::~Libro(){}
//Getters y Setters
string Libro::getAutor(){
    return Autor;
}
void Libro::setAutor(string Autor){
    this->Autor=Autor;
}
int Libro::getCantPaginas(){
    return CantPaginas;
}
void Libro::setCantPaginas(int CantPaginas){
    this->CantPaginas=CantPaginas;
}


//toString
string Libro::toString(){
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
    return "Libro: " + getNombre() + ", " + std::to_string(getAnioComprado())+", "+estadito+ ", "+getAutor()+", "+ std::to_string(getCantPaginas());
}

