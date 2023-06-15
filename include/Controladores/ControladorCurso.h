#ifndef CONTROLADORCURSO
#define CONTROLADORCURSO
#include "../Utils.h"
#include "../Clases/Curso.h"
#include "../Clases/RellenarPalabras.h"
#include "../Clases/Traduccion.h"
#include "../Clases/Ejercicio.h"
#include "../DTs/DTCurso.h"
#include "../DTs/DTLeccion.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTEstadisticaCurso.h"
#include "../DTs/DTProfesor.h"
#include "../DTs/DTTraduccion.h"
#include "../DTs/DTRellenarPalabras.h"
#include "../Interfaces/IControladorCurso.h"



class ControladorCurso: public IControladorCurso{
    private:
        map<string, Curso*> cursos;
        map<string, Idioma*> idiomas;//Es extraño que el controlador de curso controle idiomas. Pero bueno
        
        //Pseudoatributos...?
        map<int, Ejercicio*> ejercicios;//el objeto estaria dentro de la leccion dentro del set de lecciones de cada curso

        int idEjercicio; // idEjercicioActual

        //Atributos auxiliares con punteros
        DTCurso* datoDeCurso;
        DTLeccion* datoDeLeccion;
        list<DTLeccion> datosLecciones;
        Profesor* profesor;
        string datoIdioma;
        map<string, Curso*> datosPrevias;
        DTRellenarPalabras* datosRellenar;
        DTTraduccion* datosTraducir;
        list<DTRellenarPalabras> datosRellenarPalabras;
        list<DTTraduccion> datosTraduccion;
        
        //Variable estática para almacenar la instancia única del controlador
        static ControladorCurso* instancia;
        //Constructor privado para evitar la creación de instancias desde fuera de la clase
        ControladorCurso();

    public:
        //Método estático para obtener la instancia única del controlador
        static ControladorCurso& getInstancia();
        ~ControladorCurso();

        
    
        //Getters
        //fdfd
        map<string,Curso*> getCursos();
        int getIdEjercicio ();
        Idioma* getIdioma(string nombre);
        DTCurso getDatoDeCurso();
        DTLeccion getDatosDeLeccion();
        list<DTLeccion> getDatosLecciones();
        list<DTRellenarPalabras> getDatosMuchasRellenarPalabras();
        list<DTTraduccion> getDatosMuchasTraducciones();
        string getDatoNombreDeProfesor();
        Profesor* getProfesor();
        string getDatoIdioma();
        map<string ,Curso*> getDatosPrevias();
        DTRellenarPalabras getDatosRellenar();
        DTTraduccion getDatosTraduccion();
        Curso getCurso(string nombreCurso);
        int getNumeroDeLeccion(string cursoSeleccionado);
        //Setters
        void setIdEjercicio(int id);
        void setDatoDeCurso(DTCurso datos);            //void DatosCurso(DTCurso data)
        void setDatosDeLeccion(DTLeccion datos);        //void IngresaLeccion(DTLeccion lec);
        //hace que el puntero profesor apunte al objeto profesor que se le pasa
        void setProfesor(Profesor* profesor); //void seleccionProfesor(string nick);
        void setDatoIdioma(string idioma);              //void seleccionIdioma(string idioma);
        void setDatosPrevias(set<Curso*> previas);    //void seleccionPrevias(set<string> previas);
        void setDatosEjercicioCompletarPalabras(DTRellenarPalabras datos);      //void agregarCompPal(string descripcion, string fraseCompleta, set<string> solucion);
        void setDatosEjercicioTraduccion(DTTraduccion datos);             //void agregarTradu(string descripcion, string fraseATraducir, string traduccion);
        void agregarDatosRellenarPalabras(DTRellenarPalabras ejRellPal);
        void agregarDatosTraduccion(DTTraduccion tradu);


        //Operaciones para modificar el set de cursos
        bool altaCurso();
        void altaLeccion(string curso);
        void altaEjercicio(Leccion* lec);
        void eliminarCurso(string nombreCurso);
        void habilitarCurso(string nombreCurso);

        void inscribirEstudianteACurso(string curso, string estudiante);

        //Operaciones para modificar el set de idiomas
        bool confirmarAltaIdioma(string idioma);
        //Operaciones para modificar el set de ejercicios
        void agregarEjercicio(DTEjercicio datos);
        

        //Operaciones para obtener informacion

        //Devuelve los nombres de los cursos a los que el usuario se puede inscribir, teniendo en cuenta los cursos habilitados, las previas y eso
        list<string> cursosDisponibles(string nick);
        void seleccionIdioma(string idi);
        void seleccionarProfesor(string nick);
        list<string> listarProfe();
        DTEstadisticaCurso estadisticasCurso(string curso);
        set<string> listarNombresDeCursos();
        set<DTCurso> listarDTCursos();
        set<Idioma*> listarIdiomasProfesor();
        void listarIdiomas();
        void listarCursosNoHabilitados();
        bool solucionCorrectaCompletarPalabras(set<string> solucion, string estudiante, int IdEjercicio);
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



        //Operacion que solo llama a otra opperacion en controladorUsuario
        void cursosInscriptoSinAprobar(string nick);

        set<DTLeccion> ListarLecciones(string cursoLec);

};


#endif