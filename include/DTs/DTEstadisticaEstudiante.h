#ifndef DTESTADISTICAESTUDIANTE
#define DTESTADISTICAESTUDIANTE
#include "../Utils.h"

class DTEstadisticaEstudiante { 
    private:
        map<string,float> porcentajesCursos;
    public:
        map<string,float> getPorcentajesCursos();
        map<string, float> estadoEstudiante(); //curso clave y valor progreso
        ~DTEstadisticaEstudiante();
        DTEstadisticaEstudiante(map<string, float> porcentajesCursos);
};
#endif




