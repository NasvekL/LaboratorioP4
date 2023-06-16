#ifndef ESTUDIANTE
#define ESTUDIANTE
#include "../Utils.h"
#include "Usuario.h"
#include "../DTs/DTEstudiante.h"
#include "../DTs/DTNotificacion.h"
#include "../DTs/DTCurso.h"
#include "../Clases/Inscripcion.h"

    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS
class Inscripcion;

class Estudiante: public Usuario{
    private:   
        string pais;
        DTFecha nacimiento;
        //Pseudoatributos
        list<Inscripcion*> inscripciones;
    public:
        //Getters y Setters
        string getPais();
        DTFecha getNacimiento();
        list<Inscripcion*> getInscripciones();
        //Create destroy
        ~Estudiante();
        Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, DTFecha nacimiento);
        //Otras operaciones
        list<DTNotificacion> verNotificaciones();
        DTEstudiante getDTEstudiante();
        set<string> getCursosInscriptosSA();
        set<DTCurso> obtenDTCurso();
        set<int> obtenerProgreso();
        list<Inscripcion*>& Inscripciones();  //PseudoAtributo
        //Faltan los casos de uso que me permiten agregar y eliminar inscripciones

        void agregarInscripcion(Inscripcion* insc);
        void eliminarInscripcion(Inscripcion* insc);
};


#endif