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
    profesor = NULL;
    datosPrevias=NULL;
    datosRellenar=NULL;
    datosTraducir=NULL;
    idEjercicio=0;
    //datosTraduccion = NULL; ?????
    //datosRellenarPalabras = NULL;

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
    //return cursos.find(nick);
}
Idioma* ControladorCurso::getIdioma(string nombre){
    string claveBuscada = nombre;
    auto iterador = idiomas.find(claveBuscada);
    if (iterador != idiomas.end()) {
        return iterador->second;
    }
    else return nullptr;
}
int ControladorCurso:: getIdEjercicio (){
    return idEjercicio;
}
DTCurso ControladorCurso::getDatosDeCurso() {
    return *datosDeCurso;
}
DTLeccion ControladorCurso::getDatosDeLeccion() {
    return *datosDeLeccion;
}
Profesor* ControladorCurso::getProfesor(){
    return profesor;
}

string ControladorCurso::getDatoIdioma() {
    return datoIdioma;
}
map<string,DTCurso*>* ControladorCurso::getDatosPrevias() {
}
DTRellenarPalabras ControladorCurso::getDatosRellenar() {
    return *datosRellenar
;
}
DTTraduccion ControladorCurso::getDatosTraduccion() {
    return *datosTraducir;
}

list<DTRellenarPalabras> ControladorCurso::getDatosMuchasRellenarPalabras(){
    return datosRellenarPalabras;
}


list<DTTraduccion> ControladorCurso::getDatosMuchasTraducciones(){
    return datosTraduccion;
}

//Setters
//no se si funcionaran bien, pasa todo por referencia
void ControladorCurso:: setIdEjercicio(int id){
    idEjercicio = id;
}
void ControladorCurso::setDatosDeCurso(DTCurso datos) {
    datosDeCurso = &datos;
}
void ControladorCurso::setDatosDeLeccion(DTLeccion datos) {
    datosDeLeccion = &datos;
}
void ControladorCurso::setProfesor(Profesor profesor) {
    Profesor* p = &profesor;
    this->profesor = p;
}
void ControladorCurso::setDatoIdioma(string idioma) {
    this->datoIdioma = idioma;
}
void ControladorCurso::setDatosPrevias(set<DTCurso*> previas) {

}
//Precondicion: solucion de traduccion viene como null
void ControladorCurso::setDatosEjercicioCompletarPalabras(DTRellenarPalabras datos) {
    datosRellenar = &datos;
}
//Precondicion: solucion de compPal viene como null
void ControladorCurso::setDatosEjercicioTraduccion(DTTraduccion datos) {
    datosTraducir = &datos;
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
    cursos.find(nombreCurso)->second->setHabilitado(true);
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
        Idioma* id=new Idioma(idioma);
        idiomas.insert(std::make_pair(idioma, id));
        return true;
    }
}

void ControladorCurso::altaLeccion(string curso){
    Leccion *nuevaLec = new Leccion(datosDeLeccion->getTema(), datosDeLeccion->getObjetivoAprendizaje(), datosDeLeccion->getCantidadDeEjercicios(), datosDeLeccion->getNumero());
    auto iterator = cursos.find(curso);
    //Curso *cur = *iterador;
    //cur->agregarLeccion(nuevaLec);
    

    //Asocio a sus ejercicios
    for (int i = 1; i <= datosDeLeccion->getCantidadDeEjercicios(); i++){
        /*if(datosRellenarPalabras != nullptr){
            DTRellenarPalabras dt = datosRellenarPalabras.front();
            datosRellenarPalabras.pop_front();
            Ejercicio *ej = new RellenarPalabras(dt.getListaDePalabras(), dt.getIdEjercicio(), dt.getDescripcion(), dt.getLetra(),lec);
            nuevaLec->addEjercicio(ej);
            ejercicios.insert(std::make_pair(dt.getIdEjercicio(), ej));

        }else{
            DTTraduccion dt = datosTraduccion.front();
            datosTraduccion.pop_front();
            Ejercicio *ej = new Traduccion(dt.getSolucion(), dt.getIdEjercicio(), dt.getDescripcion(), dt.getLetra(),lec);
            nuevaLec->addEjercicio(ej);
            ejercicios.insert(std::make_pair(dt.getIdEjercicio(), ej));
        }    */
    }
}


void ControladorCurso::altaEjercicio(Leccion* lec){
 if(datosRellenar!=NULL){
    DTRellenarPalabras dt = getDatosRellenar();
    Ejercicio *ej = new RellenarPalabras(dt.getListaDePalabras(), dt.getIdEjercicio(), dt.getDescripcion(), dt.getLetra(),lec);
    lec->addEjercicio(ej);
    ejercicios.insert(std::make_pair(dt.getIdEjercicio(), ej));
}
else{
    DTTraduccion dt = getDatosTraduccion();
    Ejercicio *ej = new Traduccion(dt.getSolucion(), dt.getIdEjercicio(), dt.getDescripcion(), dt.getLetra(),lec);
    lec->addEjercicio(ej);
    ejercicios.insert(std::make_pair(dt.getIdEjercicio(), ej));
}
}

//Operaciones para modificar el set de ejercicios
void ControladorCurso::agregarEjercicio(DTEjercicio datos) {
    
}

void ControladorCurso::agregarDatosRellenarPalabras(DTRellenarPalabras ejRellPal){
    datosRellenarPalabras.push_back(ejRellPal);
};
void ControladorCurso::agregarDatosTraduccion(DTTraduccion tradu){
    datosTraduccion.push_back(tradu);
};

//Operaciones para obtener informacion
void ControladorCurso::seleccionarProfesor(string nick){
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    Profesor p = cu.encontrarProfesor(nick);
    setProfesor(p);
}

list<string> ControladorCurso::listarProfe() {
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    return cu.listarProfe();
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
    Profesor* p = getProfesor();
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    cu.listarIdiomasProfesor(*p);
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
        if(it->second->getHabilitado()){
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
    if(profesor != nullptr){
        delete profesor;
    }
    if(datosPrevias != nullptr){
        delete datosPrevias;
    }
    if(datosRellenar != nullptr){
        delete datosRellenar;
    }
    if(datosTraducir!= nullptr){
        delete datosTraducir;
    }
}


//Operacion rara
set<string> ControladorCurso::cursosInscriptoSinAprobar(string nick) {
    // Implementación pendiente
    return set<string>();
}

set<DTLeccion> ControladorCurso:: ListarLecciones(string cursoLec){  //implementar
    //return set<DTLeccion>
}