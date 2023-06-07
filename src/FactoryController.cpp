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
ControladorUsuario c = ControladorUsuario::getInstancia();
return c;
}

// Obtener el controlador de curso
IControladorCurso& factoryController::getIControladorCurso(){
ControladorCurso c = ControladorCurso::getInstancia();
return c;
}
