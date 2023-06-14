#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO
#include "../Utils.h"
#include "../DTs/DTEstudiante.h"
#include "../DTs/DTEstadisticaCurso.h"
#include "../DTs/DTEstadisticaProfesor.h"
#include "../DTs/DTEstadisticaEstudiante.h"
#include "../Clases/Usuario.h"
#include "../Clases/Curso.h"
#include "../Clases/Profesor.h"
#include "../DTs/DTNotificacion.h"
#include "../DTs/DTProfesorSC.h"
#include "../DTs/DTEstudianteSC.h"

class IControladorUsuario{
    public:
        // Getters
    virtual DTEstudiante getDatoEstudiante() = 0;
    virtual DTProfesor getDatoProfesor() = 0;
    // Setters
    virtual void setDatoEstudiante(DTEstudiante dato) = 0;
    virtual void setDatoProfesor(DTProfesor dato) = 0;
    // Operaciones para modificar el set de usuarios

    // Operaciones para obtener información
    virtual std::list<std::string> listarCursos() = 0;
    virtual DTEstadisticaProfesor estadisticasProfesor(std::string profesor) = 0;
    virtual DTEstadisticaEstudiante estadisticasEstudiante(std::string estudiante) = 0;
    virtual std::list<DTProfesorSC> listarProfesoresSinContra() = 0;
    virtual std::list<DTEstudianteSC> listarEstudiantes() = 0;
    virtual string getTipoUsuario(string nick) = 0;
    // Operaciones de suscripciones
    virtual Usuario obtenerSuscriptor(std::string user) = 0;
    virtual void eliminarNotificaciones() = 0;
    virtual std::list<DTNotificacion> consultarNotificaciones(std::string nick) = 0;

    // Métodos adicionales que faltan clasificar
    virtual void seleccionarUsuario(std::string nickname) = 0;
    virtual std::list<DTEjercicio> ejerciciosNoAprobados(std::string curso) = 0;
    virtual std::list<std::string> cursosInscriptosSinAprobar(std::string nick) = 0;
    virtual list<string> listarProfe() = 0;
    virtual void listarIdiomasProfesor(Profesor p) = 0;
    virtual Profesor encontrarProfesor(std::string nick) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual void deleteDataIngresado() = 0;
    virtual void listarIdiomas() = 0;
    virtual bool existeUsuario(string nickname) = 0;
    // Operaciones que no tienen sentido estar aquí
    virtual DTEstadisticaCurso estadisticaCurso(std::string curso) = 0;
    virtual Curso obtenerCurso(std::string curso) = 0;

    virtual list<string> consultarUsuario() = 0;
};
    



#endif