#ifndef LECCION
#define LECCION
#include "../Utils.h"
#include "Ejercicio.h"
#include "Estudiante.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTEjercicio.h"
class Ejercicio;
class Leccion{
    private:
        string tema;
        string objetivoAprendizaje;
        int cantidadDeEjercicios;
        int numero;
        map<int, Ejercicio*> ejercicios;

    public:
        //setters
        void setTema(string tema);
        void setObjetivoAprendizaje(string objetivoAprendizaje);
        void setCantidadEjercicios(int cantidadDeEjercicios);
        void setNumero(int numero);
        //getters
        string getTema();
        string getObjetivoAprendizaje();
        int getCantidadDeEjercicios();
        int getNumero();
        map<int, Ejercicio*> getEjercicios();
        //Constructor Destructor
        ~Leccion();
        Leccion(string tema,string objetivoAprendizaje,int cantidadDeEjercicios,int numero);
        //operaciones
        DTEjercicio seleccionarEj(int idEjercicio);
        void aumentarProgreso(Estudiante e);
        set<DTEjercicio> ejerciciosNoAprobados(string nick);
};
#endif