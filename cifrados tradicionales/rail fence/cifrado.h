//javier Alvarez Reyes
#include <cstdlib>
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
using std::string;
using namespace std;
class cifrado
{
private:
  int x;//clave
  string m;//mensaje
public:
  cifrado(int,string);
  void cifrar();
  void decifrar();
};
cifrado::cifrado(int _x,string _m)
{
  x=_x;//clave
  m=_m;//mensaje
}

void cifrado::cifrar()
{
  int c=m.length();//cantidad de caracteres
  bool anuma=true;
  string mensaji;//mensaje
  string parte;
  string parta;
  //sacar el valor de separacion
  int kaguya=x+(x-3);
 // cout<<kaguya<<endl;
  int contador=0;
  int contador2=x;
  int contador3=0;
  int smash=kaguya+1;
  //algoritmo
 while(anuma==true)
  {
    if(contador>=c)
    {
      contador2=contador2-1;
      contador3=contador3+1;
      contador=contador3;
      mensaji=mensaji+parte;
      cout<<parte<<endl;
      parte=parta;
      kaguya=kaguya-2;
      smash=kaguya+1;
      if (kaguya<1)
      {
        kaguya=x+(x-3);
        smash=kaguya+1;
      }
      if(contador2==0)
      {
        cout<<mensaji<<endl;
        anuma=false;
      }
    }
    else if(contador<c)
    {
      parte=parte+m[contador];
      contador=contador+smash;
      //cout<<kaguya<<endl;
    }
  }
}