#include "../../include/Clases/Leccion.h"
#include "../../include/Clases/RellenarPalabras.h"
#include "../../include/Clases/Traduccion.h"

void Leccion::setTema(string tema) {
    this->tema = tema;
}

void Leccion::setObjetivoAprendizaje(string objetivoAprendizaje) {
    this->objetivoAprendizaje = objetivoAprendizaje;
}

void Leccion::setCantidadEjercicios(int cantidadDeEjercicios) {
    this->cantidadDeEjercicios = cantidadDeEjercicios;
}

void Leccion::setNumero(int numero) {
    this->numero = numero;
}
void Leccion::eliminarProgreso(string nick){
    progresos.erase(nick);
}
string Leccion::getTema() {
    return tema;
}

void Leccion::agregarProgreso(Progreso* progreso){
    this->progresos[progreso->getInscripcion()->getEstudiante()->getNick()]=  progreso;
}


void Leccion::addEjercicio(Ejercicio* ej) {
    ejercicios.insert(pair<int, Ejercicio*>(ej->getIdEjercicio(), ej));
    setCantidadEjercicios(getCantidadDeEjercicios() + 1);
    // Implementación de addEjercicio
    // Agrega un ejercicio al mapa de ejercicios
}
string Leccion::getObjetivoAprendizaje() {
    return objetivoAprendizaje;
}

int Leccion::getCantidadDeEjercicios() {
    return cantidadDeEjercicios;
}

int Leccion::getNumero() {
    return numero;
}

map<int, Ejercicio*> Leccion::getEjercicios(){
    return ejercicios;
}

map<string, Progreso*> Leccion :: getProgresos(){
    return progresos;
}

Leccion::~Leccion() {
    for(auto it=ejercicios.begin();it!=ejercicios.end();it++){
        delete it->second;
    }
    ejercicios.clear();
    for(auto iter = progresos.begin();iter!=progresos.end();iter++){
        delete iter->second;
    }
    progresos.clear();
    // Implementación del destructor si es necesario
}

Leccion::Leccion(string tema, string objetivoAprendizaje, int cantidadDeEjercicios, int numero,list<DTRellenarPalabras> listaRellenarPalabras,list<DTTraduccion> listaTraduccion) {
    this->tema = tema;
    this->objetivoAprendizaje = objetivoAprendizaje;
    this->cantidadDeEjercicios = cantidadDeEjercicios;
    this->numero = numero;
    if(listaRellenarPalabras.size()>0){
    for(auto iter=listaRellenarPalabras.begin();iter!=listaRellenarPalabras.end();iter++){
        if(iter->getNumLec()==getNumero()){
            Ejercicio *ej = new RellenarPalabras(iter->getListaDePalabras(), iter->getIdEjercicio(), iter->getDescripcion(), iter->getLetra(),this);
            ejercicios[iter->getIdEjercicio()] = ej;
        }
    }
    }
    if(listaTraduccion.size()>0){
    for(auto iter=listaTraduccion.begin();iter!=listaTraduccion.end();iter++){
        if(iter->getNumLec()==getNumero()){
            Ejercicio *ej = new Traduccion(iter->getSolucion(), iter->getIdEjercicio(), iter->getDescripcion(), iter->getLetra(),this);
            ejercicios[iter->getIdEjercicio()] =ej;
        }
    }
}
}
Ejercicio* Leccion::seleccionarEj(int idEjercicio) {
    auto it = ejercicios.find(idEjercicio);
    if(it!=ejercicios.end()){
        return it->second;
    }
    else return NULL;
}

void Leccion::aumentarProgreso(Estudiante e) {
    // Implementación de aumentarProgreso
    // Aumenta el progreso del estudiante en la lección actual
}

list<DTEjercicio> Leccion::ejerciciosNoAprobados(string nick) {
    list<DTEjercicio> ejerciciosNoAprobados;
    Progreso* prog = progresos.find(nick)->second;
    list<Ejercicio*> ejerciciosAprobados = prog->getEjerciciosResueltos();
    for(auto it = ejercicios.begin();it!=ejercicios.end();it++){
        bool esta = false;
        for(auto iter = ejerciciosAprobados.begin();iter!=ejerciciosAprobados.end();iter++){
            if(it->second->getIdEjercicio()==(*iter)->getIdEjercicio()){
                esta = true;
                break;
            }
        }
        if(!esta){
            Ejercicio* ej = it->second;
            if(ej=dynamic_cast<RellenarPalabras*>(ej)){
                DTEjercicio* dt = new DTEjercicio(it->second->getIdEjercicio(),it->second->getDescripcion(),it->second->getLetra(),"RellenarPalabras",this->numero);
                ejerciciosNoAprobados.push_back(*dt);
            }
            else{
                DTEjercicio* dt= new DTEjercicio(it->second->getIdEjercicio(),it->second->getDescripcion(),it->second->getLetra(),"Traduccion",numero);
                ejerciciosNoAprobados.push_back(*dt);
            }
        }
    }
    return ejerciciosNoAprobados;
}
void Leccion::conseguirInfoLeccion(list<string> &infoLeccion){
    string datosLeccion;
    datosLeccion = "Tema: " + tema + "\n" + "Objetivo de aprendizaje: " + objetivoAprendizaje + "\n";
    infoLeccion.push_back(datosLeccion);
    if (ejercicios.size() > 0){
        for(auto it=ejercicios.begin();it!=ejercicios.end();it++){
            
            it->second->conseguirInfoEjercicio(infoLeccion);
        }
    }
}
