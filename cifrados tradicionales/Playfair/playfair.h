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
  string nuevoAlfabeto(string);
  string Alfabeto();
  void decifrar();
  string separar(string,int,int);
  string allar(int,int,string,string,string,string,string);
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

string cifrado::nuevoAlfabeto(string A){
  string aiuda=A;
  for(int i=0;i<u.length();i++)
  {
    int pop=0;
    for(int j=0;j<aiuda.length();j++)
    {
      if(u[i]==aiuda[j])
      {
        pop=pop+1;
      }
    }
    if(pop==0)
    {
      if(u[i]!=' ')
      {
        aiuda=aiuda+u[i];
      }
    }
  }
  return aiuda;
}
string cifrado::separar(string rito,int x, int y){
  string relleno;
  for(x; x<y; x++){
    relleno+=rito[x];
    }
  return relleno;
} 
string cifrado::allar(int x, int y,string A,string B,string C,string D,string E)
{
  if( (x>=0 && x<5) || (y<5 && y>=0))
  {

  }
  if( (x>=5 && x<10) || (y<10 && y>=0))
  {
    
  }
  if( (x>=10 && x<15) || (y<15 && y>=0))
  {
    
  }
  if( (x>=15 && x<20) || (y<20 && y>==0))
  {
    
  }
  if( (x>=20 && x<25) || (y<25 && y>===0))
  {
    
  }
}
void cifrado::cifrar()
{
  string alfabeto2=Alfabeto();//quitarle las letras repetidas
  string alfabeto3=nuevoAlfabeto(alfabeto2);
  cout<<alfabeto3<<endl<<"tamaño ="<<alfabeto3.length()<<endl;
  string itachi=separar(alfabeto3,0,5);cout<<itachi<<endl;
  string obito=separar(alfabeto3,5,10);cout<<obito<<endl;
  string picoro=separar(alfabeto3,10,15);cout<<picoro<<endl;
  string goku=separar(alfabeto3,15,20);cout<<goku<<endl;
  string pikachu=separar(alfabeto3,20,25);cout<<pikachu<<endl;
  int terminato=0, gaaaaaaaaa=0;//contador xdxd
  int temp,temp1;
  int yara;
  for(int i=0;i<m.length();i=i+2)
  {
    for(int j=0;j<alfabeto3.length();j++)
    {
      if(m[i]==alfabeto3[j])
      {
      temp=alfabeto3.find(m[i]);
      }
      if(m[i+1]==alfabeto3[j]){
      temp1=alfabeto3.find(m[i+1]);
      }
    }
    allar(temp,temp1,itachi,obito,picoro,goku,pikachu);
  }
}
