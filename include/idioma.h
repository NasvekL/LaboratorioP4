using namespace std;
#include<string>
#include "usuario.h"
class idioma{
    private:
        string nombreIdioma;
        void addIdioma(); //notificar observadores
    public:
        string suscribir(nick string);
        void agregar(usuario u); //agregar sucriptor
        void eliminar(usuario u); //eliminar suscriptor
        set(string) suscripciones(nick:String);
        idioma(string nombreIdioma);
        //falta set de suscriptores
        // falta set de profesores
        //falta set de cursos
};