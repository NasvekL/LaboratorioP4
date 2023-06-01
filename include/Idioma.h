#ifndef IDIOMA
#define IDIOMA
#include "Utils.h"
#include "Usuario.h"
#include "IObserver.h"
class Idioma{
    private:
        string nombreIdioma;
        void addIdioma(); //notificar observadores
        set<IObserver> observers;
    public:
       //setters
       void setNombreIdioma(string nombreIdioma);
       //getters
        string getNombreIdioma();
       //operaciones 
        string suscribir(string nick);
        void agregar(Usuario u); //agregar sucriptor
        void eliminar(Usuario u); //eliminar suscriptor
        set<string> suscripciones(string nick);
        //constructor y destructor
        ~Idioma();
        Idioma(string nombreIdioma);
        //falta set de suscriptores
        // falta set de profesores
        //falta set de cursos
};


#endif