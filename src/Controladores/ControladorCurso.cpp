#include "../../include/Controladores/ControladorCurso.h"
#include "../../include/Controladores/ControladorUsuario.h"

ControladorCurso* ControladorCurso::instancia = nullptr;

ControladorCurso& ControladorCurso::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ControladorCurso();
    }
    return *instancia;
}
ControladorCurso::ControladorCurso(){
    datosDeCurso=NULL;
    datosDeLeccion=NULL;
    datoNombreDeProfesor=NULL;
    datoIdioma=NULL;
    datosPrevias=NULL;
    datosEjercicio=NULL;
}
//Creo que no es necesario borrar los sets atributos ya que no son punteros, con lo cual deberian borrarse solos
ControladorCurso::~ControladorCurso() {
    //Borra todos los DTs temporales
    limpiarDatos();
    //Elimina la instancia
    if(instancia != nullptr){
        delete instancia;
    }
}
//Getters
Curso ControladorCurso::getCurso(string nick) {

}
Idioma ControladorCurso::getIdioma(string nombre){
    return idiomas[nombre];
}

DTCurso ControladorCurso::getDatosDeCurso() {
    return *datosDeCurso;
}
DTLeccion ControladorCurso::getDatosDeLeccion() {
    return *datosDeLeccion;
}
string ControladorCurso::getDatoNombreDeProfesor() {
    return *datoNombreDeProfesor;
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
//no se si funcionaran bien, pasa todo por referencia
void ControladorCurso::setDatosDeCurso(DTCurso datos) {
    datosDeCurso = &datos;
}
void ControladorCurso::setDatosDeLeccion(DTLeccion datos) {
    datosDeLeccion = &datos;
}
void ControladorCurso::setDatoNombreDeProfesor(string nombreProfesor) {
    datoNombreDeProfesor = &nombreProfesor;
}
void ControladorCurso::setDatoIdioma(string idioma) {
    this->datoIdioma = &idioma;
}
void ControladorCurso::setDatosPrevias(set<DTCurso*> previas) {
    datosPrevias = &previas;
}
//Precondicion: solucion de traduccion viene como null
void ControladorCurso::setDatosEjercicioCompletarPalabras(DTEjercicio datos) {
    datosEjercicio = &datos;
}
//Precondicion: solucion de compPal viene como null
void ControladorCurso::setDatosEjercicioTraduccion(DTEjercicio datos) {
    datosEjercicio = &datos;
}



//Operaciones para modificar el set de cursos
bool ControladorCurso::altaCurso() {
    // Implementación pendiente
    return false;
}
void ControladorCurso::eliminarCurso(string nombreCurso) {
    // Implementación pendiente
}
void ControladorCurso::habilitarCurso(string nombreCurso) {
     // Buscar el objeto con el nombre buscado

    

}



//Operaciones para modificar el set de idiomas
bool ControladorCurso::confirmarAltaIdioma(string idioma) {
    // Agregar elementos al mapa

    // Buscar un elemento en el mapa por clave
    string claveBuscada = idioma;
    auto iterador = idiomas.find(claveBuscada);
    if (iterador != idiomas.end()) {
        return false;
    } else {
        Idioma id=Idioma(idioma);
        idiomas.insert(std::make_pair(idioma, id));
        return true;
    }
}

void altaLeccion(){

}



//Operaciones para modificar el set de ejercicios
void ControladorCurso::agregarEjercicio(DTEjercicio datos) {
    // Implementación pendiente
}



//Operaciones para obtener informacion

set<string> ControladorCurso::listarProfe() {
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    cu.listarProfe();
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
void ControladorCurso::listarIdiomas(){
    int a=1;
    for (auto it = idiomas.begin(); it != idiomas.end(); ++it){
        string nombre = it->first;
        cout << a <<  "- " << nombre <<'\n';
        a++;
    }
}

void ControladorCurso::listarCursosNoHabilitados(){
     int a=1;
    for (auto it = cursos.begin(); it != cursos.end(); ++it){
        if(it->second.getHabilitado()){
            string nombre = it->first;
            cout << a <<  "- " << nombre <<'\n';
            a++;
        }
        
    }
}

bool ControladorCurso::solucionCorrectaCompletarPalabras(set<string> solucion, string estudiante, int IdEjercicio) {
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



//Operaciones de suscripciones
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



//Otras operaciones
void ControladorCurso::limpiarDatos() {
    if(datosDeCurso != nullptr){
        delete datosDeCurso;
    }
    if(datosDeLeccion != nullptr){
        delete datosDeLeccion;
    }
    if(datoNombreDeProfesor != nullptr){
        delete datoNombreDeProfesor;
    }
    if(datoIdioma != nullptr){
        delete datoIdioma;
    }
    if(datosPrevias != nullptr){
        delete datosPrevias;
    }
    if(datosEjercicio != nullptr){
        delete datosEjercicio;
    }
}



//Operacion rara
set<string> ControladorCurso::cursosInscriptoSinAprobar(string nick) {
    // Implementación pendiente
    return set<string>();
}