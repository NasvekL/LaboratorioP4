#ifndef IDIOMA
#define IDIOMA
#include "../Utils.h"
#include "../Clases/Usuario.h"
#include "../Interfaces/IObserver.h"

class Usuario;
class Idioma{
    private:
        string nombreIdioma;
        void addIdioma(); //notificar observadores. por que la funcion que notifica a los observadores es privada y por que se llama addIdioma????
        set<IObserver*> observers;
    public:
       //setters
       void setNombreIdioma(string nombreIdioma);
       //getters
        string getNombreIdioma();
       //operaciones 
        string suscribir(string nick);
        bool estaSuscrito(Usuario* usuario);
        void agregar(Usuario* u); //agregar sucriptor
        void eliminar(Usuario* u); //eliminar suscriptor
        set<string> suscripciones(string nick);
        set<IObserver*> getObservers();
        //constructor y destructor
        Idioma(string nombreIdioma);
        ~Idioma();
        //falta set de suscriptores
        // falta set de profesores
        //falta set de cursos
};


#endif