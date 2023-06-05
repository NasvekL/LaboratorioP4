#include "../../include/Clases/Curso.h"

// CONSTRUCTOR Y DESTRUCTOR
Curso::~Curso() {
    // Implementación del destructor
}
Curso::Curso() {
    // Implementación del constructor vacio
}

Curso::Curso(string nombre, string descripcion, nivelDeDificultad nivel, bool habilitado, Idioma* idioma) {
    // Implementación del constructor
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->nivelDeDif = nivel;
    this->habilitado = habilitado;
    this->previas = previas;
    // Inicializar los pseudoatributos
    this->idiomaDelCurso = nullptr;
    this->profesorQueLoDicta = nullptr;
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

void Curso::setInscripciones(list<Inscripcion*> inscripciones) {
    this->inscripciones = inscripciones;
}

// OPERACIONES
DTEjercicio Curso::seleccionarEjercicio(int idEjercicio) {
    // Implementación de la operación
}

int Curso::progresoPromedio() {
    // Implementación de la operación
}

int Curso::progresoDeEstudiante(Estudiante e){
    // Implementación de la operación
}

DTEstadisticaCurso Curso::estadisticasCurso() {
    // Implementación de la operación
}