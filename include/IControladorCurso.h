#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO
#include "Utils.h"




class IControladorCurso{
    public:
        virtual ControladorCurso * getInstance() = 0;
        //agragar operaciones del controlador
};
