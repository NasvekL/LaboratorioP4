#include "../include/FactoryController.h"

// Inicialización de la instancia estática
factoryController* factoryController::instancia = NULL;



// Obtener la instancia de la fábrica
factoryController& factoryController::getInstancia(){
    if (instancia == nullptr) {
        instancia = new factoryController(); // Crear una nueva instancia solo si no existe una
    }
    return *instancia;
}

// Obtener el controlador de usuario
IControladorUsuario& factoryController::getIControladorUsuario() {
return ControladorUsuario::getInstancia();

}

// Obtener el controlador de curso
IControladorCurso& factoryController::getIControladorCurso(){
return ControladorCurso::getInstancia();
}
