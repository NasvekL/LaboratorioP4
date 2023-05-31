
    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS
class Inscripcion;

class Estudiante: public Usuario{
    private:   
        string Pais;
        Fecha Nacimiento;
        //Pseudoatributos
        set<Inscripcion*> inscripciones_;
    public:
        //Getters y Setters
        string getPais();
        Fecha getNacimineto();
        //Create destroy
        ~Estudiante();
        Estudiante(string nickname, string contrasenia, string nombre, string descripcion, string pais, Fecha nacimiento);
        //Otras operaciones
        Set(DTNotificación) verNotificaciones();
        DTEstudiante getDTEstudiante();
        Set(string) getCursosInscriptosSA();
        Set(DTCurso) obtenDTCurso();
        Set(int) obtenerProgreso();
        Set<Inscripcion*>& Inscripciones();  //PseudoAtributo
        //Faltan los casos de uso que me permiten agregar y eliminar inscripciones
};