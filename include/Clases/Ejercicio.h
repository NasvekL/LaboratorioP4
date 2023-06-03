#ifndef EJERCICIO
#define EJERCICIO
#include "../Utils.h"
#include "Progreso.h"
class Leccion;

class Ejercicio{
    private:
        int idEjercicio;
        string descripcion;
        string letra;
        Leccion * leccion;
    public:
        //setters
        void setIdEjercicio(int idEjercicio);
        void setDescripcion(string descripcion);
        void setLetra(string letra);
        void setLeccion(Leccion lec);
        //getters
        int getIdEjercicio();
        string getDescripcion();
        string getLetra();
        Leccion getLeccion();
        //constructor y destructor
        ~Ejercicio();
        //operaciones
        virtual bool esCorrecto(string solucion)=0;
        void aumentarProgreso(string estudiante);
};


#endif