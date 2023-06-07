#include "../../include/Controladores/ControladorUsuario.h"

ControladorUsuario* ControladorUsuario::instancia = nullptr;

ControladorUsuario& ControladorUsuario::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ControladorUsuario();
    }
    return *instancia;
}

ControladorUsuario::ControladorUsuario(){
    this->datoEstudiante = NULL;
    this->usuarios = NULL;
}

ControladorUsuario::~ControladorUsuario() {
    // Destructor
}

DTEstudiante ControladorUsuario::getDatoEstudiante() {
    return *datoEstudiante;
}

void ControladorUsuario::setDatoEstudiante(DTEstudiante dato) {
    datoEstudiante = new DTEstudiante(dato);
}

list<string> ControladorUsuario::listarCursos() {
    // Implementar la lógica para listar los cursos
    // Retorna una lista de nombres de cursos
    list<string> cursos;
    // ...
    return cursos;
}

DTEstadisticaProfesor ControladorUsuario::estadisticasProfesor(string profesor) {
    // Implementar la lógica para obtener las estadísticas del profesor
    DTEstadisticaProfesor estadisticas;
    // ...
    return estadisticas;
}

DTEstadisticaEstudiante ControladorUsuario::estadisticasEstudiante(string estudiante) {
    // Implementar la lógica para obtener las estadísticas del estudiante
    DTEstadisticaEstudiante estadisticas;
    // ...
    return estadisticas;
}

list<DTProfesorSC> ControladorUsuario::listarProfesoresSinContra() {
    // Implementar la lógica para listar los profesores sin contraseña
    list<DTProfesorSC> profesores;
    // ...
    return profesores;
}

list<DTEstudianteSC> ControladorUsuario::listarEstudiantes() {
    // Implementar la lógica para listar los estudiantes
    list<DTEstudianteSC> estudiantes;
    // ...
    return estudiantes;
}

Usuario ControladorUsuario::obtenerSuscriptor(string user) {
    // Implementar la lógica para obtener el suscriptor
    Usuario suscriptor;
    // ...
    return suscriptor;
}

void ControladorUsuario::eliminarNotificaciones() {
    // Implementar la lógica para eliminar las notificaciones
    // ...
}

list<DTNotificacion> ControladorUsuario::consultarNotificaciones(string nick) {
    // Implementar la lógica para consultar las notificaciones de un usuario
    list<DTNotificacion> notificaciones;
    // ...
    return notificaciones;
}

// Implementa el resto de las funciones de la clase ControladorUsuario según sea necesario

DTEstadisticaCurso ControladorUsuario::estadisticaCurso(string curso) {
    // Implementar la lógica para obtener las estadísticas del curso
    DTEstadisticaCurso estadisticas;
    // ...
    return estadisticas;
}

Curso ControladorUsuario::obtenerCurso(string curso) {
    // Implementar la lógica para obtener el curso
    Curso cursoObtenido;
    // ...
    return cursoObtenido;
}
void ControladorUsuario::deleteDataIngresado()
{
}
list<DTEjercicio> ControladorUsuario::ejerciciosNoAprobados(string curso) {
    // Implementación de la función ejerciciosNoAprobados
}

list<string> ControladorUsuario::cursosInscriptosSinAprobar(string nick) {
    // Implementación de la función cursosInscriptosSinAprobar
}

list<string> ControladorUsuario::listarProfesores() {
    // Implementación de la función listarProfesores
}

list<string> ControladorUsuario::listarIdiomasProfesor(DTProfesor p) {
    // Implementación de la función listarIdiomasProfesor
}

Profesor ControladorUsuario::encontrarProfesor(string nick) {
    // Implementación de la función encontrarProfesor
}

void ControladorUsuario::confirmarAltaUsuario() {
    // Implementación de la función confirmarAltaUsuario
}


void ControladorUsuario::guardarDatosProfesor(DTProfesor data) {
    // Implementación de la función guardarDatosProfesor
}

void ControladorUsuario::guardarDatosEstudiante(DTEstudiante data) {
    
}

list<string> ControladorUsuario::listarIdiomas() {
}
