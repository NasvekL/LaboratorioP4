#ifndef LECCION
#define LECCION
#include "../Utils.h"
#include "Ejercicio.h"
#include "Estudiante.h"
#include "Progreso.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTTraduccion.h"
#include "../DTs/DTRellenarPalabras.h"
class Estudiante;
class Progreso;
class DTRellenarPalabras;
class Ejercicio;
class Leccion{
    private:
        string tema;
        string objetivoAprendizaje;
        int cantidadDeEjercicios;
        int numero;
        map<int, Ejercicio*> ejercicios;
        map<string, Progreso*> progresos;//nombre de estudiante, progreso
    public:
        //setters
        void setTema(string tema);
        void setObjetivoAprendizaje(string objetivoAprendizaje);
        void setCantidadEjercicios(int cantidadDeEjercicios);
        void setNumero(int numero);
        void agregarProgreso(Progreso* progreso);
        void addEjercicio(Ejercicio* ej);
        //getters
        string getTema();
        string getObjetivoAprendizaje();
        int getCantidadDeEjercicios();
        int getNumero();
        map<int, Ejercicio*> getEjercicios();
        map<string, Progreso*> getProgresos();
        //Constructor Destructor
        ~Leccion();
        Leccion(string tema,string objetivoAprendizaje,int cantidadDeEjercicios,int numero,list<DTRellenarPalabras> listaRellenarPalabras,list<DTTraduccion> listaTraduccion);
        //operaciones
        Ejercicio* seleccionarEj(int idEjercicio);
        void aumentarProgreso(Estudiante e);
        void eliminarProgreso(string nick);
        list<DTEjercicio> ejerciciosNoAprobados(string nick);
        void conseguirInfoLeccion(list<string> &infoLeccion);
};
#endif