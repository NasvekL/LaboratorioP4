
    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS

class Curso;
class Idioma;

class Profesor: public Usuario{
    private:
        string Instituto;
        //Pseudoatributos
        set<Idioma*> idiomas_;  
        set<Curso*> cursos_;
    public:
        //Getters
        string getInstituto();
        //Create y destroy
        ~Profesor();
        Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto);
        //Otras operaciones
        Set(DTNotificacion) verNotificaciones()
        DTProfesor getDTProfesor()
        Set(DTCurso) obtenerDTCurso()
        int obtenerPromedio()
        //Obtener Pseudoatributos
        Set<Idioma*>& Idiomas();
        Set<Curso*>& Cursos();
        //Faltan los casos de uso que nos den las operaciones de agregar idiomas y cursos
};