#ifndef NOTIFICACION
#define NOTIFICACION
#include "../Utils.h"
#include "DTCurso.h"
#include "../Clases/Idioma.h"
class DTNotificacion{
    public:
        DTCurso cursoCreado;
        Idioma idiomaDelCurso;
    private:
        //getters
        DTCurso getCurso();
        Idioma getIdioma();
        //constructor destructor
        ~DTNotificacion();
        DTNotificacion(DTCurso cursoCreado,Idioma idiomaDelCurso);
};
#endif;