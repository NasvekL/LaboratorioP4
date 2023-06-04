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
#include "../DTs/DTEstudianteSC.h"
#include "../DTs/DTCurso.h"
#include "../DTs/DTLeccion.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTEstadisticaCurso.h"



class ControladorUsuario : public IControladorUsuario{
    private:
        map<string,Usuario> usuarios;
        
        //Pseudoatributos...?


        //Atributos auxiliares con punteros
        DTEstudiante* datoEstudiante;


         //Variable estática para almacenar la instancia única del controlador
        static ControladorUsuario * instancia;
        //Constructor privado para evitar la creación de instancias desde fuera de la clase
        ControladorUsuario();

    public:
        //Método estático para obtener la instancia única del controlador
        static ControladorUsuario* getInstancia();
        ~ControladorUsuario();

        //Getters
        DTEstudiante getDatoEstudiante();
        //Setters
        void setDatoEstudiante(DTEstudiante dato); //void guardarDatosEstudiante(DTEstudiante data);

        //Operaciones para modificar el set de usuarios


        //Operaciones para obtener informacion
        list<string> listarCursos();
        DTEstadisticaProfesor estadisticasProfesor(string profesor);
        DTEstadisticaEstudiante estadisticasEstudiante(string estudiante);
        list<DTProfesorSC> listarProfesoresSinContra();
        list<DTEstudianteSC> listarEstudiantes();

        //Operaciones de suscripciones
        Usuario obtenerSuscriptor(string user);
        void eliminarNotificaciones();
        list<DTNotificacion> consultarNotificaciones(string nick);

        
        //FALTA CLASIFICAR. DESPUES. EN ALGUN MOMENTO. A MEDIDA QUE LO VAYAMOS USANDO
        list<DTEjercicio> ejerciciosNoAprobados(string curso);
        list<string> cursosInscriptosSinAprobar(string nick);
        list<string> listarProfesores();
        list<string> listarIdiomasProfesor(DTProfesor p);
        Profesor encontrarProfesor(string nick);
        void confirmarAltaUsuario();
        void deleteDataIngresado();
        void guardarDatosProfesor(DTProfesor data);
        list<string> listarIdiomas();


        //Operacion que no tiene sentido que este aca (iria en controladorCurso)
        DTEstadisticaCurso estadisticaCurso(string curso);
        //Operacion dudosa
        Curso obtenerCurso(string curso);
};      



#endif