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
    datoDeCurso=NULL;
    datoDeLeccion=NULL;
    profesor = NULL;
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
map<string,Curso*> ControladorCurso::getCursos(){
    return cursos;
}
int ControladorCurso:: getIdEjercicio (){
    return idEjercicio;
}
DTCurso ControladorCurso::getDatoDeCurso() {
    return *datoDeCurso;
}
list<DTLeccion> ControladorCurso::getDatosLecciones() {
    return datosLecciones;
}   
DTLeccion ControladorCurso::getDatosDeLeccion() {
    return *datoDeLeccion;
}
Profesor* ControladorCurso::getProfesor(){
    return profesor;
}

string ControladorCurso::getDatoIdioma() {
    return datoIdioma;
}
map<string,Curso*> ControladorCurso::getDatosPrevias() {
    return datosPrevias;
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
int ControladorCurso::getNumeroDeLeccion(string cursoSeleccionado){
    return cursos.find(cursoSeleccionado)->second->getLecciones().size();
}
//Setters
void ControladorCurso::setDatoDeLeccion(DTLeccion datos) {
    datoDeLeccion = new DTLeccion(datos.getNumero(),datos.getCantidadDeEjercicios(),datos.getObjetivoAprendizaje(),datos.getTema());
}
//no se si funcionaran bien, pasa todo por referencia
void ControladorCurso:: setIdEjercicio(int id){
    idEjercicio = id;
}
void ControladorCurso::setDatoDeCurso(DTCurso datos) {
    datoDeCurso = new DTCurso(datos.getNombre(),datos.getHabilitado(),datos.getNivel(),datos.getDescripcion(),datos.getPrevias());
}
void ControladorCurso::setDatosDeLeccion(DTLeccion datos) {
    datosLecciones.push_back(datos);
}
void ControladorCurso::setProfesor(Profesor* profesor) {
    this->profesor = profesor;
}
void ControladorCurso::setDatoIdioma(string idioma) {
    this->datoIdioma = idioma;
}
void ControladorCurso::setDatosPrevias(set<Curso*> previas) {

}
//Precondicion: solucion de traduccion viene como null
void ControladorCurso::setDatosEjercicioCompletarPalabras(DTRellenarPalabras datos) {
    datosRellenar = &datos;
}
//Precondicion: solucion de compPal viene como null
void ControladorCurso::setDatosEjercicioTraduccion(DTTraduccion datos) {
    datosTraducir = &datos;
}


void ControladorCurso::seleccionIdioma(string idi){
    datoIdioma = idi;
}
//Operaciones para modificar el set de cursos
bool ControladorCurso::altaCurso() {
    auto it = idiomas.find(datoIdioma);
    Idioma* idi = it->second;
    Curso* cur =NULL;
    if(!datosPrevias.empty())
    for(auto iter=datoDeCurso->getPrevias()->begin(); iter!=datoDeCurso->getPrevias()->end(); iter++){
        Curso* curso =cursos.find(*iter)->second;
        datosPrevias.insert(std::make_pair(*iter,curso));
    }
    cur = new Curso(datoDeCurso->getNombre(),datoDeCurso->getDescripcion(),datoDeCurso->getNivel(),datosPrevias,idi,profesor,datosRellenarPalabras,datosTraduccion,datosLecciones);
    cursos.insert(std::make_pair(datoDeCurso->getNombre(), cur));
    profesor->agregarCurso(cur);
    for(auto iter=cur->getLecciones().begin(); iter!=cur->getLecciones().end(); iter++){
        for(auto it = (*iter)->getEjercicios().begin(); it!=(*iter)->getEjercicios().end(); it++){
            ejercicios.insert(std::make_pair(it->second->getIdEjercicio(), it->second));
        }
    }
    datosPrevias.clear();
    datosRellenarPalabras.clear();
    datosTraduccion.clear();
    datosLecciones.clear();
    delete datoDeCurso;
    datoDeCurso = NULL;

return cur!=NULL;
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
    Leccion *nuevaLec = new Leccion(datoDeLeccion->getTema(), datoDeLeccion->getObjetivoAprendizaje(), datoDeLeccion->getCantidadDeEjercicios(), datoDeLeccion->getNumero(),datosRellenarPalabras,datosTraduccion);
    auto iter = cursos.find(curso);
    Curso *cur = iter->second;
    cur->agregarLeccion(nuevaLec);
    datosTraduccion.clear();
    datosRellenarPalabras.clear();
    delete datoDeLeccion;
    datoDeLeccion = NULL;
}


void ControladorCurso::altaEjercicio(Leccion* lec){
 if(datosRellenar!=NULL){
    DTRellenarPalabras dt = getDatosRellenar();
    Ejercicio *ej = new RellenarPalabras(dt.getListaDePalabras(), dt.getIdEjercicio(), dt.getDescripcion(), dt.getLetra(),lec);
    lec->addEjercicio(ej);
    ejercicios.insert(std::make_pair(dt.getIdEjercicio(), ej));
    delete datosRellenar;
    datosRellenar = NULL;
}
else{
    DTTraduccion dt = getDatosTraduccion();
    Ejercicio *ej = new Traduccion(dt.getSolucion(), dt.getIdEjercicio(), dt.getDescripcion(), dt.getLetra(),lec);
    lec->addEjercicio(ej);
    ejercicios.insert(std::make_pair(dt.getIdEjercicio(), ej));
    delete datosTraducir;
    datosTraducir = NULL;
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
    Profesor* p = cu.encontrarProfesor(nick);
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
    set<string> nombresDeCursos;
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        nombresDeCursos.insert(it->first);
    }
    return nombresDeCursos;
}
set<DTCurso> ControladorCurso::listarDTCursos() {
    // Implementación pendiente
    return set<DTCurso>();
}

list<string> ControladorCurso::cursosDisponibles(string nick){
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    list<string> cursosDisponibles = list<string>();
    //Recorro cada curso del controlador (it es un curso en cada iteracion)
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        bool cursoHabilitado;
        bool estudianteYaEstaInscritoAlCurso = false;
        bool estudianteAproboLasPrevias = true;

        cursoHabilitado = it->second->getHabilitado();

        for(auto it2 = it->second->getInscripciones().begin(); it2 != it->second->getInscripciones().end(); ++it2){
            if((*it2)->getEstudiante()->getNick() == nick){
                estudianteYaEstaInscritoAlCurso = true;
            }
        }

        //Recorro las previas de cada curso (it2 es una previa en cada iteracion)
        for(auto it2 = it->second->getPrevias().begin(); it2 != it->second->getPrevias().end(); ++it2){
            estudianteAproboLasPrevias = false;
            //Recorro las inscripciones de cada previa (it3 es una inscripcion en cada iteracion)
            for(auto it3 = (*it2)->getInscripciones().begin(); it3 != (*it2)->getInscripciones().end(); ++it3){
                if((*it3)->getEstudiante()->getNick() == nick){ //Si se encontro una inscripcion del estudiante en la previa
                    if(!(*it3)->getAprobado()){ //Si el estudiante aprobo la previa
                        estudianteAproboLasPrevias = true;
                    }else{                      //Si el estudiante no aprobo la previa
                        estudianteAproboLasPrevias = false;
                    }
                    break;//se encontro la inscripcion del estudiante, asi que dejo de buscar en las inscripciones de la previa
                }
            }
            //Termine de recorrer las inscripciones de la previa. Si estudianteAproboLasPrevias sigue siendo false, significa que el estudiante
            //tiene una previa sin aprobar, asi que dejo de mirar, salgo del for de previas.
            if(!estudianteAproboLasPrevias){
                break;
            }
        }

        if(cursoHabilitado && !estudianteYaEstaInscritoAlCurso && estudianteAproboLasPrevias){
            cursosDisponibles.push_back(it->first);
        }
    }
    return cursosDisponibles;
}

