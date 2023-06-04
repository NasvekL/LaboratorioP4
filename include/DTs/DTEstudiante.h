#ifndef DTESTUDIANTE
#define DTESTUDIANTE
#include "../Utils.h"
#include "../Clases/Usuario.h"
class DTEstudiante{
    private:
        string nickname;
        string contrasenia;
        string descripcion;
        string nombre;
        string pais;
        DTFecha nacimiento;
        
    public:
        //Getters
        string getPais();
        DTFecha getNacimineto();
        string getNickname();
        string getContrasenia();
        string getDescripcion();
        string getNombre();
        //Create destroy
        ~DTEstudiante();
        DTEstudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha nacimiento);
};
#endif