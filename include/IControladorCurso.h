#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO
#include "Utils.h"
#include "Curso.h"
#include "DTCurso.h"
#include "DTLeccion.h"
#include "DTEjercicioConId.h"
#include "DTEstadisticaCurso.h"
#include "DTProfesor.h"
//#include "DTIdioma.h"??
#include "DTEjercicio.h"



class IControladorCurso{
    private:
        set<Curso> cursos;
        set<Idioma> idiomas;//Es extraño que el controlador de curso controle idiomas. Pero bueno

        //Atributos auxiliares
        DTCurso datosDeCurso;
        DTLeccion datosDeLeccion;
        DTProfesor datosDeProfesor;
        string datoIdioma;
        set<DTCurso*> datosPrevias;
        DTEjercicio datosEjercicio;


        // Variable estática para almacenar la instancia única del controlador
        static IControladorCurso* instancia;
        // Constructor privado para evitar la creación de instancias desde fuera de la clase
        IControladorCurso();

    public:
        // Método estático para obtener la instancia única del controlador
        static IControladorCurso* getInstancia();
        static void deleteInstancia();

        //Getters
        DTCurso getDatosDeCurso();
        DTLeccion getDatosDeLeccion();
        DTProfesor getDatosDeProfesor();
        string getDatoIdioma();
        set<DTCurso*> getDatosPrevias();
        //Setters
        void setDatosDeCurso(DTCurso datos);            //void DatosCurso(DTCurso data)
        void setDatosDeLeccion(DTLeccion datos);        //void IngresaLeccion(DTLeccion lec);
        void setDatosDeProfesor(string nombreProfesor); //void seleccionProfesor(string nick);
        void setDatoIdioma(string idioma);              //void seleccionIdioma(string idioma);
        void setDatosPrevias(set<DTCurso*> previas);    //void seleccionPrevias(set<string> previas);



        //Operaciones para modificar el set de cursos
        bool altaCurso();
        void eliminarCurso(string curso);


        //Operaciones para obtener informacion
        set<string> listarProfe();
        DTEstadisticaCurso estadisticasCurso(string curso);
        set<string> listarNombresDeCursos();
        set<DTCurso> listarDTCursos();
        set<string> listarIdiomasProfesor();
        set<string> listarIdiomas();


        //Operaciones sin clasificar
        void agregarCompPal(string descripcion, string fraseCompleta, set<string> solucion);
        void agregarTradu(string descripcion, string fraseATraducir, string traduccion);
        set<string> CursosInscriptoSinAprobar(string nick);
        void seleccionarEjercicio(int idEjercicio);//hay montones de cosas como esta. es mas facil usar getters y setters
        bool completarPalabras(set<string> solucion, string estudiante, int IdEjercicio);
        bool traducir(string solucion, string estudiante, int IdEjercicio);
        set<string> consultarSuscripciones(string nick);
        void suscribirUsuario(set<string> idiomas);
        set<string> ListarIdiomasSuscrito(string nick);
        void eliminarSuscripciones(set<string> idiomas);

        //Operaciones que creo que estan mal

        //Operaciones que no entiendo
        set<DTEjercicioConId> seleccionarCurso(string curso);//por que seleccionar curso devuelve un set de ejercicios con id?




        
};


#endif
