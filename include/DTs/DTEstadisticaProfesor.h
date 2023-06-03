#ifndef DTESTADISTICAPROFESOR
#define DTESTADISTICAPROFESOR
#include "../Utils.h"

class DTCurso;

class DTEstadisticasProfesor { 
    private:
        ArrayList<Integer> promPorcetajesCursos;
        ArrayList<String> cursos;
    public:

        DTCurso getCurso();
        int getPromPorcetajesCursos(); //Este es un atributo calculado

        map<string, int> estadoCurso(); //CursoClave y valor progreso promedio

        ~DTEstadisticaProfesor();
        DTEstadisticaProfesor(DTCurso Curso, int promPorcetajesCursos);

};

#endif;