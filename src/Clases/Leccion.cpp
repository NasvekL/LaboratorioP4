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
    //return ejercicios;
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

DTEjercicio Leccion::seleccionarEj(int idEjercicio) {
    // Implementación de seleccionarEj
    // Retorna un objeto DTEjercicio según el idEjercicio proporcionado
}

void Leccion::aumentarProgreso(Estudiante e) {
    // Implementación de aumentarProgreso
    // Aumenta el progreso del estudiante en la lección actual
}

set<DTEjercicio> Leccion::ejerciciosNoAprobados(string nick) {
    set<DTEjercicio> ejNoAprobados;
    map<string, Progreso*> progs = this->progresos;
    auto it = progs.find(nick);
    Progreso* progresoEst = it->second;
    list<Ejercicio*> ejResueltos = progresoEst->getEjerciciosResueltos();
    map<int, Ejercicio*> ejercicios = this->getEjercicios();
    auto it2 = ejercicios.begin();
    for(it2; it2!=ejercicios.end(); it2++){
        auto it3 = ejResueltos.begin();
        for(it3; it3 != ejResueltos.end(); it3++){
            if(it2->first == (*it3)->getIdEjercicio()){
                string tipo;
                Ejercicio* ejercicio = it2->second;
                if (RellenarPalabras* rellenar = dynamic_cast<RellenarPalabras*>(ejercicio)) {
                tipo = "completar";
                } 
                else{
                tipo = "traduccion";
                }
                DTEjercicio ej = DTEjercicio((*it3)->getIdEjercicio(),(*it3)->getLetra(),(*it3)->getDescripcion(),tipo,this->getNumero());
                ejNoAprobados.insert(ej);
            }
                
            }
        }
        return ejNoAprobados;
    }

