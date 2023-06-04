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

}

// Obtener el controlador de curso
IControladorCurso* factoryController::getIControladorCurso() {
}