void ControladorCurso::inscribirEstudianteACurso(string curso, string estudiante) {
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    
    DTFecha* fecha = new  DTFecha(21,6,2023);
    Inscripcion* inscri = new Inscripcion(*fecha, false, 0, nullptr);

    cu.agregarInscripcionAEstudiante(estudiante, inscri);
    cursos.find(curso)->second->agregarInscripcion(inscri);
}

set<Idioma*> ControladorCurso::listarIdiomasProfesor() {
    Profesor* p = getProfesor();
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    return cu.listarIdiomasProfesor(p);
}
void ControladorCurso::listarIdiomas(){
    int a=1;
    for (auto it = idiomas.begin(); it != idiomas.end(); ++it){
        string nombre = it->first;
        cout << a <<  "- " << nombre <<'\n';
        a++;
    }
}

list<string> ControladorCurso::listarCursosNoHabilitados(){
    int a=1;
    for (auto it = cursos.begin(); it != cursos.end(); ++it){
        if(!(it->second->getHabilitado())){
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
    if(datoDeCurso != nullptr){
        delete datoDeCurso;
    }
    if(datoDeLeccion != nullptr){
        delete datoDeLeccion;
    }
    if(profesor != nullptr){
        delete profesor;
    }
    if(datosRellenar != nullptr){
        delete datosRellenar;
    }
    if(datosTraducir!= nullptr){
        delete datosTraducir;
    }
}


//Operacion rara
void ControladorCurso::cursosInscriptoSinAprobar(string nick) {
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    cu.cursosInscriptosSinAprobar(nick);
    
}

set<DTLeccion> ControladorCurso:: ListarLecciones(string cursoLec){  //implementar
    //return set<DTLeccion>
}