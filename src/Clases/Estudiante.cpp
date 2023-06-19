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
    Curso* c = NULL;
    int ultimaLec = 1;
    for(auto it = inscripciones.begin(); it!=inscripciones.end(); it++){
        if((*it)->getInscriptoA()->getNombreCurso() == curso){
            c = (*it)->getInscriptoA();
            ultimaLec = (*it)->getLeccionActual();
        }
    }
    return c->buscarEjNoAprobados(getNick(), ultimaLec);
}


list<Inscripcion*> Estudiante::getInscripciones() {
    return inscripciones;
}