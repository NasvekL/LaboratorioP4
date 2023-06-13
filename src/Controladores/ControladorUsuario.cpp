#include "../../include/Controladores/ControladorUsuario.h"
#include "../../include/Controladores/ControladorCurso.h"

ControladorUsuario* ControladorUsuario::instancia = nullptr;
map<string,Usuario>* usuarios = NULL;


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
map<string,Usuario>* ControladorUsuario::getUsuarios(){
    if(usuarios!=NULL){
        return usuarios;
    }
    else{
        usuarios = new map<string,Usuario>();
        return usuarios;
    }
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

}

DTEstudiante ControladorUsuario::getDatoEstudiante() {
    return *datoEstudiante;
}
DTProfesor ControladorUsuario::getDatoProfesor() {
    return *datoProfesor;
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
    datoEstudiante = new DTEstudiante(dato); // Asignar una copia del objeto al puntero}
}
void ControladorUsuario::setDatoProfesor(DTProfesor dato){
    datoProfesor = new DTProfesor(dato); // Asignar una copia del objeto al puntero
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
        cout <<datoEstudiante->getNickname() << endl; 
        map<string,Usuario>* users = getUsuarios();
        Estudiante e = Estudiante(datoEstudiante->getNickname(),datoEstudiante->getContrasenia(), datoEstudiante->getNombre(),datoEstudiante->getDescripcion(),datoEstudiante->getPais(),datoEstudiante->getNacimiento());
        users->insert(pair<string, Usuario>(datoEstudiante->getNickname(), e));
        delete datoEstudiante;
        datoEstudiante = NULL;
    }
    else if (datoProfesor!=NULL){
        set<Idioma*> Idiomas;
        set<string>* Sidiomas = datoProfesor->getIdiomas();
        auto it = Sidiomas->begin();
        cout << *it << endl;
        for (it; it!=Sidiomas->end(); ++it){
            string current = *it;
            Idioma idiom = cc.getIdioma(current);
            Idiomas.insert(&idiom);
        }
        map<string,Usuario>* users = getUsuarios();
        Profesor p = Profesor(datoProfesor->getNickname(),datoProfesor->getContrasenia(),datoProfesor->getNombre(), datoProfesor->getDescripcion(), datoProfesor->getInstituto(),Idiomas);
        users->insert(pair<string, Usuario>(datoProfesor->getNickname(), p));
        delete datoProfesor;
        datoProfesor = NULL;
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
    map<string,Usuario>* users= getUsuarios();
    auto it = users->begin();
    int i=1;
    if (users->empty()){
        cout << "No hay usuarios" << endl;
    }
    else{
        while (it != users->end()){
        cout<< to_string(i) + to_string(': ') + it->first <<endl;
        }
    }
}
void ControladorUsuario::seleccionarUsuario(string nick){
    
}