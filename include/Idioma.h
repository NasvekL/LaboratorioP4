#ifndef IDIOMA
#define IDIOMA
#include "Utils.h"
#include "Usuario.h"

class Idioma{
    private:
        string nombreIdioma;
        void addIdioma(); //notificar observadores
    public:
        string suscribir(string nick);
        void agregar(Usuario u); //agregar sucriptor
        void eliminar(Usuario u); //eliminar suscriptor
        set<string> suscripciones(string nick);
        idioma(string nombreIdioma); ///  <<<<<---------------- ta mal
        //falta set de suscriptores
        // falta set de profesores
        //falta set de cursos
};


#endif