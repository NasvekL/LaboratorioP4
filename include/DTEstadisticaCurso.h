#ifndef DTESTADISTICACURSO
#define DTESTADISTICACURSO
#include "Utils.h"

class DTEstadisticaCurso { 
    private:
        ArrayList<String> CursosPropuestos; 
        ArrayList<int> promedioCurso;

    public:

        ArrayList<String> getCursosPropuestos();
        ArrayList<int> getpromedioCurso;
        
        DTCurso infoCurso();
        int gradoAvance();

        ~DTEstadisticaCurso();
        DTEstadisticaCurso(ArrayList<Integer> promedioCurso, ArrayList<String> CursosPropuestos);

};
#endif: