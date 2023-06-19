#include "../../include/DTs/DTEstadisticaCurso.h"


// Constructor
DTEstadisticaCurso::DTEstadisticaCurso(int promedioCurso, string curso) {
    this->curso=curso;
    this->promedioCurso=promedioCurso;
    // Implementación del constructor
    // Puedes asignar los valores de los parámetros a los atributos correspondientes
    // Aquí solo se muestra cómo iterar sobre las listas proporcionadas
    //for (auto it = promedioCurso.begin(); it != promedioCurso.end(); ++it) {
        // Hacer algo con cada valor en la lista promedioCurso
    //}

   // for (auto it = cursosPropuestos.begin(); it != cursosPropuestos.end(); ++it) {
        // Hacer algo con cada valor en la lista cursosPropuestos
   // }
}

// Destructor
DTEstadisticaCurso::~DTEstadisticaCurso() {
    // Implementación del destructor
    // Puedes realizar cualquier limpieza necesaria
}
DTEstadisticaCurso::DTEstadisticaCurso() {
    // Implementación del constructor
    // Puedes inicializar el objeto según tus necesidades
}
// Getter de curso
string DTEstadisticaCurso::getCurso() {
    // Implementación del getter
    // Puedes devolver el nombre del curso, por ejemplo
    return curso;
}

// Getter de promedioCurso
int DTEstadisticaCurso::getpromedioCurso() {
    // Implementación del getter
    // Puedes devolver el valor del atributo promedioCurso
    return promedioCurso;
}

