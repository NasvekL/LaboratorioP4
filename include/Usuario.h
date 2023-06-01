#ifndef USUARIO
#define USUARIO
#include "Utils.h"
#include "IObserver.h"

class Usuario:public IObserver{
    private:
        string nickname;
        string contrasenia;
        string nombre;
        string descripcion;
        set<DTNotificacion> notificaciones;
    public:
        //getters
        string getContrasenia();
        string getDescripcion();
        string getNick();
        string getNombre();
        virtual set<DTNotificacion> verNotificaciones();
        virtual ~Usuario(); //destructor
        void notificar();
};



#endif