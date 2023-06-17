#include "../../include/Clases/Estudiante.h"

string Estudiante::getPais() {
    return pais;
}


DTFecha Estudiante::getNacimiento() {
    return nacimiento;
}


Estudiante::Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha nacimiento){
    this->pais = pais;
    this->nacimiento = nacimiento;
    this->setNick(nickname);
    this->setContrasenia(contrasenia);
    this->setNombre(nombre);
    this->setDescripcion(descripcion);
}

void Estudiante::agregarInscripcion(Inscripcion* insc) {
    inscripciones.push_back(insc);
}
void Estudiante::eliminarInscripcion(Inscripcion* insc) {
    inscripciones.remove(insc);
}

Estudiante::~Estudiante() {
    // Implementación del destructor si es necesario
}

list<DTNotificacion> Estudiante::verNotificaciones() {
    // Implementación de verNotificaciones
    // Retorna una lista de DTNotificacion
}

DTEstudiante Estudiante::getDTEstudiante() {
    DTEstudiante dt = DTEstudiante(this->getNick(), this->getContrasenia(), this->getNombre(), this->getDescripcion(), this->getPais(), this->getNacimiento());    
    return dt;
}

Curso* Estudiante :: buscarCurso(string nombreCurso){
    list<Inscripcion*> ins = getInscripciones();
    auto it = ins.begin();
    Curso* c = NULL;
    while(it!=ins.end() && c == NULL){
        if((*it)->getInscriptoA()->getNombreCurso() == nombreCurso){
            c = (*it)->getInscriptoA();
        }
        it++;
    }
    return c;
}

set<string> Estudiante::getCursosInscriptosSA() {
    list<Inscripcion*> inscripciones = getInscripciones();
    set<string> cursosInscriptos;
    for (auto it = inscripciones.begin(); it != inscripciones.end(); it++) {
        if (!(*it)->getAprobado()) {
            cursosInscriptos.insert((*it)->getInscriptoA()->getNombreCurso());
        }   
    }
    return cursosInscriptos;
}

list<DTEjercicio> Estudiante :: ejerciciosNoAprobados(string curso){
    list<Inscripcion*> ins = getInscripciones();
    auto it = ins.begin();
    Curso* c = NULL;
    int ultimaLec = 1;
    while(it!=ins.end() && c == NULL){
        if((*it)->getInscriptoA()->getNombreCurso() == curso){
            c = (*it)->getInscriptoA();
            ultimaLec = (*it)->getLeccionActual();
        }
        it++;
    }
    return c->buscarEjNoAprobados(this->getNick(), ultimaLec);
}

set<DTCurso> Estudiante::obtenDTCurso() {
    // Implementación de obtenDTCurso
    // Retorna un conjunto de DTCurso
}

set<int> Estudiante::obtenerProgreso() {
    // Implementación de obtenerProgreso
    // Retorna un conjunto de enteros
}

list<Inscripcion*> Estudiante::getInscripciones() {
    return inscripciones;
}