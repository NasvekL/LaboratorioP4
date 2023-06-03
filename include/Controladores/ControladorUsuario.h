#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO
#include "../Utils.h"
#include "../Interfaces/IControladorUsuario.h"
#include "../DTs/DTEstudiante.h"
#include "../DTs/DTEstadisticaCurso.h"
#include "../DTs/DTEstadisticaProfesor.h"
#include "../DTs/DTEstadisticaEstudiante.h"
#include "../Clases/Usuario.h"
#include "../Clases/Curso.h"
#include "../Clases/Profesor.h"
#include "../DTs/DTNotificacion.h"
#include "../DTs/DTProfesorSC.h"


class ControladorUsuario : public IControladorUsuario{
    private:
        static ControladorUsuario * instancia;
        ControladorUsuario();
    public:
        static ControladorUsuario * getInstance();
        void guardarDatosEstudiante(DTEstudiante data);
        DTEstadisticaCurso estadisticaCurso(string curso);
        list<DTCurso> listarCursos();
        Usuario obtenerSuscriptor(string user);
        void eliminarNotificaciones();
        list<DTNotificacion> consultarNotificaciones(string nick);
        DTEstadisticasProfesor estadisticasProfesor(string profesor);
        list<DTProfesorSC> listarProfesoresSinContra();
        DTEstadisticasEstudiante estadisticasEstudiante(string estudiante);
        set(DTEstudianteSC) listarEstudiantes();
        Curso obtenerCurso(string curso);
        list(DTEjercicioConId) ejerciciosNoAprobados(string curso);
        list<string> cursosInscriptosSinAprobar(string nick);
        list<string> listarProfesores();
        list<string> listarIdiomasProfesor(DTProfesor p);
        Profesor encontrarProfesor(string nick);
        void confirmarAltaUsuario();
        void deleteDataIngresado();
        void guardarDatosProfesor(DTProfesor data);
        list<string> listarIdiomas();
};      

#endif