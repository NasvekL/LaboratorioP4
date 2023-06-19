#include "../../include/Clases/Curso.h"

// CONSTRUCTOR Y DESTRUCTOR
Curso::~Curso() {
    profesorQueLoDicta->eliminarCurso(this);
    for (auto iter=lecciones.begin(); iter!=lecciones.end(); iter++){
        Leccion* lec = *iter;
        delete lec;
    }
    lecciones.clear();
    for(auto it = inscripciones.begin(); it!=inscripciones.end(); it++){
        Inscripcion* ins = *it;
        Estudiante* est = ins->getEstudiante();
        est->eliminarInscripcion(ins);
        delete ins;
    }
    aprobados.clear();
    inscripciones.clear();
    previas.clear();
}
Curso::Curso() {
    // Implementación del constructor vacio
}
//Hay que hacer un constructor para los casos en los que hay lecciones y otro para los que no?
Curso::Curso(string nombre, string descripcion, nivelDeDificultad nivel, map<string,Curso*> previas, Idioma* idioma, Profesor* profesorQueLoDicta,list<DTRellenarPalabras> datosRellenarP,list<DTTraduccion> datosTraduccion,list<DTLeccion>lecciones): previas(){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->nivelDeDif = nivel;
    this->idiomaDelCurso = idioma;
    this->profesorQueLoDicta = profesorQueLoDicta;
    this->habilitado = false;
    for(auto iter=previas.begin(); iter!=previas.end(); iter++){
        Curso* cur = iter->second;
        this->previas.push_back(cur);
    }
    for(auto iter = lecciones.begin(); iter!=lecciones.end(); iter++){
        DTLeccion dtl = *iter;
        Leccion* lec = new Leccion(dtl.getTema(),dtl.getObjetivoAprendizaje(),dtl.getCantidadDeEjercicios(),dtl.getNumero(),datosRellenarP,datosTraduccion);
        this->lecciones.push_back(lec);
    }
}

// GETTERS
string Curso::getNombreCurso() const{
    return nombre;
}

string Curso::getDescripcion() {
    return descripcion;
}

nivelDeDificultad Curso::getNivelDeDificultad() {
    return nivelDeDif;
}

list<Curso*> Curso::getPrevias() {
    return previas;
}

bool Curso::getHabilitado() {
    return habilitado;
}

// SETTERS
void Curso::setHabilitado(bool habilitado) {
    this->habilitado = habilitado;
}
// GETTERS DE PSEUDOATRIBUTOS
Idioma* Curso::getIdiomaDelCurso() {
    return idiomaDelCurso;
}

Profesor* Curso::getProfesorQueLoDicta() {
    return profesorQueLoDicta;
}

list<Leccion*>& Curso::getLecciones() {
    return lecciones;
}
list<Inscripcion*> Curso::getInscripciones() {
    return inscripciones;
}

// SETTERS DE PSEUDOATRIBUTOS
void Curso::setIdiomaDelCurso(Idioma* i) {
    idiomaDelCurso = i;
}

void Curso::setProfesorQueLoDicta(Profesor* p) {
    profesorQueLoDicta = p;
}

void Curso::setLecciones(list<Leccion*> lecciones) {
    this->lecciones = lecciones;
}
void Curso::agregarInscripcion(Inscripcion* insc){
    inscripciones.push_back(insc);
}
void Curso::eliminarPrevia(Curso* previa){
    for(auto it = previas.begin(); it!=previas.end(); it++){
        if((*it) == previa){
            previas.erase(it);
            break;
        }
    }
}

// OPERACIONES
Ejercicio* Curso :: seleccionarEj(int id){
    Ejercicio* ejer = NULL;
    for(auto it = lecciones.begin(); it!=lecciones.end(); it++){
        ejer = (*it)->seleccionarEj(id);
        if (ejer!=NULL)
        break;
    }
    return ejer;
    }

void Curso :: agregarPrevia(Curso* previa){
    previas.push_back(previa);
}

list<DTEjercicio> Curso::buscarEjNoAprobados(string nick, int lecActual){
    if(lecciones.size() > 0){
        for(auto it = lecciones.begin(); it!=lecciones.end(); it++){
            if((*it)->getNumero() == lecActual){
                return (*it)->ejerciciosNoAprobados(nick);
            }
        }
    }
    list<DTEjercicio> vacia;
    return vacia;
}

void Curso::agregarLeccion(Leccion* lec){
    lecciones.push_back(lec);
}

//Contar
int Curso::cantidadDeLecciones(){
    return lecciones.size();
}
int Curso::cantidadDeEjercicios(){
    int cant = 0;
    for(auto iter = lecciones.begin(); iter!=lecciones.end(); iter++){
        Leccion* lec = *iter;
        cant += lec->getCantidadDeEjercicios();
    }
    return cant;
}

void Curso::conseguirInfoCurso(list<string> &infoCur){
    
    
    string hab;
    if (habilitado){
        hab = "Habilitado";
    } else {
        hab = "No habilitado";
    }
    string dificultad;
    if(nivelDeDif==1)
        dificultad = "Principiante";
    else if(nivelDeDif==2)
        dificultad = "Medio";
    else
        dificultad = "Avanzado";
    string datosCurso = "Nombre del curso: " + nombre + "\n" + "Descripcion del curso: " + descripcion + "\n" + "Nivel de dificultad: " + dificultad + "\n" + "Idioma del curso: " + idiomaDelCurso->getNombreIdioma() + "\n" + "Profesor que lo dicta: " + profesorQueLoDicta->getNombre() + "\n" + hab + "\n" + "\n"; 
    infoCur.push_back(datosCurso);      //Tengo toda la info del curso en el primer lugar de la lista
    
    

    if (lecciones.size()!=0){  //Si tiene lecciones
        int a = 1;
        for (auto it = lecciones.begin(); it != lecciones.end(); it++){
            string aux = "Leccion" + to_string(a) + ":" + "\n";
            infoCur.push_back(aux);
            (*it)->conseguirInfoLeccion(infoCur);
            a++;
        }
    }

    if(inscripciones.size()!=0){     //Si tiene inscripciones
        infoCur.push_back("Estudiantes Inscriptos: \n");      
        for (auto iterador = inscripciones.begin(); iterador != inscripciones.end(); iterador++){
            (*iterador)->conseguirInfoInscripcion(infoCur);
        }
    }
}