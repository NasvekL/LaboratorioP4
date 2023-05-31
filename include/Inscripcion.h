#ifndef INSCRIPCION
#define INSCRIPCION
#include "Utils.h"
#include "Curso.h"
    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS

class Inscripcion{
    private:
        Fecha fecha;
        bool aprobado;
        int leccionActual;
        //Pseudoatributos
        Progreso* prog;
        Curso* inscriptoA;
    public:
        //Getters
        Fecha getFecha();
        bool getAprobado();
        int getLeccionActual();
        //Create y destroy
        ~Inscripcion();
    
};


#endif