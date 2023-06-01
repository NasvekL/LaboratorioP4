#ifndef DTESTADISTICAPROFESOR
#define DTESTADISTICAPROFESOR
#include "Utils.h"

class DTEstadisticasEstudiante { 
    private:
        ArrayList<Integer> porcetajesCursos;
        ArrayList<String> Cursos;
    public:
        ArrayList<Integer> getPorcentajes();
        ArrayList<String> getCursos;

        //Dictionary(cursoClave: String,valorProgreso: int);

        ~DTEstadisticaEstudiante();
        DTEstadisticasEstudiante(ArrayList<Integer> porcetajesCursos, ArrayList<String> Cursos);




};
#endif;





