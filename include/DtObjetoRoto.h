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
        string getNombre(); 
        string getNombreNinio();
        bool esprestado();
        DtObjetoRoto(string,bool,string);
        ~DtObjetoRoto();
        friend ostream& operator<<(ostream& os, const DtObjetoRoto& dt);
};
#endif