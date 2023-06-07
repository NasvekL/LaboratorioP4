#ifndef CONTROLADORCURSO
#define CONTROLADORCURSO
#include "../Utils.h"
#include "../Clases/Curso.h"
#include "../DTs/DTCurso.h"
#include "../DTs/DTLeccion.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTEstadisticaCurso.h"
#include "../DTs/DTProfesor.h"
//#include "DTIdioma.h"??
#include "../Interfaces/IControladorCurso.h"



class ControladorCurso: public IControladorCurso{
    private:
        map<string, Curso> cursos;
        map<string, Idioma> idiomas;//Es extraño que el controlador de curso controle idiomas. Pero bueno
        
        //Pseudoatributos...?
        map<int, Ejercicio*> ejercicios;//el objeto estaria dentro de la leccion dentro del set de lecciones de cada curso

        //Atributos auxiliares con punteros
        DTCurso* datosDeCurso;
        DTLeccion* datosDeLeccion;
        string* datoNombreDeProfesor;
        string* datoIdioma;
        set<DTCurso*>* datosPrevias;
        DTEjercicio* datosEjercicio;


        //Variable estática para almacenar la instancia única del controlador
        static ControladorCurso* instancia;
        //Constructor privado para evitar la creación de instancias desde fuera de la clase
        ControladorCurso(){};

    public:
        //Método estático para obtener la instancia única del controlador
        static ControladorCurso& getInstancia();
        ~ControladorCurso();


    
        //Getters
        DTCurso getDatosDeCurso();
        DTLeccion getDatosDeLeccion();
        string getDatoNombreDeProfesor();
        string getDatoIdioma();
        set<DTCurso*> getDatosPrevias();
        DTEjercicio getDatosEjercicio();
        Curso getCurso(string nombreCurso);
        //Setters
        void setDatosDeCurso(DTCurso datos);            //void DatosCurso(DTCurso data)
        void setDatosDeLeccion(DTLeccion datos);        //void IngresaLeccion(DTLeccion lec);
        void setDatoNombreDeProfesor(string nombreProfesor); //void seleccionProfesor(string nick);
        void setDatoIdioma(string idioma);              //void seleccionIdioma(string idioma);
        void setDatosPrevias(set<DTCurso*> previas);    //void seleccionPrevias(set<string> previas);
        void setDatosEjercicioCompletarPalabras(DTEjercicio datos);      //void agregarCompPal(string descripcion, string fraseCompleta, set<string> solucion);
        void setDatosEjercicioTraduccion(DTEjercicio datos);             //void agregarTradu(string descripcion, string fraseATraducir, string traduccion);



        //Operaciones para modificar el set de cursos
        bool altaCurso();
        void eliminarCurso(string nombreCurso);
        void habilitarCurso(string nombreCurso);

        //Operaciones para modificar el set de idiomas
        bool confirmarAltaIdioma(string idioma);
        //Operaciones para modificar el set de ejercicios
        void agregarEjercicio(DTEjercicio datos);

        //Operaciones para obtener informacion
        set<string> listarProfe();
        DTEstadisticaCurso estadisticasCurso(string curso);
        set<string> listarNombresDeCursos();
        set<DTCurso> listarDTCursos();
        set<string> listarIdiomasProfesor();
        set<string> listarIdiomas();
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
        set<string> cursosInscriptoSinAprobar(string nick);

};


#endif