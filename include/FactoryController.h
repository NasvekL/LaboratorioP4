#ifndef FACTORYCONTROLLER
#define FACTORYCONTROLLER
#include "Utils.h"
#include "Interfaces/IControladorCurso.h"
#include "Interfaces/IControladorUsuario.h"
class factoryController{
    private:
        static factoryController instancia;
        factoryController();
    public:
        IControladorUsuario* getIControladorUsuario();
        IControladorCurso* getIControladorCurso();
        factoryController getFactoryInstance();
};





#endif
