#ifndef CONTROLADORCURSO
#define CONTROLADORCURSO
#include "Utils.h"
#include "IControladorCurso.h"
#include "DTCurso.h"
#include "DTLeccion.h"
#include "DTEjercicioConId.h"
#include "DTEstadisticaCurso.h"

class ControladorCurso : public IControladorCurso{
    private:
        static ControladorCurso * instancia;
        ControladorCurso();
    public:
        ControladorCurso * getInstance()
        set<string> listarProfes();
        void seleccionarProfesor(string nick);
        void datosCurso(DTCurso data);
        set<string> listarIdiomasProfesor();
        void seleccionarIdioma(string idioma);
        set<string> listarNombresCursos();
        void seleccionPrevias(set<string> previas);
        void ingresaLeccion(DTLeccion lec);
        void agregarCompPal(string descripcion, string fraseCompleta, set<string> solucion);
        void agregarTradu(string descripcion,string fraseATraducir, strig traduccion);
        set<string> listarIdiomas();
        set<string> listarCursos();
        bool altaCurso()
        void eliminarCurso(string curso);
        set<string> cursosInscriptosSinAprobar(string nick);
        set<DTEjercicioConId> seleccionarCurso(string curso);
        seleccionarEjercicio(integer id);
        bool completarPalabras(set<string> solucion, string estudiante, integer idEjercicio);
        bool traducir(string solucion, string estudiante, integer idEjercicio);
        void eliminarSuscripcion(set<string> idiomas);
        set<string> listarIdiomasSuscrito(string nick);
        void suscribirUsuario(set<string> idiomas);
        set<string> consultarSuscripciones(string nick);
        DTEstadisticaCurso estadisticasCurso(string curso);
};