#include "../include/Controladores/ControladorCurso.h"

ControladorCurso* ControladorCurso::instancia = nullptr;

ControladorCurso::ControladorCurso() {
    // Constructor privado
    //Poner todas las variables en null
    this->datosDeCurso = nullptr;
    this->datosDeLeccion = nullptr;
    this->datosDeProfesor = nullptr;
    this->datoIdioma = nullptr;
    this->datosPrevias = nullptr;
    this->datosEjercicio = nullptr;
}

ControladorCurso* ControladorCurso::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ControladorCurso();
    }
    return instancia;
}

ControladorCurso::~ControladorCurso() {
    // Destructor
}

//Getters
DTCurso ControladorCurso::getDatosDeCurso() {
    return *datosDeCurso;
}
DTLeccion ControladorCurso::getDatosDeLeccion() {
    return *datosDeLeccion;
}
DTProfesor ControladorCurso::getDatosDeProfesor() {
    return *datosDeProfesor;
}
string ControladorCurso::getDatoIdioma() {
    return *datoIdioma;
}
set<DTCurso*> ControladorCurso::getDatosPrevias() {
    return *datosPrevias;
}
DTEjercicio ControladorCurso::getDatosEjercicio() {
    return *datosEjercicio;
}

//Setters
void ControladorCurso::setDatosDeCurso(DTCurso datos) {
    // Implementación pendiente
}
void ControladorCurso::setDatosDeLeccion(DTLeccion datos) {
    // Implementación pendiente
}
void ControladorCurso::setDatosDeProfesor(string nombreProfesor) {
    // Implementación pendiente
}
void ControladorCurso::setDatoIdioma(string idioma) {
    // Implementación pendiente
}
void ControladorCurso::setDatosPrevias(set<DTCurso*> previas) {
    // Implementación pendiente
}
void ControladorCurso::setDatosEjercicioComletarpPalabras(DTEjercicio datos) {
    // Implementación pendiente
}
void ControladorCurso::setDatosEjercicioTraduccion(DTEjercicio datos) {
    // Implementación pendiente
}




bool ControladorCurso::altaCurso() {
    // Implementación pendiente
    return false;
}

void ControladorCurso::eliminarCurso(string curso) {
    // Implementación pendiente
}

void ControladorCurso::habilitarCurso(string curso) {
    // Implementación pendiente
}

bool ControladorCurso::altaIdioma() {
    // Implementación pendiente
    return false;
}

void ControladorCurso::agregarEjercicio(DTEjercicio datos) {
    // Implementación pendiente
}

set<string> ControladorCurso::listarProfe() {
    // Implementación pendiente
    return set<string>();
}

DTEstadisticaCurso ControladorCurso::estadisticasCurso(string curso) {
    // Implementación pendiente
    return DTEstadisticaCurso();
}

set<string> ControladorCurso::listarNombresDeCursos() {
    // Implementación pendiente
    return set<string>();
}

set<DTCurso> ControladorCurso::listarDTCursos() {
    // Implementación pendiente
    return set<DTCurso>();
}

set<string> ControladorCurso::listarIdiomasProfesor() {
    // Implementación pendiente
    return set<string>();
}

set<string> ControladorCurso::listarIdiomas() {
    // Implementación pendiente
    return set<string>();
}

bool ControladorCurso::solucionCorrectacompletarPalabras(set<string> solucion, string estudiante, int IdEjercicio) {
    // Implementación pendiente
    return false;
}

bool ControladorCurso::solucionCorrectaTraduccion(string solucion, string estudiante, int IdEjercicio) {
    // Implementación pendiente
    return false;
}

void ControladorCurso::seleccionarEjercicio(int idEjercicio) {
    // Implementación pendiente
}

set<DTEjercicio> ControladorCurso::seleccionarEjerciciosDeCurso(string curso) {
    // Implementación pendiente
    return set<DTEjercicio>();
}

set<string> ControladorCurso::consultarSuscripciones(string nick) {
    // Implementación pendiente
    return set<string>();
}

void ControladorCurso::suscribirUsuario(set<string> idiomas) {
    // Implementación pendiente
}

set<string> ControladorCurso::listarIdiomasSuscrito(string nick) {
    // Implementación pendiente
    return set<string>();
}

void ControladorCurso::eliminarSuscripciones(set<string> idiomas, string nick) {
    // Implementación pendiente
}

void ControladorCurso::limpiarDatos() {
    // Implementación pendiente
}

set<string> ControladorCurso::CursosInscriptoSinAprobar(string nick) {
    // Implementación pendiente
    return set<string>();
}