#ifndef DTESTADISTICACURSO
#define DTESTADISTICACURSO
#include "../Utils.h"
class DTCurso;

class DTEstadisticaCurso { 
    private:
        DTCurso curso; 
        int promedioCurso;

    public:

        String getCurso();
        int getpromedioCurso;
        
        DTCurso infoCurso();
        int gradoAvance();

        ~DTEstadisticaCurso();
        DTEstadisticaCurso(ArrayList<Integer> promedioCurso, ArrayList<String> CursosPropuestos);

};
#endif: