#ifndef LECCION
#define LECCION
#include "../Utils.h"
#include "Ejercicio.h"
#include "Estudiante.h"
#include "RellenarPalabras.h"
#include "Traduccion.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTTraduccion.h"
#include "../DTs/DTRellenarPalabras.h"
class DTTraduccion;
class DTRellenarPalabras;
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
        void addEjercicio(Ejercicio* ej);
        //getters
        string getTema();
        string getObjetivoAprendizaje();
        int getCantidadDeEjercicios();
        int getNumero();
        map<int, Ejercicio*> getEjercicios();
        //Constructor Destructor
        ~Leccion();
        Leccion(string tema,string objetivoAprendizaje,int cantidadDeEjercicios,int numero,list<DTRellenarPalabras> listaRellenarPalabras,list<DTTraduccion> listaTraduccion);
        //operaciones
        DTEjercicio seleccionarEj(int idEjercicio);
        void aumentarProgreso(Estudiante e);
        set<DTEjercicio> ejerciciosNoAprobados(string nick);
};
#endif