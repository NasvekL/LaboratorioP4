#ifndef ICONTROLADORUSUARIO
#define ICONTROLADORUSUARIO
#include "../Utils.h"


class IControladorUsuario{
    public:
        virtual ControladorUsuario * getInstance() = 0;
        virtual set<string> listarProfes();
        virtual void seleccionarProfesor(string nick);
        virtual void datosCurso(DTCurso data);
        virtual set<string> listarIdiomasProfesor();
        virtual void seleccionarIdioma(string idioma);
        virtual set<string> listarNombresCursos();
        virtual void seleccionPrevias(set<string> previas);
        virtual void ingresaLeccion(DTLeccion lec);
        virtual void agregarCompPal(string descripcion, string fraseCompleta, set<string> solucion);
        virtual void agregarTradu(string descripcion,string fraseATraducir, string traduccion);
        virtual set<string> listarIdiomas();
        virtual list<string> listarCursos();
        virtual bool altaCurso();
        virtual void eliminarCurso(string curso);
        virtual set<string> cursosInscriptosSinAprobar(string nick);
        virtual set<DTEjercicio> seleccionarCurso(string curso);
        virtual void seleccionarEjercicio(int id);
        virtual bool completarPalabras(set<string> solucion, string estudiante, int idEjercicio);
        virtual bool traducir(string solucion, string estudiante, int idEjercicio);
        virtual void eliminarSuscripcion(set<string> idiomas);
        virtual set<string> listarIdiomasSuscrito(string nick);
        virtual void suscribirUsuario(set<string> idiomas);
        virtual set<string> consultarSuscripciones(string nick);
        virtual DTEstadisticaCurso estadisticasCurso(string curso);
};




#endif