#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO
#include "../Utils.h"
#include "../Clases/Curso.h"
#include "../DTs/DTCurso.h"
#include "../DTs/DTLeccion.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTEstadisticaCurso.h"
#include "../DTs/DTProfesor.h"
//#include "DTIdioma.h"??



class IControladorCurso{
    private:
        
    public:
        public:
        // Métodos públicos virtuales
        virtual ~IControladorCurso();

        //Getters virtuales
        virtual DTCurso getDatosDeCurso();
        virtual DTLeccion getDatosDeLeccion();
        virtual DTProfesor getDatosDeProfesor();
        virtual string getDatoIdioma();
        virtual set<DTCurso*> getDatosPrevias();
        virtual DTEjercicio getDatosEjercicio();
        //Setters virtuales
        virtual void setDatosDeCurso(DTCurso datos);
        virtual void setDatosDeLeccion(DTLeccion datos);
        virtual void setDatosDeProfesor(string nombreProfesor);
        virtual void setDatoIdioma(string idioma);
        virtual void setDatosPrevias(set<DTCurso*> previas);
        virtual void setDatosEjercicioComletarpPalabras(DTEjercicio datos);
        virtual void setDatosEjercicioTraduccion(DTEjercicio datos);

        //Operaciones virtuales para modificar el set de cursos
        virtual bool altaCurso();
        virtual void eliminarCurso(string curso);
        virtual void habilitarCurso(string curso);

        //Operaciones virtuales para modificar el set de idiomas
        virtual bool altaIdioma();

        //Operaciones virtuales para modificar el set de ejercicios
        virtual void agregarEjercicio(DTEjercicio datos);

        //Operaciones virtuales para obtener información
        virtual set<string> listarProfe();
        virtual DTEstadisticaCurso estadisticasCurso(string curso);
        virtual set<string> listarNombresDeCursos();
        virtual set<DTCurso> listarDTCursos();
        virtual set<string> listarIdiomasProfesor();
        virtual set<string> listarIdiomas();
        virtual bool solucionCorrectacompletarPalabras(set<string> solucion, string estudiante, int IdEjercicio);
        virtual bool solucionCorrectaTraduccion(string solucion, string estudiante, int IdEjercicio);
        virtual void seleccionarEjercicio(int idEjercicio);
        virtual set<DTEjercicio> seleccionarEjerciciosDeCurso(string curso);

        //Operaciones virtuales de suscripciones
        virtual set<string> consultarSuscripciones(string nick);
        virtual void suscribirUsuario(set<string> idiomas);
        virtual set<string> listarIdiomasSuscrito(string nick);
        virtual void eliminarSuscripciones(set<string> idiomas, string nick);

        //Otras operaciones virtuales
        virtual void limpiarDatos();

        //Operaciones que creo que están mal
        virtual set<string> CursosInscriptoSinAprobar(string nick);
};


#endif