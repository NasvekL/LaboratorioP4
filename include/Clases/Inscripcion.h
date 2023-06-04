#ifndef INSCRIPCION
#define INSCRIPCION
#include "../Utils.h"
#include "Curso.h"
    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS

class Progreso;

class Inscripcion{
    private:
        DTFecha fecha;
        bool aprobado;
        int leccionActual;
        //Pseudoatributos
        Progreso* prog;
        Curso* inscriptoA;
    public:
        //Getters
        DTFecha getFecha();
        bool getAprobado();
        int getLeccionActual();
        //Create y destroy
        Inscripcion(Fecha fecha,bool aprobado,int leccionActual,Progreso* prog);
        ~Inscripcion();
    
};


#endif