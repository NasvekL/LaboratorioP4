#include "DtObjetoRoto.h"
#include <iostream>
string DtObjetoRoto::getNombreObjeto(){
    return nombreObjeto;
}
string DtObjetoRoto::getNombreNinio(){
    return NombreNinio;
}
bool DtObjetoRoto::esPrestado(){
    return prestado;
}
DtObjetoRoto::DtObjetoRoto(string nombreO,bool pr,string nombreN){
    this->nombreObjeto=nombreO;
    this->NombreNinio=nombreN;
    this->prestado=pr;
}
DtObjetoRoto::~DtObjetoRoto(){
}
ostream& operator<<(ostream& os, const DtObjetoRoto& dt)
{
    if(dt.prestado)
        os << dt.nombreObjeto << ',' << 'PRESTADO SI' << ',' << dt.NombreNinio;
    else
        os << dt.nombreObjeto << ',' << 'PRESTADO NO';
    return os;
}