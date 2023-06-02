#include "../include/IControladorCurso.h"

// Inicialización de la instancia única del controlador
IControladorCurso* IControladorCurso::instancia = nullptr;

// Constructor
IControladorCurso::IControladorCurso() {
    // Implementación del constructor
}

// Método estático para obtener la instancia única del controlador
IControladorCurso* IControladorCurso::getInstancia() {
    if (instancia == nullptr) {
        instancia = new IControladorCurso();
    }
    return instancia;
}
