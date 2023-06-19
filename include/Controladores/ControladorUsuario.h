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


class ControladorUsuario : public IControladorUsuario{
    private:
        map<string,Usuario*> usuarios;
        
        //Pseudoatributos...?


        //Atributos auxiliares con punteros
        DTEstudiante* datoEstudiante;
        DTProfesor* datoProfesor;

         //Variable estática para almacenar la instancia única del controlador
        static ControladorUsuario* instancia;
        //Constructor privado para evitar la creación de instancias desde fuera de la clase
        ControladorUsuario();

    public:

        //Método estático para obtener la instancia única del controlador
        static ControladorUsuario& getInstancia();
        ~ControladorUsuario();


        void agregarInscripcionAEstudiante(string estudiante, Inscripcion* inscri);

        //Getters
        DTEstudiante getDatoEstudiante();
        map<string,Usuario>* getUsuarios();
        DTProfesor getDatoProfesor();
        string getTipoUsuario(string nick);
        Usuario* getUsuario(string nick);
        //Setters
        void setDatoEstudiante(DTEstudiante dato); //void guardarDatosEstudiante(DTEstudiante data);
        void setDatoProfesor(DTProfesor dato);
        //Operaciones para modificar el set de usuarios
        

        //Operaciones para obtener informacion
        list<string> listarCursos();
        DTEstadisticaProfesor estadisticasProfesor(string profesor);
        DTEstadisticaEstudiante estadisticasEstudiante(string estudiante);
        list<DTProfesorSC> listarProfesoresSinContra();
        list<DTEstudianteSC> listarEstudiantes();
        list<string> listarUsuarios();
        bool existeUsuario(string nick);

        //Operaciones de suscripciones
        Usuario* obtenerSuscriptor(string user);
        void eliminarNotificaciones(string nick);
        list<DTNotificacion> consultarNotificaciones(string nick);

        
        //FALTA CLASIFICAR. DESPUES. EN ALGUN MOMENTO. A MEDIDA QUE LO VAYAMOS USANDO
        list<DTEjercicio> ejerciciosNoAprobados(string curso);
        set<string> cursosInscriptosSinAprobar(string nick);
        list<string> listarProfe();
        set<Idioma*> listarIdiomasProfesor(Profesor* p);
        Profesor* encontrarProfesor(string nick);
        Estudiante* encontrarEstudiante(string nick);
        void confirmarAltaUsuario();
        void deleteDataIngresado();

        list<string> listarIdiomas();
        void seleccionarUsuario(string nick);
        //Operacion que no tiene sentido que este aca (iria en controladorCurso)
        DTEstadisticaCurso estadisticaCurso(string curso);
        //Operacion dudosa
        Curso* obtenerCurso(string curso);

        list<string> consultarUsuario();
        void limpiarDatos();
};      
#endif