#include "../../include/Controladores/ControladorCurso.h"
#include "../../include/Controladores/ControladorUsuario.h"

ControladorCurso* ControladorCurso::instancia = nullptr;

ControladorCurso& ControladorCurso::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ControladorCurso();
    }
    return *instancia;
}
ControladorCurso::ControladorCurso() : datosPrevias(), datosLecciones(), datosRellenarPalabras(), datosTraduccion(){
    datoDeCurso=NULL;
    datoDeLeccion=NULL;
    profesor = NULL;
    curso = NULL;
    datosRellenar=NULL;
    datosTraducir=NULL;
    idEjercicio=0;
    ejercicio=NULL;
    datoIdioma="";
    nickUsuario="";

}
ControladorCurso::~ControladorCurso() {
    //Borra todos los DTs temporales
    limpiarDatos();
    //Elimina la instancia
    if(instancia != nullptr){
        delete instancia;
    }
}
//Getters
Curso* ControladorCurso::getCurso(string nick) {
    auto iter = cursos.find(nick);
    return iter->second;
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

Curso* ControladorCurso::getCursoEnMemoria(){
    return curso;
}

Ejercicio* ControladorCurso::getEjercicioEnMemoria(){
    return ejercicio;
}

Ejercicio* ControladorCurso::getEjercicioPorIdDesdeMapa(int id){
    return ejercicios[id];
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

string ControladorCurso::getNickUsuario(){
    return nickUsuario;
}
//Setters
void ControladorCurso:: eliminarDePrevias(Curso* curso){
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        it->second->eliminarPrevia(curso);
    }
}
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

void ControladorCurso::setCursoEnMemoria(Curso* curso) {
    this->curso = curso;
}

void ControladorCurso::setEjercicioEnMemoria(Ejercicio* ejercicio) {
    this->ejercicio = ejercicio;
}

void ControladorCurso::setDatoIdioma(string idioma) {
    this->datoIdioma = idioma;
}
void ControladorCurso::setDatosPrevias(set<Curso*> previas) {

}
//Precondicion: solucion de traduccion viene como null
void ControladorCurso::setDatosEjercicioCompletarPalabras(DTRellenarPalabras datos) {
    datosRellenar = new DTRellenarPalabras(datos.getDescripcion(),datos.getLetra(),datos.getIdEjercicio(),datos.getListaDePalabras(),datos.getTipo(),datos.getNumLec());
}
//Precondicion: solucion de compPal viene como null
void ControladorCurso::setDatosEjercicioTraduccion(DTTraduccion datos) {
    datosTraducir = new DTTraduccion(datos.getDescripcion(),datos.getLetra(),datos.getIdEjercicio(),datos.getSolucion(),datos.getTipo(),datos.getNumLec());
}


void ControladorCurso::seleccionIdioma(string idi){
    datoIdioma = idi;
}

void ControladorCurso::setNickUsuario(string nick){
    this->nickUsuario = nick;
}
//Operaciones para modificar el set de cursos
bool ControladorCurso::altaCurso() {
    auto it = idiomas.find(datoIdioma);
    Idioma* idi = it->second;
    Curso* cur =NULL;
    if(!datoDeCurso->getPrevias().empty()){
        set<string> previas = datoDeCurso->getPrevias();
        for(auto iter=previas.begin(); iter!=previas.end(); iter++){
            Curso* curso =cursos.find(*iter)->second;
            datosPrevias.insert(std::make_pair(*iter,curso));
        }
    }
    cur = new Curso(datoDeCurso->getNombre(),datoDeCurso->getDescripcion(),datoDeCurso->getNivel(),datosPrevias,idi,profesor,datosRellenarPalabras,datosTraduccion,datosLecciones);
    cursos.insert(std::make_pair(datoDeCurso->getNombre(), cur));
    profesor->agregarCurso(cur);
    list<Leccion*> lecs = cur->getLecciones();
    for(auto iter=lecs.begin(); iter!=lecs.end(); iter++){
        map<int,Ejercicio*> ejs = (*iter)->getEjercicios();
        for(auto it = ejs.begin(); it!=ejs.end(); it++){
            ejercicios.insert(std::make_pair(it->second->getIdEjercicio(), it->second));
        }
        int tamanio = ejs.size();
        (*iter)->setCantidadEjercicios(tamanio);
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
    Curso* cur = getCurso(nombreCurso);
    cursos.erase(nombreCurso);
    list<Leccion*> lecsCur=cur->getLecciones();
    eliminarDePrevias(cur);
    for(auto iter=lecsCur.begin(); iter!=lecsCur.end(); iter++){
        map<int,Ejercicio*> ejsLec = (*iter)->getEjercicios();
        for(auto it = ejsLec.begin(); it!=ejsLec.end(); it++){
            ejercicios.erase(it->second->getIdEjercicio());
        }
    }
    delete cur;
}
bool ControladorCurso::habilitarCurso(string nombreCurso) {
    Curso* cur = getCurso(nombreCurso);
    if(cur->getLecciones().empty()){
    return false;
    }
    for(auto iter=cur->getLecciones().begin(); iter!=cur->getLecciones().end(); iter++){
        if((*iter)->getEjercicios().empty()){
            return false;
        }
    }
    cur->setHabilitado(true);
    Idioma * idi = cur->getIdiomaDelCurso();
    set<IObserver*> obs = idi->getObservers();
    DTNotificacion noti = DTNotificacion(cur->getNombreCurso(),idi);
    for(auto it = obs.begin(); it!=obs.end(); it++){
        (*it)->notificar(noti);
    }
    return true;
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
    Curso* cur = iter->second;
    cur->agregarLeccion(nuevaLec);
    if(!nuevaLec->getEjercicios().empty()){
        map<int, Ejercicio*> lista = nuevaLec->getEjercicios();
        for(auto it = lista.begin(); it != lista.end(); it++){
            ejercicios[it->second->getIdEjercicio()] =  it->second;
        }
    }
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
    Curso* cur = cursos.find(curso)->second;
    int promedio = 0;
    int inscriptos=0;
    for (Inscripcion* inscripcion : cur->getInscripciones()) {
        Progreso* progreso = inscripcion->getProg();
        promedio = promedio + progreso->getPorcentajeCurso();
        inscriptos++;
    }
    if(inscriptos!=0)
    promedio = promedio / inscriptos;
    DTEstadisticaCurso estadisticas = DTEstadisticaCurso(promedio, cur->getNombreCurso());

    return estadisticas;
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

//Devuelve una lista de triadas de cursos disponibles, cada uno contiene, en orden, el nombre del curso,
//la cantidad de lecciones y la cantidad de ejercicios
list<tuple<string, int, int>> ControladorCurso::cursosDisponibles(string nick){
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    list<tuple<string, int, int>> cursosDisponibles;
    
    //Recorro cada curso del controlador (it es un curso en cada iteracion)
    for(auto it = cursos.begin(); it != cursos.end(); ++it){
        bool cursoHabilitado;
        bool estudianteYaEstaInscritoAlCurso = false;
        bool estudianteAproboLasPrevias = true;

        cursoHabilitado = it->second->getHabilitado();

        if(it->second->getInscripciones().size() == 0){
            estudianteYaEstaInscritoAlCurso = false;
        }
        else{
            list<Inscripcion*> inscripcionesitass = it->second->getInscripciones();
            for(auto it2 = inscripcionesitass.begin(); it2 != inscripcionesitass.end(); ++it2){
                if((*it2)->getEstudiante()->getNick() == nick){
                    estudianteYaEstaInscritoAlCurso = true;
                }
            }
        }
        //Recorro las previas de cada curso (it2 es una previa en cada iteracion)
        if(it->second->getPrevias().size() == 0){
            estudianteAproboLasPrevias = true;
        }
        else{
            list <Curso*> previasitass = it->second->getPrevias();
            for(auto it2 = previasitass.begin(); it2 != previasitass.end(); ++it2){
                estudianteAproboLasPrevias = false;
                //Si la previa no tiene inscripciones, significa que nadie la aprobo, asi que el estudiante no la aprobo
                if((*it2)->getInscripciones().size() == 0){
                    estudianteAproboLasPrevias = false;
                    break;
                }
                else{
                    Inscripcion* inscripcio = nullptr;
                    //primero busco la inscripcion del estudiante en la previa
                    //Recorro las inscripciones de cada previa (it3 es una inscripcion en cada iteracion) y busco si el estudiante esta inscrito
                    list<Inscripcion*> inscripcionesitass = (*it2)->getInscripciones();
                    for(auto it3 = inscripcionesitass.begin(); it3 != inscripcionesitass.end(); ++it3){
                        if((*it3)->getEstudiante()->getNick() == nick){ //Si se encontro una inscripcion del estudiante en la previa
                            inscripcio = (*it3);
                            break;//se encontro la inscripcion del estudiante, asi que dejo de buscar en las inscripciones de la previa
                        }
                    }
                    if(inscripcio == nullptr){
                        estudianteAproboLasPrevias = false; //Si el estudiante no esta inscrito en la previa, no la aprobo
                        break; //Dejo de buscar en las previas del curso
                    }else{
                        if(inscripcio->getAprobado()){ //Si el estudiante aprobo la previa
                            estudianteAproboLasPrevias = true;
                        }else{                      //Si el estudiante no aprobo la previa
                            estudianteAproboLasPrevias = false;
                            break;//Dejo de buscar en las previas del curso
                        }
                    }
                }//fin if inscripciones previas size
            }//dejo de buscar en previas
        }

        if(cursoHabilitado && !estudianteYaEstaInscritoAlCurso && estudianteAproboLasPrevias){
            string nombreDelCursitoDisponible = it->first;
            int cantidadDeLecciones = it->second->cantidadDeLecciones();
            int cantidadDeEjercicios = it->second->cantidadDeEjercicios();
            cursosDisponibles.push_back(make_tuple(nombreDelCursitoDisponible, cantidadDeLecciones, cantidadDeEjercicios));
        }
    }
    return cursosDisponibles;
}

void ControladorCurso::agregarPrevia(string curso, string previa){
    cursos.find(curso)->second->agregarPrevia(cursos.find(previa)->second);
}

void ControladorCurso:: inscribirEstudianteACurso(string curso, string estudiante, int dia, int mes, int anio) {
    //Obtengo el controlador de usuario
    ControladorUsuario& cu = ControladorUsuario::getInstancia();

    //Creo DTFecha de la inscripcion
    DTFecha* fecha = new DTFecha(dia,mes,anio);

    //Obtengo la primera leccion del curso
    Curso* refACurso = cursos.find(curso)->second;
    list<Leccion*> lecciones = refACurso->getLecciones();
    Leccion* primeraLeccion = lecciones.front();

    //Creo el progreso con referencia a la leccion actual
    Progreso* progresoDeInscripcion = new Progreso(primeraLeccion);

    //Creo la inscripcion con referencia al progreso
    Inscripcion* inscri = new Inscripcion(*fecha, progresoDeInscripcion);

    //En el progreso pongo una referencia a la inscripcion
    progresoDeInscripcion->setInscripcion(inscri);

    //Agrego visibilidad entre inscripcion y estudiante
    cu.agregarInscripcionAEstudiante(estudiante, inscri);
    inscri->setEstudianteInscrito(cu.encontrarEstudiante(estudiante));
    
    //Agrego visibilidad entre inscripcion y leccion
    primeraLeccion->agregarProgreso(progresoDeInscripcion);

    //Agrego visibilidad entre inscripcion y curso
    cursos.find(curso)->second->agregarInscripcion(inscri);
    inscri->setInscripccionACurso(cursos.find(curso)->second);
}

set<Idioma*> ControladorCurso::listarIdiomasProfesor() {
    Profesor* p = getProfesor();
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    return cu.listarIdiomasProfesor(p);
}
list<string> ControladorCurso::listarIdiomas(){
    list<string> listita;
    for (auto it = idiomas.begin(); it != idiomas.end(); ++it){
        listita.push_back(it->first);
    }
    return listita;
}

list<string> ControladorCurso::listarCursosNoHabilitados(){
    int a=1;
    list<string> cursosNoHabilitados;
    for (auto it = cursos.begin(); it != cursos.end(); ++it){
        if(!(it->second->getHabilitado())){
            string nombre = it->first;
            cursosNoHabilitados.push_back(nombre);
        }
    }
return cursosNoHabilitados;
}

bool ControladorCurso::solucionCorrectaCompletarPalabras(list<string> solucion, string estudiante, int IdEjercicio) {
    Ejercicio* ej = getEjercicioEnMemoria();
    bool esCorrecta = ej->esCorrectoRellenarPal(solucion);
    Ejercicio* e = getEjercicioEnMemoria();
    Curso* cur = getCursoEnMemoria();                       //obtengo curso
    int cantidadDeLecciones = cur->getLecciones().size();   //obtengo cantidad de lecciones
    if(esCorrecta){                                       //si es correcta
        Leccion* lec = e->getLeccion();           //obtengo leccion
        int lecActual= lec->getNumero();      //obtengo numero de leccion
        Progreso* prog = lec->getProgresos().find(estudiante)->second;   //obtengo progreso
        int cant = lec->getCantidadDeEjercicios();   //obtengo cantidad de ejercicios
        prog->agregarEjercicioResuelto(e);                                //agrego ejercicio a ejercicios resueltos
        int ejResueltos = prog->getEjerciciosResueltos().size();  //obtengo cantidad de ejercicios resueltos
        if(cant == ejResueltos){
            lec->eliminarProgreso(estudiante);              //elimino progreso
            Inscripcion* ins = prog->getInscripcion();      //obtengo inscripcion
            if(cantidadDeLecciones==lec->getNumero()){      //si es la ultima leccion
                prog->setLeccionActual(NULL);        //seteo leccion actual a NULL
                ins->setAprobado();             //seteo inscripcion a aprobado
            }       
            else{       
                Leccion* lecSig;        //obtengo leccion siguiente
                ins->setLeccionActual(lecActual+1);         //seteo leccion actual
                list<Leccion*> lecciones = cur->getLecciones();     //obtengo lecciones
                for(auto it = lecciones.begin(); it != lecciones.end(); ++it){      //recorro lecciones
                    if((*it)->getNumero() == ins->getLeccionActual()){      //si es la leccion siguiente
                        lecSig = (*it);     //guardo leccion siguiente
                    }
                }
                lecSig->agregarProgreso(prog);
                prog->limpiarEjerciciosResueltos();     //limpio ejercicios resueltos
                prog->setLeccionActual(lecSig);     //seteo leccion actual
            }    
        prog->setPorcentaje(0);     //seteo porcentaje de leccion

        }
        else{
            prog->aumentarProgreso(estudiante);     //aumento progreso
        }
        float cantidadDeEjerciciosDelCurso = cur->cantidadDeEjercicios();
        prog->setPorcentajeCurso(1.0/cantidadDeEjerciciosDelCurso*100.0);      //seteo porcentaje de curso
        ejercicio=NULL;     //seteo ejercicio a NULL
        curso=NULL;     //seteo curso a NULL
        return true;        //retorno true
    }
    else{
        ejercicio=NULL;     //seteo ejercicio a NULL
        curso=NULL;         
        return false;
    } 
}
bool ControladorCurso::solucionCorrectaTraduccion(string solucion, string estudiante, int IdEjercicio) {
    Ejercicio* e = getEjercicioEnMemoria();
    Curso* cur = getCursoEnMemoria();                                               //obtengo curso
    int cantidadDeLecciones = cur->getLecciones().size();                           //obtengo cantidad de lecciones
    bool esCorrecta = e->esCorrectoTraduccion(solucion);                            //verifico si la solucion es correcta
    if(esCorrecta){                                                                 //si es correcta
        Leccion* lec = e->getLeccion();                                             //obtengo leccion
        int lecActual= lec->getNumero();                                            //obtengo numero de leccion
        Progreso* prog = lec->getProgresos().find(estudiante)->second;              //obtengo progreso
        int cant = lec->getCantidadDeEjercicios();                                  //obtengo cantidad de ejercicios
        prog->agregarEjercicioResuelto(e);                                //agrego ejercicio a ejercicios resueltos
        int ejResueltos = prog->getEjerciciosResueltos().size();                    //obtengo cantidad de ejercicios resueltos
        if(cant == ejResueltos){
            lec->eliminarProgreso(estudiante);      //elimino progreso
            Inscripcion* ins = prog->getInscripcion();      //obtengo inscripcion
            if(cantidadDeLecciones==lec->getNumero()){      //si es la ultima leccion
                prog->setLeccionActual(NULL);        //seteo leccion actual a NULL
                ins->setAprobado();             //seteo inscripcion a aprobado
            }       
            else{       
                Leccion* lecSig;        //obtengo leccion siguiente
                ins->setLeccionActual(lecActual+1);         //seteo leccion actual
                for(auto it = cur->getLecciones().begin(); it != cur->getLecciones().end(); ++it){      //recorro lecciones
                    if((*it)->getNumero() == ins->getLeccionActual()){      //si es la leccion siguiente
                        lecSig = (*it);     //guardo leccion siguiente
                    }
                }
                lecSig->agregarProgreso(prog);
                prog->limpiarEjerciciosResueltos();     //limpio ejercicios resueltos
                prog->setLeccionActual(lecSig);     //seteo leccion actual
            }    
        prog->setPorcentaje(0);     //seteo porcentaje de leccion
        }
        else{
            prog->aumentarProgreso(estudiante);     //aumento progreso
        }
        float cantidadDeEjerciciosDelCurso = cur->cantidadDeEjercicios();
        prog->setPorcentajeCurso(1.0/cantidadDeEjerciciosDelCurso*100.0);      //seteo porcentaje de curso
        ejercicio=NULL;     //seteo ejercicio a NULL
        curso=NULL;     //seteo curso a NULL
        return true;        //retorno true
    }
    else{
        ejercicio=NULL;     //seteo ejercicio a NULL
        curso=NULL;         
        return false;
    }
}
void ControladorCurso::seleccionarEjercicio(int idEjercicio) {
    Curso* c = getCursoEnMemoria();
    Ejercicio* ej = c->seleccionarEj(idEjercicio);
    setEjercicioEnMemoria(ej);
}
list<DTEjercicio> ControladorCurso::seleccionarEjerciciosDeCurso(string curso) {
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    Curso* c = getCurso(curso);
    setCursoEnMemoria(c);
    return cu.ejerciciosNoAprobados(curso);
}



//Operaciones de suscripciones

set<string> ControladorCurso::consultarSuscripciones(string nick) {
    set<string> idiomasNoSuscrito;
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    Usuario* user = cu.getUsuario(nick);
    for(auto it = idiomas.begin(); it != idiomas.end(); ++it){
        if(!it->second->estaSuscrito(user))
            idiomasNoSuscrito.insert(it->first);
    }
    return idiomasNoSuscrito;
}
void ControladorCurso::suscribirUsuario(set<string> idiomas,string nick) {
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    Usuario* user = cu.getUsuario(nick);
    for(auto it = idiomas.begin(); it != idiomas.end(); ++it){
        Idioma* idioma = this->idiomas.find(*it)->second;
        idioma->agregar(user);
    }
}
list<string> ControladorCurso::listarIdiomasSuscrito(string nick) {
    //ControladorUsuario& cu = ControladorUsuario::getInstancia();
    //Usuario* user = cu.getUsuario(nick);
    list<string> idiomasSuscrito;
    set<string> usuariosSuscritos;
    for (auto it = idiomas.begin(); it != idiomas.end(); it++){
        Idioma* idioma = it->second;
        usuariosSuscritos = idioma->suscripciones();
        if(usuariosSuscritos.find(nick) != usuariosSuscritos.end()){
            idiomasSuscrito.push_back(it->first);
        }
    }

    return idiomasSuscrito;
}
void ControladorCurso::eliminarSuscripciones(set<string> idi) {
    string nick = nickUsuario;
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    Usuario *user = cu.getUsuario(nick);
    for(auto it = idi.begin(); it != idi.end(); it++){
        Idioma *idiomaAEliminar = idiomas.find(*it)->second;
        idiomaAEliminar->eliminar(user);
    }
}

string ControladorCurso::getTipoEjercicio(int id) {
    auto it = ejercicios.find(id);
    if (it != ejercicios.end()) {
        Ejercicio* ejercicio = it->second;
        if (RellenarPalabras* rellenar = dynamic_cast<RellenarPalabras*>(ejercicio)) {
            return "completar";
        } else {
            return "traduccion";
        }
    }
    return "probar devuelta";
}

list<string> ControladorCurso::verCurso(string curso){
    list<string> datosCurso;
    string cursoBuscado = curso;
    auto it = cursos.find(cursoBuscado);
    Curso *cur = it->second;
    cur->conseguirInfoCurso(datosCurso); //Obtengo en la lista toda la info del curso
    return datosCurso;
}


//Otras operaciones
void ControladorCurso::limpiarDatos() {
    datoIdioma="";
    nickUsuario="";
    if(datoDeCurso != nullptr){
        delete datoDeCurso;
        datoDeCurso = NULL;
    }
    if(datoDeLeccion != nullptr){
        delete datoDeLeccion;
        datoDeLeccion = NULL;
    }
    if(datosRellenar != nullptr){
        delete datosRellenar;
        datosRellenar = NULL;
    }
    if(datosTraducir!= nullptr){
        delete datosTraducir;
        datosTraducir = NULL;
    }
    curso = NULL;
    profesor = NULL;
    ejercicio = NULL;
    //deletear 
    datosRellenarPalabras.clear();
    datosTraduccion.clear();
    datosLecciones.clear();
    datosPrevias.clear();

}

set<string> ControladorCurso::cursosInscriptoSinAprobar(string nick) {
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    return cu.cursosInscriptosSinAprobar(nick);
}


list<string> ControladorCurso:: listarNicks(){
    ControladorUsuario& cu = ControladorUsuario::getInstancia();
    return cu.listarUsuarios();
}