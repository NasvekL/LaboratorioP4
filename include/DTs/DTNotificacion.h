#ifndef NOTIFICACION
#define NOTIFICACION
#include "../Utils.h"
#include "DTCurso.h"
#include "../Clases/Idioma.h"

class Idioma;
class DTNotificacion{
    private:
        DTCurso cursoCreado;
        Idioma* idiomaDelCurso;
    public:
        //getters
        DTCurso getCurso();
        Idioma* getIdioma();
        //constructor destructor
        ~DTNotificacion();
        DTNotificacion(DTCurso cursoCreado,Idioma* idiomaDelCurso);
};
#endif