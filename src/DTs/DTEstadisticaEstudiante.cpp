#include "../../include/DTs/DTEstadisticaEstudiante.h"

// Constructor
DTEstadisticaEstudiante::DTEstadisticaEstudiante(map<string, int> porcentajesCursos) {
    // Implementación del constructor
    this->porcentajesCursos = porcentajesCursos;
    // Puedes inicializar el objeto según tus necesidades
}
DTEstadisticaEstudiante::DTEstadisticaEstudiante() {
    // Implementación del constructor
    // Puedes inicializar el objeto según tus necesidades
}

// Destructor
DTEstadisticaEstudiante::~DTEstadisticaEstudiante() {
    // Implementación del destructor
    // Puedes liberar recursos si es necesario
}

// Getter para porcentajesCursos
map<string, int> DTEstadisticaEstudiante::getPorcentajesCursos() {
    return porcentajesCursos;
}

// Función para obtener el estado del estudiante en cada curso
map<string, int> DTEstadisticaEstudiante::estadoEstudiante() {
    // Implementación de la función
    // Puedes calcular y devolver el estado del estudiante en cada curso
}