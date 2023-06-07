#include "../../include/Clases/Profesor.h"


// Implementación de los métodos de la clase Profesor

string Profesor::getInstituto() {
    return instituto;
}

Profesor::~Profesor() {
}

Profesor::Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, list<Curso*> cursos, list<Idioma*> idiomas){
    setNick(nickname);
    setNombre(nombre);
    setContrasenia(contrasenia);
    setDescripcion(descripcion);
    this->instituto = instituto;
    this->idiomas = idiomas;
    this->cursos = nullptr;
}

list<DTNotificacion> Profesor::verNotificaciones() {
    // Implementar la lógica para obtener las notificaciones del profesor
    // ...
}

DTProfesor Profesor::getDTProfesor() {
    // Implementar la lógica para obtener un objeto DTProfesor con los datos del profesor
    // ...
}

list<DTCurso> Profesor::obtenerDTCurso() {
    // Implementar la lógica para obtener los objetos DTCurso asociados al profesor
    // ...
}

int Profesor::obtenerPromedio() {
    // Implementar la lógica para calcular el promedio del profesor
    // ...
}

list<Idioma*> Profesor::Idiomas() {
    return idiomas;
}

list<Curso*> Profesor::Cursos() {
    return cursos;
}

// Implementar los métodos adicionales y las operaciones para agregar idiomas y cursos
// según tus necesidades