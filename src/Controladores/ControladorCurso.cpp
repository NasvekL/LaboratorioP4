#include "../../include/Controladores/ControladorCurso.h"

ControladorCurso* ControladorCurso::instancia = nullptr;

ControladorCurso::ControladorCurso() {
    // Constructor privado
    //Poner todas las variables en null
    this->datosDeCurso = nullptr;
    this->datosDeLeccion = nullptr;
    this->datoNombreDeProfesor = nullptr;
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
void ControladorCurso::setDatosEjercicioComletarpPalabras(DTEjercicio datos) {
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
    auto cursoBuscado = std::find_if(cursos.begin(), cursos.end(), [&](const Curso& curso) {
        return curso.getNombreCurso() == nombreCurso;
    });

    //verificar que el curso tenga al menos una leccion
    if(cursoBuscado->getLecciones().empty()){
        throw std::invalid_argument("El curso no tiene lecciones");
    }
    


    //Esta todo bastante dudoso este codigo. No se si funcionara
    // Crear un nuevo curso identico pero con habilitado true
    Curso nuevoCurso = *cursoBuscado; //aca se copia o se pasa la referencia? no c
    nuevoCurso.setHabilitado(true);
    // Eliminar el objeto anterior del conjunto
    cursos.erase(cursoBuscado);
    // Insertar el nuevo objeto en el conjunto
    cursos.insert(nuevoCurso);
}



//Operaciones para modificar el set de idiomas
bool ControladorCurso::altaIdioma() {
    // Implementación pendiente
    return false;
}



//Operaciones para modificar el set de ejercicios
void ControladorCurso::agregarEjercicio(DTEjercicio datos) {
    // Implementación pendiente
}



//Operaciones para obtener informacion

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
set<string> ControladorCurso::CursosInscriptoSinAprobar(string nick) {
    // Implementación pendiente
    return set<string>();
}