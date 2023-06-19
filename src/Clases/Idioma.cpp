#include "../../include/Clases/Idioma.h"

void Idioma::addIdioma() {
    // Implementación de addIdioma
    // Notificar a los observadores
}

void Idioma::setNombreIdioma(string nombreIdioma) {
    this->nombreIdioma = nombreIdioma;
}

string Idioma::getNombreIdioma() {
    return nombreIdioma;
}
set<IObserver*> Idioma::getObservers(){
    return observers;
}

void Idioma::agregar(Usuario* u) {
IObserver* obs = dynamic_cast<IObserver*>(u);
observers.insert(obs);
    // Agregar un suscriptor a la lista de observers 
}

void Idioma::eliminar(Usuario* u) {
    IObserver* obs = dynamic_cast<IObserver*>(u);
    observers.erase(obs);
}
bool Idioma::estaSuscrito(Usuario* usuario) {
    if(observers.size() == 0){
        return false;
    }
    else{
        auto it = std::find(observers.begin(), observers.end(), usuario);
        if (it!=observers.end())
            return true;
        else{
            return false;
        }
    }
    // Implementación de estaSuscrito
    // Retorna true si el usuario está suscrito al idioma
}
set<string> Idioma::suscripciones() {
    set<string> usuariosSuscritos;
    for(auto it = observers.begin(); it != observers.end(); it++){
        Usuario* obs = dynamic_cast<Usuario*>(*it);
        usuariosSuscritos.insert(obs->getNick());
    }
    return usuariosSuscritos;
}

Idioma::~Idioma() {
}

Idioma::Idioma(string nombreIdioma) {
    this->nombreIdioma = nombreIdioma;
}
