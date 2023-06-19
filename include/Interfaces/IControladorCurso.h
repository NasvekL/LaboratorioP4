#ifndef ICONTROLADORCURSO
#define ICONTROLADORCURSO
#include "../Utils.h"
#include "../Interfaces/IObserver.h"
#include "../Clases/Usuario.h"
#include "../Clases/Curso.h"
#include "../DTs/DTCurso.h"
#include "../DTs/DTLeccion.h"
#include "../DTs/DTEjercicio.h"
#include "../DTs/DTEstadisticaCurso.h"
#include "../DTs/DTProfesor.h"
#include "../DTs/DTTraduccion.h"
#include "../DTs/DTRellenarPalabras.h"
#include "../DTs/DTNotificacion.h"


//#include "DTIdioma.h"??



class IControladorCurso{
    private:
        
    public:
        // Métodos públicos virtuales
        //virtual ~IControladorCurso()= 0;
        //virtual IControladorCurso * getInstancia()= 0;

        //Getters virtuales
        virtual string getTipoEjercicio(int id) = 0;
        virtual int getIdEjercicio()=0;
        virtual Idioma* getIdioma(string nombre)= 0;
        virtual DTCurso getDatoDeCurso()= 0;
        virtual list<DTLeccion> getDatosLecciones()=0;
        virtual DTLeccion getDatosDeLeccion()= 0;
        virtual Profesor* getProfesor()= 0;
        virtual Curso* getCursoEnMemoria() = 0;
        virtual Ejercicio* getEjercicioEnMemoria() = 0;
        virtual string getDatoIdioma()= 0;
        virtual map<string, Curso*> getDatosPrevias()= 0;
        virtual Curso* getCurso(string nombreCurso) = 0;
        virtual map<string,Curso*> getCursos()= 0;
        virtual DTRellenarPalabras getDatosRellenar()= 0;
        virtual DTTraduccion getDatosTraduccion()= 0;
        virtual list<DTRellenarPalabras> getDatosMuchasRellenarPalabras() = 0;
        virtual list<DTTraduccion> getDatosMuchasTraducciones() = 0;
        virtual int getNumeroDeLeccion(string cursoSeleccionado)=0;
        virtual string getNickUsuario() = 0;
        //Setters virtuales
        virtual void setDatoDeLeccion(DTLeccion datos)= 0;
        virtual void setDatoDeCurso(DTCurso datos)= 0;
        virtual void setIdEjercicio (int id)=0;
        virtual void setDatosDeLeccion(DTLeccion datos)= 0;
        virtual void setProfesor(Profesor* profesor)= 0;
        virtual void setCursoEnMemoria(Curso* curso) = 0;
        virtual void setEjercicioEnMemoria(Ejercicio* ejercicio) = 0;
        virtual void setDatoIdioma(string idioma)= 0;
        virtual void setDatosPrevias(set<Curso*> previas)= 0;
        virtual void setDatosEjercicioCompletarPalabras(DTRellenarPalabras datos)= 0;
        virtual void setDatosEjercicioTraduccion(DTTraduccion datos)= 0;
        virtual void agregarDatosRellenarPalabras(DTRellenarPalabras ejRellPal) = 0;
        virtual void agregarDatosTraduccion(DTTraduccion tradu) = 0;
        virtual void seleccionIdioma(string idi)=0;
        virtual void setNickUsuario(string nick) = 0;
        //Operaciones virtuales para modificar el set de cursos
        virtual void altaEjercicio(Leccion* lec)= 0;
        virtual bool altaCurso() = 0;
        virtual void altaLeccion(string curso) = 0;
        virtual void eliminarDePrevias(Curso* curso)=0;
        virtual void eliminarCurso(string nombreCurso)= 0;
        virtual bool habilitarCurso(string nombreCurso)= 0;

        //Operaciones virtuales para modificar el set de idiomas
        virtual bool confirmarAltaIdioma(string idioma)= 0;

        //Operaciones virtuales para modificar el set de ejercicios
        virtual void agregarEjercicio(DTEjercicio datos)= 0;


        virtual void inscribirEstudianteACurso(string curso, string estudiante, int dia, int mes, int anio)= 0;

        //Operaciones virtuales para obtener información

        //Primero, busca el profesor en la lista de usuarios, y devuelve una copia (o el profesor original, no se). Luego, ese Profesor se
        //le pasa a setProfesor(p), que lo que hace es que el puntero profesor de contCurso apunte al objeto p Profesor que se le pasa.
        //No esta claro si dicho objeto es una copia del profesor del contUsuario o si es el profesor original.
        virtual void seleccionarProfesor(string nick) = 0;
        virtual list<string> listarProfe()= 0;
        virtual DTEstadisticaCurso estadisticasCurso(string curso)= 0;
        virtual set<string> listarNombresDeCursos()= 0;
        //Devuelve una lista de triadas de cursos disponibles para un estudiante en particular.
        //Cada uno contiene, en orden, el nombre del curso, la cantidad de lecciones y la cantidad de ejercicios
        virtual list<tuple<string, int, int>> cursosDisponibles(string nick) = 0;
        virtual set<DTCurso> listarDTCursos()= 0;
        virtual set<Idioma*> listarIdiomasProfesor()= 0;
        virtual list<string> listarIdiomas()= 0;
        virtual list<string> listarCursosNoHabilitados() = 0;
        virtual bool solucionCorrectaCompletarPalabras(list<string> solucion, string estudiante, int IdEjercicio)= 0;
        virtual bool solucionCorrectaTraduccion(string solucion, string estudiante, int IdEjercicio)= 0;
        virtual void seleccionarEjercicio(int idEjercicio)= 0;
        virtual list<DTEjercicio> seleccionarEjerciciosDeCurso(string curso)= 0;
        virtual list<string> verCurso(string curso) = 0;
        virtual list<string> listarNicks() = 0;
        virtual void agregarPrevia(string curso, string previa) = 0;

        //Operaciones virtuales de suscripciones
        virtual set<string> consultarSuscripciones(string nick)= 0;
        virtual void suscribirUsuario(set<string> idiomas,string nick)= 0;
        virtual list<string> listarIdiomasSuscrito(string nick)= 0;
        virtual void eliminarSuscripciones(set<string> idi)= 0;


        virtual Ejercicio* getEjercicioPorIdDesdeMapa(int id) = 0;
        //Otras operaciones virtuales
        virtual void limpiarDatos()= 0;

        //Operaciones que creo que están mal

        virtual set<string> cursosInscriptoSinAprobar(string nick)= 0;
};


#endif