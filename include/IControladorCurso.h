#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO
#include "Utils.h"
#include "Curso.h"
#include "DTCurso.h"
#include "DTLeccion.h"
#include "DTEjercicio.h"
#include "DTEstadisticaCurso.h"
#include "DTProfesor.h"
//#include "DTIdioma.h"??



class IControladorCurso{
    private:
        set<Curso> cursos;
        set<Idioma> idiomas;//Es extraño que el controlador de curso controle idiomas. Pero bueno
        
        //Pseudoatributos...?
        map<int, Ejercicio*> ejercicios;//el objeto estaria dentro de la leccion dentro del set de lecciones de cada curso

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
        ~IControladorCurso();

        //Getters
        DTCurso getDatosDeCurso();
        DTLeccion getDatosDeLeccion();
        DTProfesor getDatosDeProfesor();
        string getDatoIdioma();
        set<DTCurso*> getDatosPrevias();
        DTEjercicio getDatosEjercicio();
        //Setters
        void setDatosDeCurso(DTCurso datos);            //void DatosCurso(DTCurso data)
        void setDatosDeLeccion(DTLeccion datos);        //void IngresaLeccion(DTLeccion lec);
        void setDatosDeProfesor(string nombreProfesor); //void seleccionProfesor(string nick);
        void setDatoIdioma(string idioma);              //void seleccionIdioma(string idioma);
        void setDatosPrevias(set<DTCurso*> previas);    //void seleccionPrevias(set<string> previas);
        void setDatosEjercicioComletarpPalabras(DTEjercicio datos);      //void agregarCompPal(string descripcion, string fraseCompleta, set<string> solucion);
        void setDatosEjercicioTraduccion(DTEjercicio datos);             //void agregarTradu(string descripcion, string fraseATraducir, string traduccion);



        //Operaciones para modificar el set de cursos
        bool altaCurso();
        void eliminarCurso(string curso);
        void habilitarCurso(string curso);

        //Operaciones para modificar el set de idiomas
        bool altaIdioma();

        //Operaciones para modificar el set de ejercicios
        void agregarEjercicio(DTEjercicio datos);

        //Operaciones para obtener informacion
        set<string> listarProfe();
        DTEstadisticaCurso estadisticasCurso(string curso);
        set<string> listarNombresDeCursos();
        set<DTCurso> listarDTCursos();
        set<string> listarIdiomasProfesor();
        set<string> listarIdiomas();
        bool solucionCorrectacompletarPalabras(set<string> solucion, string estudiante, int IdEjercicio);
        bool solucionCorrectaTraduccion(string solucion, string estudiante, int IdEjercicio);
        void seleccionarEjercicio(int idEjercicio);
        set<DTEjercicio> seleccionarEjerciciosDeCurso(string curso);//set<DTEjercicio> seleccionarCurso(string curso);

        //Operaciones de suscripciones
        set<string> consultarSuscripciones(string nick);
        void suscribirUsuario(set<string> idiomas);
        set<string> listarIdiomasSuscrito(string nick);//no iria en controlador usuario??
        void eliminarSuscripciones(set<string> idiomas, string nick);//en el diagrama de clases falta el nick

        //Otras operaciones
        void limpiarDatos(); //borra todos los datos de los atributos auxiliares






        //Operaciones que creo que estan mal
        set<string> CursosInscriptoSinAprobar(string nick);// esto no va en controlador usuario??

};


#endif