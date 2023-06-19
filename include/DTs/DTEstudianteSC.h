#ifndef DTESTUDIANTESC
#define DTESTUDIANTESC
#include "../Utils.h"

class DTEstudianteSC {
    private:
        string descripcion;
        string nickname;
        string nombre;
        string pais;
        DTFecha nacimiento;
    public:
        string getNickname();
        ~DTEstudianteSC();
        DTEstudianteSC(string nickname, string nombre, string descripcion, string pais, DTFecha nacimiento);

};
#endif


