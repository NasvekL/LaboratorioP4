#ifndef DTESTADISTICACURSO
#define DTESTADISTICACURSO
#include "../Utils.h"
class DTCurso;

class DTEstadisticaCurso { 
    private:
        DTCurso curso; 
        int promedioCurso;

    public:

        string getCurso();
        int getpromedioCurso;
        
        DTCurso infoCurso();
        int gradoAvance();

        ~DTEstadisticaCurso();
        DTEstadisticaCurso(ArrayList<int> promedioCurso, ArrayList<string> CursosPropuestos);

};
#endif: