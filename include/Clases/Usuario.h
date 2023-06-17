#ifndef USUARIO
#define USUARIO
#include "../Interfaces/IObserver.h"
#include "../Utils.h"
#include "../DTs/DTNotificacion.h"
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
        list<DTNotificacion> getNotificaciones();
        void eliminarNotificaciones();
        //observer
        void notificar(DTNotificacion noti);
        //NO ESTAMOS PONIENDO DESTRUCTOR EN VIRTUAL DE USUARIO, CAPAZ ESTA MAL
};



#endif