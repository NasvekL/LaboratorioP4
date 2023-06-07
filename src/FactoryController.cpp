#include "../include/FactoryController.h"

// Inicialización de la instancia estática
factoryController* factoryController::instancia = NULL;

// Constructor privado
factoryController::factoryController() {}

// Obtener la instancia de la fábrica
factoryController* factoryController::getFactoryInstance() {
    if(instancia == NULL){
        instancia = new factoryController();
    }
    return instancia;
}

// Obtener el controlador de usuario
IControladorUsuario* factoryController::getIControladorUsuario() {

}

// Obtener el controlador de curso
IControladorCurso* factoryController::getIControladorCurso() {
}