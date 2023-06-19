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

Usuario* ControladorUsuario::getUsuario(string nick){
    auto iter = usuarios.find(nick);
    Usuario* user = iter->second; 
    return user;
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
    auto it = usuarios.find(profesor);
    Profesor* profe = dynamic_cast<Profesor*>(it->second);
    list<Curso*> cursos = profe->getCursos();
    map<string, int> promPorcentajesCursos;
    for (Curso* curso : cursos) {
        int promedio = 0;
        int inscriptos=0;
        for (Inscripcion* inscripcion : curso->getInscripciones()) {
            Progreso* progreso = inscripcion->getProg();
            promedio = promedio + progreso->getPorcentajeCurso();
            inscriptos++;
        }
        if(inscriptos!=0)
            promedio = promedio / inscriptos;
        promPorcentajesCursos.insert(std::make_pair(curso->getNombreCurso(), promedio));
    }



    DTEstadisticaProfesor estadisticas = DTEstadisticaProfesor(promPorcentajesCursos);
    // ...
    return estadisticas;
}

DTEstadisticaEstudiante ControladorUsuario::estadisticasEstudiante(string estudiante) {
    // Implementar la lógica para obtener las estadísticas del estudiante
    auto it = usuarios.find(estudiante);
    Estudiante* estu = dynamic_cast<Estudiante*>(it->second);
    list<Inscripcion*> inscripciones = estu->getInscripciones();
    map<string, int> estad;
    for (Inscripcion* inscripcion : inscripciones) {
        Curso* curso = inscripcion->getInscriptoA();
        Progreso* prog = inscripcion->getProg();
        int porcentaje = prog->getPorcentajeCurso();
        estad[curso->getNombreCurso()] = porcentaje;
    }
    DTEstadisticaEstudiante estadisticas = DTEstadisticaEstudiante(estad);

    
    // ...
    return estadisticas;
}

void ControladorUsuario::setDatoEstudiante(DTEstudiante dato){
    datoEstudiante = new DTEstudiante(dato.getNickname(),dato.getContrasenia(),dato.getNombre(),dato.getDescripcion(),dato.getPais(),dato.getNacimiento()); // Asignar una copia del objeto al puntero}
}
void ControladorUsuario::setDatoProfesor(DTProfesor dato){
    datoProfesor = new DTProfesor(dato.getNickname(),dato.getContrasenia(),dato.getNombre(),dato.getDescripcion(),dato.getInstituto(),dato.getIdiomas()); // Asignar una copia del objeto al puntero
}
list<DTProfesorSC> ControladorUsuario::listarProfesoresSinContra() {
    // Implementar la lógica para listar los profesores sin contraseña
    list<DTProfesorSC> profesores;
    // ...
    return profesores;
}
list<string> ControladorUsuario::listarUsuarios() {
    // Implementar la lógica para listar los usuarios
    list<string> users;
    for(auto iter=usuarios.begin(); iter!=usuarios.end(); iter++){
        users.push_back(iter->second->getNick());
    }
    // ...
    return users;
}
list<DTEstudianteSC> ControladorUsuario::listarEstudiantes() {
    // Implementar la lógica para listar los estudiantes
    list<DTEstudianteSC> estudiantes;

    for (const auto& usuario : usuarios) {
        string tipoUsuario = getTipoUsuario(usuario.first);
        if (tipoUsuario == "estudiante") {
            Estudiante* estudiante = dynamic_cast<Estudiante*>(usuario.second);
            DTEstudianteSC estu =  DTEstudianteSC(estudiante->getNick(), estudiante->getNombre(), estudiante->getDescripcion(), estudiante->getPais() , estudiante->getNacimiento());
            estudiantes.push_back(estu);
        }
    }
    // ...
    return estudiantes;
}

Usuario* ControladorUsuario::obtenerSuscriptor(string user) {
    // Implementar la lógica para obtener el suscriptor
    Usuario* suscriptor;
    // ..
    return suscriptor;
}

void ControladorUsuario::eliminarNotificaciones(string nick) {
    Usuario* user = getUsuario(nick);
    user->eliminarNotificaciones();
    }

list<DTNotificacion> ControladorUsuario::consultarNotificaciones(string nick) {
    // Implementar la lógica para consultar las notificaciones de un usuario
    Usuario* user =getUsuario(nick);
    list<DTNotificacion> notis = user->getNotificaciones();
    return notis;    // ...
}

// Implementa el resto de las funciones de la clase ControladorUsuario según sea necesario

