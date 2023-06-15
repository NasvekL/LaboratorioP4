#include "../../include/Clases/Curso.h"

// CONSTRUCTOR Y DESTRUCTOR
Curso::~Curso() {
    // Implementación del destructor
}
Curso::Curso() {
    // Implementación del constructor vacio
}
//Hay que hacer un constructor para los casos en los que hay lecciones y otro para los que no?
Curso::Curso(string nombre, string descripcion, nivelDeDificultad nivel, map<string,Curso*> previas, Idioma* idioma, Profesor* profesorQueLoDicta,list<DTRellenarPalabras> datosRellenarP,list<DTTraduccion> datosTraduccion,list<DTLeccion>lecciones){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->nivelDeDif = nivel;
    this->idiomaDelCurso = idioma;
    this->profesorQueLoDicta = profesorQueLoDicta;
    this->habilitado = false;
    for(auto iter=previas.begin(); iter!=previas.end(); iter++){
        Curso* cur = iter->second;
        this->previas.push_back(cur);
    }
    for(auto iter = lecciones.begin(); iter!=lecciones.end(); iter++){
        DTLeccion dtl = *iter;
        Leccion* lec = new Leccion(dtl.getTema(),dtl.getObjetivoAprendizaje(),dtl.getCantidadDeEjercicios(),dtl.getNumero(),datosRellenarP,datosTraduccion);
        this->lecciones.push_back(lec);
    }
}

// GETTERS
string Curso::getNombreCurso() const{
    return nombre;
}

string Curso::getDescripcion() {
    return descripcion;
}

nivelDeDificultad Curso::getNivelDeDificultad() {
    return nivelDeDif;
}

list<Curso*> Curso::getPrevias() {
    return previas;
}

bool Curso::getHabilitado() {
    return habilitado;
}

// SETTERS
void Curso::setHabilitado(bool habilitado) {
    this->habilitado = habilitado;
}

// GETTERS DE PSEUDOATRIBUTOS
Idioma* Curso::getIdiomaDelCurso() {
    return idiomaDelCurso;
}

Profesor* Curso::getProfesorQueLoDicta() {
    return profesorQueLoDicta;
}

list<Leccion*>& Curso::getLecciones() {
    return lecciones;
}

list<Inscripcion*>& Curso::getInscripciones() {
    return inscripciones;
}

// SETTERS DE PSEUDOATRIBUTOS
void Curso::setIdiomaDelCurso(Idioma* i) {
    idiomaDelCurso = i;
}

void Curso::setProfesorQueLoDicta(Profesor* p) {
    profesorQueLoDicta = p;
}

void Curso::setLecciones(list<Leccion*> lecciones) {
    this->lecciones = lecciones;
}
void Curso::agregarInscripcion(Inscripcion* insc){
    inscripciones.push_back(insc);
}

// OPERACIONES

int Curso::progresoPromedio() {
    // Implementación de la operación
}

int Curso::progresoDeEstudiante(Estudiante e){
    // Implementación de la operación
}

DTEstadisticaCurso Curso::estadisticasCurso() {
    // Implementación de la operación
}

void Curso::agregarLeccion(Leccion *lec){
    lecciones.push_back(lec);
}