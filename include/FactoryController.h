#ifndef FACTORYCONTROLLER
#define FACTORYCONTROLLER
#include "Utils.h"
#include "../Interfaces/IControladorCurso.h"
#include "Interfaces/IControladorUsuario.h"

factoryController{
    private:
        factoryController instancia;
        factoryController();
    public:
        IControladorUsuario getIControladorUsuario();
        IControladorCurso getIControladorCurso();
        factoryController getFactoryInstance();
};





#endif
