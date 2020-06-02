#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using std::ostringstream;

class Polybios
{
    public:
        Polybios(string);
        string Alfabetizado(string);
        string cifrado(string);
        string descifrado(string);
        int modulo(int, int);

    private:
        string Alf;
        ostringstream new_m;
        int unsigned i,tamanhio=25,posicion;
        string::iterator j;
};
Polybios::Polybios(string abc)
{
    Alf=Alfabetizado(abc);
}
int Polybios::modulo(int a, int n)
{
    int q=a/n;
    int r=a-(q*n);
    if(r<0)
    {
        q++;
        r=a-(q*n);
    }
    return r;
}
string Polybios::Alfabetizado(string abc)
{
    Alf.resize(tamanhio);
    for(i=0,j=abc.begin(); i<tamanhio; j++)
    {
        posicion=Alf.find(*j);
        if((*j)=='j')
        {
            posicion = Alf.find('i');
        }
        if(posicion==string::npos)
        {
            Alf.at(i)=*j;
            i++;
        }
    }
    return Alf;
}
string Polybios::cifrado(string m)
{
    for(j=m.begin(); j!=m.end(); j++)
    {
        if((*j)==' ')
        {
            j++;
            new_m<<" ";
        }
        posicion=Alf.find(*j);
        if((*j)=='j')
        {
            posicion=Alf.find('i');
        }
        i=posicion/5;
        new_m<<(char)('A'+i);
        i=modulo(posicion,5);
        new_m<<(char)('A'+i);
    }
    return new_m.str();
}
string Polybios::descifrado(string m)
{
    for(j=m.begin(); j!=m.end(); j++)
    {
        if((*j)==' ')
        {
            j++;
            new_m<<" ";
        }
        i=((*j)-'A')*5;
        j++;
        i+=((*j)-'A');
        new_m<<Alf.at(i);
    }
    return new_m.str();
}