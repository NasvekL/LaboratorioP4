#include "../include/FactoryController.h"

// Inicialización de la instancia estática
factoryController factoryController::instancia;

// Constructor privado
factoryController::factoryController() {}

// Obtener la instancia de la fábrica
factoryController factoryController::getFactoryInstance() {
    return instancia;
}

// Obtener el controlador de usuario
IControladorUsuario* factoryController::getIControladorUsuario() {
    // Implementación de la función
    // Puedes retornar un puntero a una instancia del controlador de usuario
    return ControladorUsuario::getInstance();
}

// Obtener el controlador de curso
IControladorCurso* factoryController::getIControladorCurso() {
    // Implementación de la función
    // Puedes retornar un puntero a una instancia del controlador de curso
    return ControladorCurso::getInstance();
}