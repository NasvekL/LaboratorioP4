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
        string getDescripcion();
        string getNickname();
        string getNombre();
        string getPais();
        DTFecha getNacimineto();

        ~DTEstudianteSC();
        DTEstudianteSC(string nickname, string nombre, string descripcion, string pais, DTFecha nacimiento);

};
#endif;


