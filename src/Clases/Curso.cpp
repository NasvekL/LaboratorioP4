#include "../../include/Clases/Curso.h"

// CONSTRUCTOR Y DESTRUCTOR
Curso::~Curso() {
    // Implementación del destructor
}
Curso::Curso() {
    // Implementación del constructor vacio
}
//Hay que hacer un constructor para los casos en los que hay lecciones y otro para los que no?
Curso::Curso(string nombre, string descripcion, nivelDeDificultad nivel, bool habilitado, list<Curso*> previas, Idioma* idioma, Profesor* profesorQueLoDicta){
    // Implementación del constructor
    // Inicializar los pseudoatributos
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

void Curso::agregarLeccion(Leccion *lec){
    lecciones.push_back(lec);
}