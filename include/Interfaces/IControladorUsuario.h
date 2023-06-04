#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO
#include "../Utils.h"
#include "../DTs/DTCurso.h"
#include "../DTs/DTLeccion.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTEstadisticaCurso.h"

class IControladorUsuario{
    public:
        //virtual ControladorUsuario * getInstancia() = 0;
        virtual list<string> listarProfes();
        virtual void seleccionarProfesor(string nick);
        virtual void datosCurso(DTCurso data);
        virtual list<string> listarIdiomasProfesor();
        virtual void seleccionarIdioma(string idioma);
        virtual list<string> listarNombresCursos();
        virtual void seleccionPrevias(set<string> previas);
        virtual void ingresaLeccion(DTLeccion lec);
        virtual void agregarCompPal(string descripcion, string fraseCompleta, set<string> solucion);
        virtual void agregarTradu(string descripcion,string fraseATraducir, string traduccion);
        virtual list<string> listarIdiomas();
        virtual list<string> listarCursos();
        virtual bool altaCurso();
        virtual void eliminarCurso(string curso);
        virtual list<string> cursosInscriptosSinAprobar(string nick);
        virtual list<DTEjercicio> seleccionarCurso(string curso);
        virtual DTEjercicio seleccionarEjercicio(int id);
        virtual bool completarPalabras(set<string> solucion, string estudiante, int idEjercicio);
        virtual bool traducir(string solucion, string estudiante, int idEjercicio);
        virtual void eliminarSuscripcion(set<string> idiomas);
        virtual list<string> listarIdiomasSuscrito(string nick);
        virtual void suscribirUsuario(set<string> idiomas);
        virtual list<string> consultarSuscripciones(string nick);
        virtual DTEstadisticaCurso estadisticasCurso(string curso);
};




#endif