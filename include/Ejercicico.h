using namespace std;
#include <string>
class Ejercicio{
    private:
        int idEjercicio;
        string Descripcion;
        string Letra;
        Leccion * leccion;
    public:
        virtual bool esCorrecto(string solucion);
        void aumentarProgreso(string estudiante);
};