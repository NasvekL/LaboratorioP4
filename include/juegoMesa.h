
#include <string>
using namespace std;

class JuegoMesa{
    private:
        int EdadRecomendada;
        int CantJugadores;
    public:
        JuegoMesa(int, int);    //Constructor -> EdadRecomendada, CantJugadores
        ~JuegoMesa();           //Destructor
        toString();
}                   



JuegoMesa::JuegoMesa(int Edad, int Cant);

JuegoMesa::~JuegoMesa();

