#ifndef DTPROFESOR
#define DTPROFESOR
#include "../Utils.h"
#include "../Clases/Usuario.h"
class DTProfesor{
    private:
        string instituto;
        string descripcion;
        string nombre;
        string contrasenia;
        string nickname;
    public:
        //Getters
        string getInstituto();
        string getDescripcion();
        string getNombre();
        string getContrasenia();
        string getNickname();
        //Create y destroy
        ~DTProfesor();
        DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);

};
#endif;