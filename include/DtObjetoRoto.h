#ifndef DTOBJETOROTO
#define DTOBJETOROTO
#include<string>
using namespace std;
class DtObjetoRoto{
    private:
        string nombreObjeto;  
        bool prestado;
        string NombreNinio;
    public:
        string getNombreObjeto(); 
        string getNombreNinio();
        bool esPrestado();
        DtObjetoRoto(string,bool,string);
        ~DtObjetoRoto();
        friend ostream& operator<<(ostream& os, const DtObjetoRoto& dt);
};
#endif