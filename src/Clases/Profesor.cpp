#include "../../include/Clases/Profesor.h"


// Implementación de los métodos de la clase Profesor

string Profesor::getInstituto() {
    return instituto;
}

Profesor::~Profesor() {
}

Profesor::Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto,set<Idioma*> idiomas){
    setNick(nickname);
    setNombre(nombre);
    setContrasenia(contrasenia);
    setDescripcion(descripcion);
    this->instituto = instituto;
    this->idiomas = idiomas;
}


DTProfesor Profesor::getDTProfesor() {
    set<string> setIdi;
    for (auto it = idiomas.begin(); it != idiomas.end(); ++it) {
        setIdi.insert((*it)->getNombreIdioma());
    }
    DTProfesor dt = DTProfesor(this->getNick(), this->getContrasenia(), this->getNombre(), this->getDescripcion(), this->getInstituto(),setIdi);
    return dt;
    // Implementar la lógica para obtener un objeto DTProfesor con los datos del profesor
    // ...
}
set<Idioma*> Profesor::getIdiomas() {
    return idiomas;
}

list<Curso*> Profesor::getCursos() {
    return this->cursos;
}
void Profesor::agregarCurso(Curso* curso) {
    this->cursos.push_back(curso);
}
void Profesor::eliminarCurso(Curso* curso) {
    this->cursos.remove(curso);
}
// Implementar los métodos adicionales y las operaciones para agregar idiomas y cursos
// según tus necesidades