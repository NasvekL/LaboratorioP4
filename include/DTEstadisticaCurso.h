#ifndef DTESTADISTICACURSO
#define DTESTADISTICACURSO
#include "Utils.h"

class DTEstadisticaCurso { 
    private:
        ArrayList<String> CursosPropuestos; 
        ArrayList<Integer> promedioCurso;

    public:

        ArrayList<String> getCursosPropuestos();
        ArrayList<Integer> getpromedioCurso;
        
        DTCurso infoCurso();
        int gradoAvance();

        ~DTEstadisticaCurso();
        DTEstadisticaCurso(ArrayList<Integer> promedioCurso, ArrayList<String> CursosPropuestos);

};
#endif: