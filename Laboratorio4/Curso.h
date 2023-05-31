

class Idioma;
class Inscripcion;
class Leccion;
class Profesor;

class Curso{
    private:
        string Nombre;
        string Descripcion;
        Nivel_de_dificultad Nivel;
        bool Habilitado;
        Set(DTCurso) Previas; 
        //Pseudoatributos
        Idioma* se_dicta_en_;
        Profesor* lo_dicta_;
        set<Leccion*> lecciones_;
        set<Inscripcion*> inscripciones_;
    public:
        //Getters
        string getNombreCurso();
        string getDescripcion();
        Nivel_de_dificultad getNivelDeDificultad();
        bool getHabilitado();
        //Create y destroy
        ~Curso();
        Curso(string nombre, string descripcion, Nivel_de_dificultad nivel, bool habilitado, Set(DTCurso) previas);
        //Otras operaciones
        Ejercicio seleccionar(int idEjercicio);
        int getPromedio(Profesor p);
        int getProgreso(Estudiante e);
        DTestadisticaCurso mostrarEstadisticas();
        //Obtener Pseudoatributos
        Idioma* idiomas();
        Profesor* profesores();
        Set<Leccion*>& lecciones(); 
        Set<Inscripcion*>& inscripciones();
        //Faltan los casos de uso que nos den las operaciones de agregar idiomas y cursos
};