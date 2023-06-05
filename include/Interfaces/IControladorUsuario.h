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
        virtual list<string> listarProfes()= 0;
        virtual void seleccionarProfesor(string nick)= 0;
        virtual void datosCurso(DTCurso data)= 0;
        virtual list<string> listarIdiomasProfesor()= 0;
        virtual void seleccionarIdioma(string idioma)= 0;
        virtual list<string> listarNombresCursos()= 0;
        virtual void seleccionPrevias(set<string> previas)= 0;
        virtual void ingresaLeccion(DTLeccion lec)= 0;
        virtual void agregarCompPal(string descripcion, string fraseCompleta, set<string> solucion)= 0;
        virtual void agregarTradu(string descripcion,string fraseATraducir, string traduccion)= 0;
        virtual list<string> listarIdiomas()= 0;
        virtual list<string> listarCursos()= 0;
        virtual bool altaCurso()= 0;
        virtual void eliminarCurso(string curso);
        virtual list<string> cursosInscriptosSinAprobar(string nick)= 0;
        virtual list<DTEjercicio> seleccionarCurso(string curso)= 0;
        virtual DTEjercicio seleccionarEjercicio(int id)= 0;
        virtual bool completarPalabras(set<string> solucion, string estudiante, int idEjercicio)= 0;
        virtual bool traducir(string solucion, string estudiante, int idEjercicio)= 0;
        virtual void eliminarSuscripcion(set<string> idiomas)= 0;
        virtual list<string> listarIdiomasSuscrito(string nick)= 0;
        virtual void suscribirUsuario(set<string> idiomas)= 0;
        virtual list<string> consultarSuscripciones(string nick)= 0;
        virtual DTEstadisticaCurso estadisticasCurso(string curso)= 0;
};




#endif