#ifndef DTESTADISTICACURSO
#define DTESTADISTICACURSO
#include "../Utils.h"
#include "DTCurso.h"

class DTEstadisticaCurso { 
    private:
        DTCurso curso; 
        int promedioCurso;

    public:

        string getCurso();
        int getpromedioCurso();
        
        DTCurso infoCurso();
        int gradoAvance();

        ~DTEstadisticaCurso();
        DTEstadisticaCurso();
        DTEstadisticaCurso(list<int> promedioCurso, list<string> cursosPropuestos);

};
#endif: