#include "../../include/DTs/DTEstadisticaEstudiante.h"

// Constructor
DTEstadisticaEstudiante::DTEstadisticaEstudiante(map<string, int> porcentajesCursos) {
    // Implementación del constructor
    this->porcentajesCursos = porcentajesCursos;
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
