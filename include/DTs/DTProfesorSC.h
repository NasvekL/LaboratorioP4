#ifndef DTPROFESORSC
#define DTPROFESORSC
#include "../Utils.h"

class DTProfesorSC {
    private:
        string instituto;
        string descripcion;
        string nickname;
        string nombre;
    public:
        string getInstituto();
        string getDescripcion();
        string getNickname();
        string getNombre();

        ~DTProfesorSC();
        DTProfesorSC(string nickname, string nombre, string descripcion, string instituto);

};
#endif






















