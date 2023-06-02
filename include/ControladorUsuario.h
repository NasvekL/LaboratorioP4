#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO
#include "Utils.h"
#include "IControladorUsuario.h"
#include "DTEstudiante.h"
#include "DTEstadisticaCurso.h"
#include "DTEstadisticaProfesor.h"
#include "DTEstadisticaEstudiante.h"
#include "Usuario.h"
#include "DTNotificacion.h"



class ControladorUsuario : public IControladorUsuario{
    private:
        static ControladorUsuario * instancia;
        ControladorUsuario();
    public:
        ControladorUsuario * getInstance();
        void guardarDatosEstudiante(DTEstudiante data);
        DTEstadisticaCurso estadisticaCurso(string curso);
        set<DTCurso> listarCursos();
        Usuario obtenerSuscriptor(string user);
        void eliminarNotificaciones();
        set<DTNotificacion> consultarNotificaciones(string nick);
        DTEstadisticasProfesor estadisticasProfesor(string profesor);
        //me faltaron algunas
}