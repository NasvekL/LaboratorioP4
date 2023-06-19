#ifndef IDIOMA
#define IDIOMA
#include "../Utils.h"
#include "../Interfaces/IObserver.h"
#include "../Clases/Usuario.h"
#include "../DTs/DTNotificacion.h"
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
        bool estaSuscrito(Usuario* usuario);
        void agregar(Usuario* u); //agregar sucriptor
        void eliminar(Usuario* u); //eliminar suscriptor
        set<string> suscripciones();
        set<IObserver*> getObservers();
        //constructor y destructor
        Idioma(string nombreIdioma);
        ~Idioma();
};


#endif