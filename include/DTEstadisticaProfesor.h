#ifndef DTESTADISTICAPROFESOR
#define DTESTADISTICAPROFESOR
#include "Utils.h"

class DTCurso;

class DTEstadisticasProfesor { 
    private:
    
        DTCurso Curso;
        int PromedioCurso; 

    public:

        DTCurso getCurso();
        int getPromedioCurso; //Este es un atributo calculado

        Dictionary(cursoClave: String,valorProgresoPromedio: int)

        ~DTEstadisticaProfesor();
        DTEstadisticaProfesor(DTCurso Curso, int PromedioCurso);

};

#endif;