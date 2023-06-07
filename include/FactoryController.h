#ifndef FACTORYCONTROLLER
#define FACTORYCONTROLLER
#include "Utils.h"
#include "Interfaces/IControladorCurso.h"
#include "Interfaces/IControladorUsuario.h"
class factoryController{
    private:
        factoryController() = default;
        static factoryController* instancia;
    public:
        IControladorUsuario* getIControladorUsuario();
        IControladorCurso* getIControladorCurso();
        static factoryController* getFactoryInstance();
};





#endif
