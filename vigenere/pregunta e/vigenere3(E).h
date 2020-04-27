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
void cifrado::decifrar()
{
  cout<<n<<endl;
  cout<<m<<endl;
  string alfabeto;
  string espacio(" ");
  ifstream archivo;
  int j=0,u=0,F=0,c=0,q=0;
  archivo.open("alfabetoMiss.txt",ios::in);
  while(!archivo.eof())
    {
      getline(archivo,alfabeto);
    }
    archivo.close();
  int b=0;
  while(m.length()<n.length())
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
  //quitar w
  /*/quitar los aqui
  string insertar("AQUI");
  int contar=0,minimo=9;
  while(contar!=n.length())
  {
    if(minimo<contar)
    {

    }
    contar+=1;
  }*/
  cout<<sifrado<<endl;
}
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
  int j=0,u=0,F=0,c=0,q=0;
  archivo.open("alfabetoMiss.txt",ios::in);
  while(!archivo.eof())
    {
      getline(archivo,alfabeto);
    }
  archivo.close();
  //llenar los AQUI
  string insertar("AQUI");
  int contar=0,minimo=9;
  while(contar!=n.length())
  {
    if(minimo<contar)
    {
      n.insert(contar,insertar);
      minimo+=14;//se pone 14 por los caracteres aquique suman a los 10 de la pregunta
    }
    contar+=1;
  }
  //llenar w si ase falta
  while(n.length()%4!=0)
  {
    n=n+"w";
  }
  cout<<"mensaje:"<<n<<"caracteres:"<<n.length()<<endl;
  //completar la clave
  int b=0;
  string reservado=m;
  while(m.length()<n.length())
  {
    m=m+m[j];
    j+=1;
  }
  cout<<m<<"caracteres:"<<m.length()<<endl;
  //cifrado
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
    sifrado=sifrado+alfabeto[c];
  }
  cout<<sifrado<<endl;
  int responder=0;
  cout<<"ponga 1 si desea decifrar su mensaje u otro numero si desea finalizar"<<endl;
  cin >> responder;
  string temporalmente;
  //manda los valores a la funcion decifrar
  if(responder==1)
  {
    m=reservado;
    n=sifrado;
    sifrado=temporalmente;
    decifrar();
  }
  else 
  {
    cout<<"ok"<<endl;
  }
}