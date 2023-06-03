#ifndef DTESTADISTICAESTUDIANTE
#define DTESTADISTICESTUDIANTE
#include "../Utils.h"

class DTEstadisticasEstudiante { 
    private:
        ArrayList<Integer> porcetajesCursos;
        ArrayList<String> cursos;
    public:
        ArrayList<Integer> getPorcentajes();
        ArrayList<String> getCursos();

        map<string, int> estadoEstudiante(); //curso clave y valor progreso

        ~DTEstadisticaEstudiante();
        DTEstadisticasEstudiante(ArrayList<Integer> porcetajesCursos, ArrayList<String> cursos);




};
#endif;





