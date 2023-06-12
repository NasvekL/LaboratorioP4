#ifndef FACTORYCONTROLLER
#define FACTORYCONTROLLER
#include "Utils.h"
#include "Interfaces/IControladorCurso.h"
#include "Interfaces/IControladorUsuario.h"
#include "Controladores/ControladorUsuario.h"
#include "Controladores/ControladorCurso.h"
class factoryController{
    private:
        factoryController(){};
        static factoryController* instancia;
    public:
        static factoryController& getInstancia();
        IControladorUsuario& getIControladorUsuario();
        IControladorCurso& getIControladorCurso();
        static factoryController* getFactoryInstance();
};





#endif
    