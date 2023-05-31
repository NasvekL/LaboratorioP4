using namespace std;
#include<string>
class usuario:public observer{
    private:
        string Nickname;
        string Contrasenia;
        string Nombre;
        string Descripcion;
        set(DTNotificacion) notificaciones;
    public:
        string getContrasenia();
        string getDescripcion();
        string getNick();
        string getNombre();
        virtual void verNotificaciones()set(DTNotificacion);
        virtual ~usuario(); //destructor
        void notificar();
};
