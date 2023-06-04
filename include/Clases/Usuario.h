#ifndef USUARIO
#define USUARIO
#include "../Utils.h"
#include "../IObserver.h"

class Usuario:public IObserver{
    private:
        string nickname;
        string contrasenia;
        string nombre;
        string descripcion;
        list<DTNotificacion> notificaciones;
    public:
        //setters
        void setNick(string nick);
        void setNombre(string nombre);
        void setContrasenia(string contra);
        void setDescripcion(string descripcion);
        virtual list<DTNotificacion> verNotificaciones();
        //getters
        string getContrasenia();
        string getDescripcion();
        string getNick();
        string getNombre();
        //destrucotor
        virtual ~Usuario();
        //observer
        void notificar();
};



#endif