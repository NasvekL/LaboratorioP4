#include "DtObjetoRoto.h"
string DtObjetoRoto::getNombre(){
    return nombreObjeto;
}
string DtObjetoRoto::getNombreNinio(){
    return NombreNinio;
}
bool DtObjetoRoto::esprestado(){
    return prestado;
}
DtObjetoRoto::DtObjetoRoto(string nombreO,bool pr,string nombreN){
 this->nombreObjeto=nombreO;
 this->NombreNinio=nombreN;
 this->prestado=pr;
}
DtObjetoRoto::~DtObjetoRoto(){}