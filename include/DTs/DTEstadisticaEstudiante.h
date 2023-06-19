#ifndef DTESTADISTICAESTUDIANTE
#define DTESTADISTICAESTUDIANTE
#include "../Utils.h"

class DTEstadisticaEstudiante { 
    private:
        map<string,int> porcentajesCursos;
    public:
        map<string,int> getPorcentajesCursos();
        ~DTEstadisticaEstudiante();
        DTEstadisticaEstudiante(map<string, int> porcentajesCursos);
};
#endif




