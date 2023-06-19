#ifndef DTESTADISTICACURSO
#define DTESTADISTICACURSO
#include "../Utils.h"
#include "DTCurso.h"

class DTEstadisticaCurso { 
    private:
        string curso; 
        int promedioCurso;

    public:
        string getCurso();
        int getpromedioCurso();
        ~DTEstadisticaCurso();
        DTEstadisticaCurso(int promedioCurso, string curso);
        DTEstadisticaCurso();
};
#endif