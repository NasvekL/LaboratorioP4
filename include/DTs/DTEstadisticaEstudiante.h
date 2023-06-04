#ifndef DTESTADISTICAESTUDIANTE
#define DTESTADISTICESTUDIANTE
#include "../Utils.h"

class DTEstadisticaEstudiante { 
    private:
        map<string,int> porcentajesCursos;
    public:
        map<string,int> getPorcentajesCursos();
        map<string, int> estadoEstudiante(); //curso clave y valor progreso
        ~DTEstadisticaEstudiante();
        DTEstadisticaEstudiante();
        DTEstadisticaEstudiante(string estudiante);
};
#endif;





