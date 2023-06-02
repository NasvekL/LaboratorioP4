#include "../include/IControladorCurso.h"

IControladorCurso* IControladorCurso::instancia = nullptr;

IControladorCurso::IControladorCurso() {
    // Constructor privado
}

IControladorCurso* IControladorCurso::getInstancia() {
    if (instancia == nullptr) {
        instancia = new IControladorCurso();
    }
    return instancia;
}

IControladorCurso::~IControladorCurso() {
    // Destructor
}

DTCurso IControladorCurso::getDatosDeCurso() {
    // Implementación pendiente
    return DTCurso();
}

DTLeccion IControladorCurso::getDatosDeLeccion() {
    // Implementación pendiente
    return DTLeccion();
}

DTProfesor IControladorCurso::getDatosDeProfesor() {
    // Implementación pendiente
    return DTProfesor();
}

string IControladorCurso::getDatoIdioma() {
    // Implementación pendiente
    return "";
}

set<DTCurso*> IControladorCurso::getDatosPrevias() {
    // Implementación pendiente
    return set<DTCurso*>();
}

DTEjercicio IControladorCurso::getDatosEjercicio() {
    // Implementación pendiente
    return DTEjercicio();
}

void IControladorCurso::setDatosDeCurso(DTCurso datos) {
    // Implementación pendiente
}

void IControladorCurso::setDatosDeLeccion(DTLeccion datos) {
    // Implementación pendiente
}

void IControladorCurso::setDatosDeProfesor(string nombreProfesor) {
    // Implementación pendiente
}

void IControladorCurso::setDatoIdioma(string idioma) {
    // Implementación pendiente
}

void IControladorCurso::setDatosPrevias(set<DTCurso*> previas) {
    // Implementación pendiente
}

void IControladorCurso::setDatosEjercicioComletarpPalabras(DTEjercicio datos) {
    // Implementación pendiente
}

void IControladorCurso::setDatosEjercicioTraduccion(DTEjercicio datos) {
    // Implementación pendiente
}

bool IControladorCurso::altaCurso() {
    // Implementación pendiente
    return false;
}

void IControladorCurso::eliminarCurso(string curso) {
    // Implementación pendiente
}

void IControladorCurso::habilitarCurso(string curso) {
    // Implementación pendiente
}

bool IControladorCurso::altaIdioma() {
    // Implementación pendiente
    return false;
}

void IControladorCurso::agregarEjercicio(DTEjercicio datos) {
    // Implementación pendiente
}

set<string> IControladorCurso::listarProfe() {
    // Implementación pendiente
    return set<string>();
}

DTEstadisticaCurso IControladorCurso::estadisticasCurso(string curso) {
    // Implementación pendiente
    return DTEstadisticaCurso();
}

set<string> IControladorCurso::listarNombresDeCursos() {
    // Implementación pendiente
    return set<string>();
}

set<DTCurso> IControladorCurso::listarDTCursos() {
    // Implementación pendiente
    return set<DTCurso>();
}

set<string> IControladorCurso::listarIdiomasProfesor() {
    // Implementación pendiente
    return set<string>();
}

set<string> IControladorCurso::listarIdiomas() {
    // Implementación pendiente
    return set<string>();
}

bool IControladorCurso::solucionCorrectacompletarPalabras(set<string> solucion, string estudiante, int IdEjercicio) {
    // Implementación pendiente
    return false;
}

bool IControladorCurso::solucionCorrectaTraduccion(string solucion, string estudiante, int IdEjercicio) {
    // Implementación pendiente
    return false;
}

void IControladorCurso::seleccionarEjercicio(int idEjercicio) {
    // Implementación pendiente
}

set<DTEjercicio> IControladorCurso::seleccionarEjerciciosDeCurso(string curso) {
    // Implementación pendiente
    return set<DTEjercicio>();
}

set<string> IControladorCurso::consultarSuscripciones(string nick) {
    // Implementación pendiente
    return set<string>();
}

void IControladorCurso::suscribirUsuario(set<string> idiomas) {
    // Implementación pendiente
}

set<string> IControladorCurso::listarIdiomasSuscrito(string nick) {
    // Implementación pendiente
    return set<string>();
}

void IControladorCurso::eliminarSuscripciones(set<string> idiomas, string nick) {
    // Implementación pendiente
}

void IControladorCurso::limpiarDatos() {
    // Implementación pendiente
}

set<string> IControladorCurso::CursosInscriptoSinAprobar(string nick) {
    // Implementación pendiente
    return set<string>();
}