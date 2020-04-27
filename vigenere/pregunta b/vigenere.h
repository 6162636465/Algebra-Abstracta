//javier Alvarez Reyes
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
using std::string;
using namespace std;
class cifrado
{
private:
  int x;//alfabeto
  string m;//clave
  string n;//mensaje
  string sifrado;
public:
  cifrado(int,string,string,string);
  void cifrar();
  void decifrar();
};
cifrado::cifrado(int _x,string _m,string _n,string _sifrado)
{
  n=_n;//mensaje
  x=_x;//alfabeto
  m=_m;//clave
  sifrado=_sifrado;
}
void cifrado::cifrar()
{
  string alfabeto;
  string espacio(" ");
  ifstream archivo;
  fstream Texto("respuesta.txt");
  int j=0,u=0,F=0,c=0,q=0;
  if(x==1)
  {
    archivo.open("alfabetoACII.txt",ios::in);
    while(!archivo.eof())
      {
        getline(archivo,alfabeto);
      }
    archivo.close();
  }
  else if(x==2)
  {
    archivo.open("alfabetoMIS.txt",ios::in);
    while(!archivo.eof())
      {
        getline(archivo,alfabeto);
      }
    archivo.close();
  }
  else if(x==3)
  {
    archivo.open("alfabetoWord.txt",ios::in);
    while(!archivo.eof())
      {
        getline(archivo,alfabeto);
      }
    archivo.close();
  }
  int b=0;
  while(m.length()<n.length())//completar la clave
  {
    m=m+m[j];
    j+=1;
  }
  cout<<m<<endl;
  for(int i=0;i<m.length();i++)
  {
    for(int k=0;k<alfabeto.length();k++)
    {
      if(m[i]==alfabeto[k] && n[i]==alfabeto[k])
      {
        F=k;
        u=k;
      }
      else if(m[i]==alfabeto[k] && n[i]!=alfabeto[k])
      {
        F=k;
      }
      else if(n[i]==alfabeto[k] && m[i]!=alfabeto[k])
      {
        u=k;
      }
    }
    c=F+u;
    if(alfabeto.length()<=c)
    {
      c=c-alfabeto.length();
    }
    cout<<alfabeto[c]<<endl;
    sifrado=sifrado+alfabeto[c];
  }
  cout<<sifrado<<endl;
  Texto<<"cifrado :"<<sifrado<<endl;
  Texto.close();
}
void cifrado::decifrar()
{
  string alfabeto;
  string espacio(" ");
  ifstream archivo;
  fstream Texto("respuesta.txt");
  int j=0,u=0,F=0,c=0,q=0;
  if(x==1)
  {
    archivo.open("alfabetoACII.txt",ios::in);
    while(!archivo.eof())
      {
        getline(archivo,alfabeto);
      }
    archivo.close();
  }
  else if(x==2)
  {
    archivo.open("alfabetoWord.txt",ios::in);
    while(!archivo.eof())
      {
        getline(archivo,alfabeto);
      }
    archivo.close();
  }
  else if(x==3)
  {
    archivo.open("alfabetoMIS.txt",ios::in);
    while(!archivo.eof())
      {
        getline(archivo,alfabeto);
      }
    archivo.close();
  }
  int b=0;
  while(m.length()<n.length())//completar la clave
  {
    m=m+m[j];
    j+=1;
  }
  for(int i=0;i<m.length();i++)
  {
    for(int k=0;k<alfabeto.length();k++)
    {
      if(m[i]==alfabeto[k] && n[i]==alfabeto[k])
      {
        F=k;
        u=k;
      }
      else if(m[i]==alfabeto[k] && n[i]!=alfabeto[k])
      {
        F=k;
      }
      else if(n[i]==alfabeto[k] && m[i]!=alfabeto[k])
      {
        u=k;
      }
    }
    c=u-F;
    if(c<0)
    {
      c=c+alfabeto.length();
    }
    sifrado=sifrado+alfabeto[c];
  }
  cout<<sifrado<<endl;
  Texto<<"cifrado :"<<sifrado<<endl;
  Texto.close();
}