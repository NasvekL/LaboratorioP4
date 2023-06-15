#ifndef INSCRIPCION
#define INSCRIPCION
#include "../Utils.h"
#include "Curso.h"
#include "Progreso.h"
#include "Estudiante.h"
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
        Estudiante* estudiante;

    public:
        //Getters
        DTFecha getFecha();
        bool getAprobado();
        int getLeccionActual();
        //Create y destroy
        Inscripcion(DTFecha fecha,bool aprobado,int leccionActual,Progreso* prog);
        ~Inscripcion();
    
};


#endif