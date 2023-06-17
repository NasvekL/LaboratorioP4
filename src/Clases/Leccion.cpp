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

string Leccion::getTema() {
    return tema;
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
    for(auto iter=listaRellenarPalabras.begin();iter!=listaRellenarPalabras.end();iter++){
        if(iter->getNumLec()==getNumero()){
            Ejercicio *ej = new RellenarPalabras(iter->getListaDePalabras(), iter->getIdEjercicio(), iter->getDescripcion(), iter->getLetra(),this);
            ejercicios.insert(std::make_pair(iter->getIdEjercicio(), ej));
        }
    }
    for(auto iter=listaTraduccion.begin();iter!=listaTraduccion.end();iter++){
        if(iter->getNumLec()==getNumero()){
            Ejercicio *ej = new Traduccion(iter->getSolucion(), iter->getIdEjercicio(), iter->getDescripcion(), iter->getLetra(),this);
            ejercicios.insert(std::make_pair(iter->getIdEjercicio(), ej));
        }
    }
}

Ejercicio* Leccion::seleccionarEj(int idEjercicio) {
    map<int, Ejercicio*> ejercicios = this->getEjercicios();
    auto it = ejercicios.find(idEjercicio);
    if(it!=ejercicios.end()){
        return it->second;
    }else return NULL;
}

void Leccion::aumentarProgreso(Estudiante e) {
    // Implementación de aumentarProgreso
    // Aumenta el progreso del estudiante en la lección actual
}

set<DTEjercicio> Leccion::ejerciciosNoAprobados(string nick) {
    // Implementación de ejerciciosNoAprobados
    // Retorna un conjunto de DTEjercicio de los ejercicios no aprobados por el estudiante con el nickname proporcionado
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
