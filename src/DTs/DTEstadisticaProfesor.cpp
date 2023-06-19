#include "../../include/DTs/DTEstadisticaProfesor.h"
#include "../../include/DTs/DTCurso.h" // Asegúrate de incluir el archivo de encabezado correspondiente

// Constructor
DTEstadisticaProfesor::DTEstadisticaProfesor(map<string, int> promPorcenCur) {
    this->promPorcetajesCursos =promPorcenCur;
    // Implementación del constructor
    // Puedes inicializar el objeto según tus necesidades
}
DTEstadisticaProfesor::DTEstadisticaProfesor() {
    // Implementación del constructor
    // Puedes inicializar el objeto según tus necesidades
}

// Destructor
DTEstadisticaProfesor::~DTEstadisticaProfesor() {
    // Implementación del destructor
    // Puedes liberar recursos si es necesario
}


// Getter para obtener el promedio de porcentajes de cursos
map<string,int> DTEstadisticaProfesor::getPromPorcetajesCursos() {
return promPorcetajesCursos;
}
