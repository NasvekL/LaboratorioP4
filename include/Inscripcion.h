
    //CAMBIAR TODOS LOS SET POR EL SET QUE USEMOS

class Inscripcion{
    private:
        Fecha Fecha;
        bool Aprobado;
        int LeccionActual;
        //Pseudoatributos
        Progreso* prog;
        Curso* inscripto_a;
    public:
        //Getters
        Fecha getFecha();
        bool getAprobado();
        int getLeccionActual();
        //Create y destroy
        ~Inscripcion();
        




}