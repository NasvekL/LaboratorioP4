#include "../../include/Controladores/ControladorUsuario.h"
#include "../../include/Controladores/ControladorCurso.h"
ControladorUsuario* ControladorUsuario::instancia = nullptr;

ControladorUsuario& ControladorUsuario::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ControladorUsuario();
    }
    return *instancia;
}

ControladorUsuario::ControladorUsuario(){
    this->datoProfesor = NULL;
    this->datoEstudiante = NULL;
    this->usuarios = NULL;
}

ControladorUsuario::~ControladorUsuario() {
    // Destructor
}

//existeUsuario
bool ControladorUsuario::existeUsuario(string nick) {
    // Implementar la lógica para verificar si existe un usuario con el nickname recibido
    if(usuarios!=NULL){
        string claveBuscada = nick;
        auto iterador = usuarios->find(claveBuscada);
        if (iterador != usuarios->end()) {
            return true;
        } else {
            return false;
        }
    }
    return false;

    //return false;
}

DTEstudiante ControladorUsuario::getDatoEstudiante() {
    return *datoEstudiante;
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

void ControladorUsuario::setDatoEstudiante(DTEstudiante dato){
    *datoEstudiante=dato;
}
void ControladorUsuario::setDatoProfesor(DTProfesor dato){
    *datoProfesor=dato;
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
    ControladorCurso& cc = ControladorCurso::getInstancia();
    if (datoEstudiante!=NULL){
        Estudiante e = Estudiante(datoEstudiante->getNickname(),datoEstudiante->getContrasenia(), datoEstudiante->getNombre(),datoEstudiante->getDescripcion(),datoEstudiante->getPais(),datoEstudiante->getNacimiento());
        usuarios->insert(pair<string, Usuario>(datoEstudiante->getNickname(), e));
    }
    else if (datoProfesor!=NULL){
        set<Idioma*> Idiomas;
        set<string>* Sidiomas = datoProfesor->getIdiomas();
        set<string>::iterator it;
        for (it=Sidiomas->begin(); it!=Sidiomas->end(); ++it){
            string current = *it;
            Idioma idiom = cc.getIdioma(current);
            Idiomas.insert(&idiom);
        }
        Profesor p = Profesor(datoProfesor->getNickname(),datoProfesor->getContrasenia(),datoProfesor->getNombre(), datoProfesor->getDescripcion(), datoProfesor->getInstituto(),Idiomas);
        usuarios->insert(pair<string, Usuario>(datoProfesor->getNickname(), p));
    }
    else{
        throw invalid_argument("No se ha ingresado un usuario");
    }
    
}


void ControladorUsuario::listarIdiomas() {
 set<string> res;
 ControladorCurso& cc = ControladorCurso::getInstancia();
 cc.listarIdiomas();
}

void ControladorUsuario::consultarUsuario(){
    auto it = usuarios->begin();
    int i=1;
    while (it != usuarios->end()){
        cout<< to_string(i) + to_string(': ') + it->first <<endl;
    }
}