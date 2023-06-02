#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO
#include "Utils.h"
#include "DTCurso.h"
#include "DTLeccion.h"
#include "DTEjercicioConId.h"
#include "DTEstadisticaCurso.h"




class IControladorCurso{
    private:
        // Variable estática para almacenar la instancia única del controlador
        static IControladorCurso* instancia;
        // Constructor privado para evitar la creación de instancias desde fuera de la clase
        IControladorCurso();
    public:
        // Método estático para obtener la instancia única del controlador
        static IControladorCurso* getInstancia();


        //Otras operaciones
        set<string> ListarProfe();
        void seleccionProfesor(string nick);
        void DatosCurso(DTCurso data);
        set<string> ListarIdiomasProfesor();
        void seleccionIdioma(string idioma);
        set<string> ListarNombresCursos();
        void SeleccionPrevias(set<string> previas);
        void IngresaLeccion(DTLeccion lec);
        void agregarCompPal(string descripcion, string fraseCompleta, set<string> solucion);
        void agregarTradu(string descripcion, string fraseATraducir, string traduccion);
        set<string> ListarIdiomas();
        bool AltaCurso();
        void eliminarCurso(string curso);
        set<string> CursosInscriptoSinAprobar(string nick);
        set<DTEjercicioConId> seleccionarCurso(string curso);
        void seleccionarEjercicio(int idEjercicio);
        bool completarPalabras(set<string> solucion, string estudiante, int IdEjercicio);
        bool traducir(string solucion, string estudiante, int IdEjercicio);
        DTEstadisticaCurso estadisticasCurso(string curso);
        set<string> consultarSuscripciones(string nick);
        void suscribirUsuario(set<string> idiomas);
        set<string> ListarIdiomasSuscrito(string nick);
        void eliminarSuscripciones(set<string> idiomas);



        set<string> listarCursos();
        set<DTCurso> listarCursos();//Ta mal. No se pueden llamar igual




        v
};


#endif
