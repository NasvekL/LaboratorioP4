using namespace std;
#include <string>
class RellenarPalabras:public Ejercicio{
    private:
        list<string> ListadePalabras;
    public:
        list<string> getlista();
        bool esCorrecto(list<string>);
        void aumentarProgreso(string estudiante);
        RellenarPalabras(solucion list<string>,letra string,idEjercicio int, Descripcion string);
};