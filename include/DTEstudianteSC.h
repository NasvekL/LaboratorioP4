#include "Utils.h"

class DTEstudianteSC {
    private:
        string descripcion;
        string nickname;
        string nombre;
        string pais;
        Fecha nacimiento;
    public:
        string getDescripcion();
        string getNickname();
        string getNombre();
        string getPais();
        Fecha getNacimineto();

        ~DTEstudianteSC();
        DTEstudiante(string nickname, string nombre, string descripcion, string pais, Fecha nacimiento);

};



