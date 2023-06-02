#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO
#include "Utils.h"
#include "Curso.h"
#include "DTCurso.h"
#include "DTLeccion.h"
#include "DTEjercicioConId.h"
#include "DTEstadisticaCurso.h"




class IControladorCurso{
    private:
        set<Curso> cursos;
        DTCurso datosDeCurso;
        DTLeccion datosDeLeccion;

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
        //Setters
        void setDatosDeCurso(DTCurso datos);    //void DatosCurso(DTCurso data)
        void setDatosDeLeccion(DTLeccion datos);//void IngresaLeccion(DTLeccion lec);


        //Operaciones para modificar el set de cursos
        bool altaCurso();
        void eliminarCurso(string curso);


        //Operaciones para obtener informacion
        set<string> listarProfe();
        DTEstadisticaCurso estadisticasCurso(string curso);
        set<string> listarNombresDeCursos();
        set<DTCurso> listarDTCursos();


        //Operaciones sin clasificar
        void seleccionProfesor(string nick);
        set<string> ListarIdiomasProfesor();
        void seleccionIdioma(string idioma);
        void SeleccionPrevias(set<string> previas);
        void agregarCompPal(string descripcion, string fraseCompleta, set<string> solucion);
        void agregarTradu(string descripcion, string fraseATraducir, string traduccion);
        set<string> ListarIdiomas();
        set<string> CursosInscriptoSinAprobar(string nick);
        set<DTEjercicioConId> seleccionarCurso(string curso);//por que seleccionar curso devuelve un set de ejercicios con id?
        void seleccionarEjercicio(int idEjercicio);//hay montones de cosas como esta. es mas facil usar getters y setters
        bool completarPalabras(set<string> solucion, string estudiante, int IdEjercicio);
        bool traducir(string solucion, string estudiante, int IdEjercicio);
        set<string> consultarSuscripciones(string nick);
        void suscribirUsuario(set<string> idiomas);
        set<string> ListarIdiomasSuscrito(string nick);
        void eliminarSuscripciones(set<string> idiomas);




        
};


#endif
