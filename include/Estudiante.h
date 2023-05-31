#ifndef ESTUDIANTE
#define ESTUDIANTE
#include "Utils.h"
#include "Usuario.h"

    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS
class Inscripcion;

class Estudiante: public Usuario{
    private:   
        string pais;
        Fecha nacimiento;
        //Pseudoatributos
        set<Inscripcion*> inscripciones;
    public:
        //Getters y Setters
        string getPais();
        Fecha getNacimineto();
        //Create destroy
        ~Estudiante();
        Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, Fecha nacimiento);
        //Otras operaciones
        set<DTNotificación> verNotificaciones();
        DTEstudiante getDTEstudiante();
        set<string> getCursosInscriptosSA();
        set<DTCurso> obtenDTCurso();
        set<int> obtenerProgreso();
        set<Inscripcion*>& Inscripciones();  //PseudoAtributo
        //Faltan los casos de uso que me permiten agregar y eliminar inscripciones
};


#endif