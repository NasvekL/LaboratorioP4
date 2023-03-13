#include "Libro.h"
//Constructores
Libro::Libro(/* args */)
{
}
Libro::~Libro()
{
}
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
    return "Libro: " + getNombre() + ", "+getAnioComprado()+", "+getEstado().toString() + ", "+getAutor()+", "+getCantPaginas();
}

