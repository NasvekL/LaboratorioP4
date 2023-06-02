#ifndef FACTORYCONTROLLER
#define FACTORYCONTROLLER
#include "Utils.h"
#include "IControladorCurso.h"
#include "IControladorUsuario.h"

factoryController{
    private:
        factoryController instancia;
        factoryController();
    public:
        IControladorUsuario getIControladorUsuario();
        IControladorCurso getIControladorCurso();
        factoryController getFactoryInstance();
};

