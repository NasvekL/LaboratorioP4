#ifndef NOTIFICACION
#define NOTIFICACION
#include "../Utils.h"
#include "DTCurso.h"
class Idioma;
class DTNotificacion{
    private:
        string cursoCreado;
        Idioma* idiomaDelCurso;
    public:
        //getters
        string getCurso();
        Idioma* getIdioma();
        //constructor destructor
        ~DTNotificacion();
        DTNotificacion(string cursoCreado,Idioma* idiomaDelCurso);
};
#endif