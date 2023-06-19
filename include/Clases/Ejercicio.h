#ifndef EJERCICIO
#define EJERCICIO
#include "../Utils.h"
#include "Progreso.h"
#include "Leccion.h"
#include "../DTs/DTEjercicio.h"

class Ejercicio{
    private:
        int idEjercicio;
        string descripcion;
        string letra;
        Leccion* leccion;
    public:
        //setters
        void setIdEjercicio(int idEjercicio);
        void setDescripcion(string descripcion);
        void setLetra(string letra);
        void setLeccion(Leccion* lec);
        //getters
        int getIdEjercicio();
        string getDescripcion();
        string getLetra();
        Leccion* getLeccion();
        //constructor y destructor
        ~Ejercicio();
        //operaciones
        string mostrarEjercicio();
        virtual bool esCorrectoRellenarPal(list<string> respuestas)=0;
        virtual bool esCorrectoTraduccion(string solucion)=0;
        void aumentarProgreso(string estudiante);
        void conseguirInfoEjercicio(list<string> &infoEjercicio);
};


#endif