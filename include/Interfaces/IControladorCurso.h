#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO
#include "../Utils.h"
#include "../Clases/Curso.h"
#include "../DTs/DTCurso.h"
#include "../DTs/DTLeccion.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTEstadisticaCurso.h"
#include "../DTs/DTProfesor.h"
#include "../DTs/DTTraduccion.h"
#include "../DTs/DTRellenarPalabras.h"
//#include "DTIdioma.h"??



class IControladorCurso{
    private:
        
    public:
        // Métodos públicos virtuales
        //virtual ~IControladorCurso()= 0;
        //virtual IControladorCurso * getInstancia()= 0;

        //Getters virtuales
        virtual int getIdEjercicio()=0;
        virtual Idioma* getIdioma(string nombre)= 0;
        virtual DTCurso getDatosDeCurso()= 0;
        virtual DTLeccion getDatosDeLeccion()= 0;
        virtual string getDatoNombreDeProfesor()= 0;
        virtual string getDatoIdioma()= 0;
        virtual set<DTCurso*> getDatosPrevias()= 0;
        virtual DTEjercicio getDatosEjercicio()= 0;
        virtual Curso getCurso(string nombreCurso) = 0;
        //Setters virtuales
        virtual void setDatosDeCurso(DTCurso datos)= 0;
        virtual void setDatosDeLeccion(DTLeccion datos)= 0;
        virtual void setDatoNombreDeProfesor(string nombreProfesor)= 0;
        virtual void setDatoIdioma(string idioma)= 0;
        virtual void setDatosPrevias(set<DTCurso*> previas)= 0;
        virtual void setDatosEjercicioCompletarPalabras(DTEjercicio datos)= 0;
        virtual void setDatosEjercicioTraduccion(DTEjercicio datos)= 0;
        virtual void agregarDatosRellenarPalabras(DTRellenarPalabras ejRellPal) = 0;
        virtual void agregarDatosTraduccion(DTTraduccion tradu) = 0;

        //Operaciones virtuales para modificar el set de cursos
        virtual void altaEjercicio()= 0;
        virtual bool altaCurso() = 0;
        virtual void altaLeccion(string curso) = 0;
        virtual void eliminarCurso(string nombreCurso)= 0;
        virtual void habilitarCurso(string nombreCurso)= 0;

        //Operaciones virtuales para modificar el set de idiomas
        virtual bool confirmarAltaIdioma(string idioma)= 0;

        //Operaciones virtuales para modificar el set de ejercicios
        virtual void agregarEjercicio(DTEjercicio datos)= 0;

        //Operaciones virtuales para obtener información
        virtual set<string> listarProfe()= 0;
        virtual DTEstadisticaCurso estadisticasCurso(string curso)= 0;
        virtual set<string> listarNombresDeCursos()= 0;
        virtual set<DTCurso> listarDTCursos()= 0;
        virtual set<string> listarIdiomasProfesor()= 0;
        virtual void listarIdiomas()= 0;
        virtual void listarCursosNoHabilitados() = 0;
        virtual bool solucionCorrectaCompletarPalabras(set<string> solucion, string estudiante, int IdEjercicio)= 0;
        virtual bool solucionCorrectaTraduccion(string solucion, string estudiante, int IdEjercicio)= 0;
        virtual void seleccionarEjercicio(int idEjercicio)= 0;
        virtual set<DTEjercicio> seleccionarEjerciciosDeCurso(string curso)= 0;

        //Operaciones virtuales de suscripciones
        virtual set<string> consultarSuscripciones(string nick)= 0;
        virtual void suscribirUsuario(set<string> idiomas)= 0;
        virtual set<string> listarIdiomasSuscrito(string nick)= 0;
        virtual void eliminarSuscripciones(set<string> idiomas, string nick)= 0;

        //Otras operaciones virtuales
        virtual void limpiarDatos()= 0;

        //Operaciones que creo que están mal
        virtual set<DTLeccion> ListarLecciones(string cursoLec)=0;

        virtual set<string> cursosInscriptoSinAprobar(string nick)= 0;
};


#endif