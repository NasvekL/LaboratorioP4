#ifndef DTESTADISTICAESTUDIANTE
#define DTESTADISTICAESTUDIANTE
#include "../Utils.h"

class DTEstadisticaEstudiante { 
    private:
        map<string,int> porcentajesCursos;
    public:
        map<string,int> getPorcentajesCursos();
        map<string, int> estadoEstudiante(); //curso clave y valor progreso
        ~DTEstadisticaEstudiante();
        DTEstadisticaEstudiante();
        DTEstadisticaEstudiante(map<string, int> porcentajesCursos);
};
#endif




