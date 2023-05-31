using namespace std;
#include <string>
class Traduccion:public Ejercicio{
    private:
        string solucion;

    public:
    string getSolucion();
    bool esCorrecto(string solucion);
    void aumentarProgreso(string estudiante);
    Traduccion(string solucion,int idEjercicio,string Descripcion,string Letra);
};