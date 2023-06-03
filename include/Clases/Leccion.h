#ifndef LECCION
#define LECCION
#include "../Utils.h"
#include "Ejercicio.h"
#include "Estudiante.h"
class Leccion{
    private:
        string tema;
        string objetivoAprendizaje;
        int cantidadDeEjercicios;
        int numero;
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
        //Constructor Destructor
        ~Leccion();
        Leccion(string tema,string objetivoAprendizaje,int cantidadDeEjercicios,int numero);
        //operaciones
        Ejercicio seleccionarEj(int idEjercicio);
        void aumentarProgreso(Estudiante e);
        set<DTEjercicioConId> ejerciciosNoAprobados(string nick);
};
#endif;