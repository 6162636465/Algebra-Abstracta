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
  string x;//clave
  string m;//mensaje
  string u;
public:
  cifrado(string,string,string);
  void cifrar();
  int nuevoAlfabeto(string);
  string Alfabeto();
  void decifrar();
};
cifrado::cifrado(string _x,string _m,string _u)
{
  x=_x;//clave
  m=_m;//mensaje
  u=_u;
}
string cifrado::Alfabeto()
{
  string aiuda;
  for(int i=0;i<x.length();i++)
  {
    int pop=0;
    for(int j=0;j<aiuda.length();j++)
    {
      if(x[i]==aiuda[j])
      {
        pop=pop+1;
      }
    }
    if(pop==0)
    {
      if(x[i]!=' ')
      {
        aiuda=aiuda+x[i];
      }
    }
  }
  return aiuda;
}

int cifrado::nuevoAlfabeto(string A)
{
  for(int i=0;i<u.length();i++)
  {
    for(int j=0;j<x.length();j++)
    {
      if()
    }
  }
}
void cifrado::cifrar()
{
  string alfabeto2=Alfabeto();//quitarle las letras repetidas
  string alfabeto3=nuevoAlfabeto(alfabeto2);
}