DTEstadisticaCurso ControladorUsuario::estadisticaCurso(string curso) {
    // Implementar la lógica para obtener las estadísticas del curso
    DTEstadisticaCurso estadisticas;
    // ...
    return estadisticas;
}

Curso* ControladorUsuario::obtenerCurso(string curso) {
    DTEstudiante est = getDatoEstudiante();
    string nick = est.getNickname();
    auto it = usuarios.begin();
    Estudiante* estudiante = NULL;
    for(it; it!=usuarios.end(); it++){
        if(it->first == nick){
            estudiante = dynamic_cast<Estudiante*>(it->second);
        } 
    }
    return estudiante->buscarCurso(curso);
}

void ControladorUsuario::deleteDataIngresado(){
    if (datoEstudiante!=NULL){
        delete datoEstudiante;
        datoEstudiante = NULL;
    }
    else if (datoProfesor!=NULL){
        delete datoProfesor;
        datoProfesor = NULL;
    }
}
list<DTEjercicio> ControladorUsuario::ejerciciosNoAprobados(string curso) {
    DTEstudiante est = getDatoEstudiante();
    string nick = est.getNickname();
    Estudiante* estudiante = encontrarEstudiante(nick);
    return estudiante->ejerciciosNoAprobados(curso);
}

set<string> ControladorUsuario::cursosInscriptosSinAprobar(string nick) {
    //Buscarlo

    //Setearlo
    Estudiante* estudiante = encontrarEstudiante(nick);
    DTEstudiante dt = estudiante->getDTEstudiante();
    setDatoEstudiante(dt);
    //Trabajo
    return estudiante->getCursosInscriptosSA();
}

list<string> ControladorUsuario::listarProfe() {
    list<string> listaProfes;
    for (auto it = usuarios.begin(); it != usuarios.end(); it++) {
        if (getTipoUsuario(it->first) == "profesor") {
            listaProfes.push_back(it->second->getNick());
        }
    }
    return listaProfes;
}

set<Idioma*> ControladorUsuario::listarIdiomasProfesor(Profesor* p) {
    set<Idioma*> SIdiomas = p->getIdiomas();
    return SIdiomas;
}


void ControladorUsuario::agregarInscripcionAEstudiante(string estudiante, Inscripcion* inscri) {
    encontrarEstudiante(estudiante)->agregarInscripcion(inscri);
}

Estudiante* ControladorUsuario::encontrarEstudiante(string nick) {
    auto it = usuarios.find(nick);
    Estudiante* e = dynamic_cast<Estudiante*>(it->second);
    return e;  
}

Profesor* ControladorUsuario::encontrarProfesor(string nick) {
    auto it = usuarios.find(nick);
    Profesor* p = dynamic_cast<Profesor*>(it->second);
    return p;  
}




void ControladorUsuario::confirmarAltaUsuario() {
    // Implementación de la función confirmarAltaUsuario
    ControladorCurso& cc = ControladorCurso::getInstancia();
    if (datoEstudiante!=NULL){
        Estudiante *e = new Estudiante(datoEstudiante->getNickname(),datoEstudiante->getContrasenia(), datoEstudiante->getNombre(),datoEstudiante->getDescripcion(),datoEstudiante->getPais(),datoEstudiante->getNacimiento());
        usuarios.insert(std::make_pair(e->getNick(), e));
        delete datoEstudiante;
        datoEstudiante = NULL;
    }
    else if (datoProfesor!=NULL){
        set<Idioma*> Idiomas;
        set<string> Sidiomas = datoProfesor->getIdiomas();
        auto it = Sidiomas.begin();
        for (it; it!=Sidiomas.end(); ++it){
            string current = *it;
            Idioma* idiom = cc.getIdioma(current);
            Idiomas.insert(idiom);
        }
        Profesor* p = new Profesor(datoProfesor->getNickname(),datoProfesor->getContrasenia(),datoProfesor->getNombre(), datoProfesor->getDescripcion(), datoProfesor->getInstituto(),Idiomas);
        usuarios.insert(std::make_pair(p->getNick(), p));
        delete datoProfesor;
        datoProfesor = NULL;
    }
    else{
        throw invalid_argument("No se ha ingresado un usuario");
    }
}


list<string> ControladorUsuario::listarIdiomas() {
 ControladorCurso& cc = ControladorCurso::getInstancia();
 return cc.listarIdiomas();
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
void ControladorUsuario::limpiarDatos(){
    if(datoEstudiante!=NULL){
        delete datoEstudiante;
        datoEstudiante = NULL;
    }
    else if(datoProfesor!=NULL){
        delete datoProfesor;
        datoProfesor = NULL;
    }
}