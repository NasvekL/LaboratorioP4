#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO
#include "../Utils.h"
#include "../Interfaces/IControladorUsuario.h"
#include "../DTs/DTEstudiante.h"
#include "../DTs/DTEstadisticaCurso.h"
#include "../DTs/DTEstadisticaProfesor.h"
#include "../DTs/DTEstadisticaEstudiante.h"
#include "../Clases/Usuario.h"
#include "../DTs/DTNotificacion.h"



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
};

#endif