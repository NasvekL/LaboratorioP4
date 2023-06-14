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
}

ControladorUsuario::~ControladorUsuario() {
    delete datoProfesor;
    delete datoEstudiante;
    datoProfesor = NULL;
    datoEstudiante =NULL;
    // Destructor
}
//existeUsuario
bool ControladorUsuario::existeUsuario(string nick) {
    // Implementar la lógica para verificar si existe un usuario con el nickname recibido
        string claveBuscada = nick;
        auto iterador = usuarios.find(claveBuscada);
        if (iterador != usuarios.end()) {
            return true;
        } else {
            return false;
        }
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

set<string> ControladorUsuario::listarProfe() {
    auto it = usuarios.begin();
    Usuario* prof = new Usuario;
    for (it; it != usuarios.end(); it++){
        prof = it->second;
        cout<<"gola"<<endl;
        if (dynamic_cast<const Profesor*>(prof) != nullptr) {
        cout<<it->first<<endl;
        }
    }
    delete prof;
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
        Estudiante *e = new Estudiante(datoEstudiante->getNickname(),datoEstudiante->getContrasenia(), datoEstudiante->getNombre(),datoEstudiante->getDescripcion(),datoEstudiante->getPais(),datoEstudiante->getNacimiento());
        usuarios.insert(std::make_pair(e->getNick(), e));
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
        Profesor* p = new Profesor(datoProfesor->getNickname(),datoProfesor->getContrasenia(),datoProfesor->getNombre(), datoProfesor->getDescripcion(), datoProfesor->getInstituto(),Idiomas);
        usuarios.insert(std::make_pair(p->getNick(), p));
        datoProfesor = NULL;
    }
    else{
        throw invalid_argument("No se ha ingresado un usuario");
    }
}


void ControladorUsuario::listarIdiomas() {
 ControladorCurso& cc = ControladorCurso::getInstancia();
 cc.listarIdiomas();
}
string ControladorUsuario::getTipoUsuario(string nick) {
    auto it = usuarios.find(nick);
    if (it != usuarios.end()) {
        Usuario* usuario = it->second;
        if (Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario)) {
            return "estudiante";
        } else {
            return "profesor";
        }
    } else {
        throw std::invalid_argument("No existe el usuario");
    }
}
list<string> ControladorUsuario::consultarUsuario(){
    list<string> us;
    if (!usuarios.empty()){
    auto it = usuarios.begin();
    int i=1;
    while (it != usuarios.end()){
    us.push_back(it->first);
    it++;
    }
    }
    return us;
}

void ControladorUsuario::seleccionarUsuario(string nick){
   auto it = usuarios.find(nick);
   Usuario* usuario = it->second;
   if (dynamic_cast<Estudiante*>(usuario)){
       Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario);
       DTEstudiante dt = estudiante->getDTEstudiante();
       setDatoEstudiante(dt);
   }
   else if (dynamic_cast<Profesor*>(usuario)!=NULL){
       Profesor* profesor = dynamic_cast<Profesor*>(usuario);
       DTProfesor dt = profesor->getDTProfesor();
       setDatoProfesor(dt);
       }
}