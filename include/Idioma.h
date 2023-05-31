#ifndef IDIOMA
#define IDIOMA
#include "Utils.h"
#include "Usuario.h"

class Idioma{
    private:
        string nombreIdioma;
        void addIdioma(); //notificar observadores
    public:
        string suscribir(nick string);
        void agregar(Usuario u); //agregar sucriptor
        void eliminar(Usuario u); //eliminar suscriptor
        set(string) suscripciones(nick string);
        idioma(string nombreIdioma);
        //falta set de suscriptores
        // falta set de profesores
        //falta set de cursos
};


#endif