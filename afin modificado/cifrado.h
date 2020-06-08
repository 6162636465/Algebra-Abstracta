//javier Alvarez Reyes
#include <cstdlib>
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
#include <random>
#include <stdlib.h>
#include <time.h>
using std::string;
using namespace std;


class cifrado
{
private:
  string m;//mensaje
  string alfabeto;
public:
  cifrado(string,string);
  void cifrar();
  int random();
  int generarclabe(int);
  int euclides(int,int);
  int modulo(int,int);
  int buscar(int,int,int);
  void decifrar(string);
};
cifrado::cifrado(string _m,string _alfabeto)
{
  m=_m;//mensaje
  alfabeto=_alfabeto;
}
int cifrado::modulo(int a, int b){
    if(a>=0)
        return a-(a/b)*b;
    else
        return a-((a/b)-1)*b;
}
int cifrado::buscar(int x,int a,int b)
{
  cout<<x<<" "<<a<<" "<<b<<endl;
  int aea=alfabeto.length();
  int c=(x*a+b);
  cout<<"numero : "<<c<<endl;
  int j=modulo(c,aea);
  cout<<"modulo"<<j<<endl;
  return j;
}
int cifrado::euclides(int a, int b)
{
  int r;
  int contador=0;
  while(true){
    r=modulo(a,b);
    if(r==0)
      return b;
    if(r>(b/2)){
      r=b-r;
    }
    a=b;
    b=r;
    contador+=1;
    a=1;
    return a;//mcd
  }
}
int cifrado::random()
{
  random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> random(0,alfabeto.size());
	return random(rng);
}
int cifrado::generarclabe(int tamaño){
	int a = random();
	int b = euclides(a, tamaño);
	if (b == 1){
		return a;
	}
	else
		return generarclabe(tamaño);
}
void cifrado::cifrar()
{
  string salida;
  int num = alfabeto.size();
  int a=generarclabe(num);//clave A
  int b=random();//clave b
  cout<<"clave A :"<<a<<endl;
  cout<<"clave B :"<<b<<endl;
  for(int j=0;j<m.length();j++)
  {
    string temporal;
    for(int i=0;i<alfabeto.length();i++)
    {
      if(m[j]==alfabeto[i])
      {
        temporal=alfabeto[buscar(i,a,b)];
        salida=salida+temporal;
      }
    }
  }
  cout<<"cifrado : "<<salida<<endl;
}
void cifrado::decifrar(string texto)
{
  int claveAd,claveBd;
  cout<<"coloque el primer numero"<<endl;
  cin>>claveAd;
  cout<<"coloque el segundo numero"<<endl;
  cin>>claveBd;
  string descifrado;
  int temp, pos;
	for (int i = 0; i<texto.size(); i++){
		temp = alfabeto.find(texto[i]);
    pos=modulo(claveAd*(temp-claveBd), alfabeto.size());
		descifrado.push_back(alfabeto[pos]);
	}
	 cout<<descifrado<<endl;
}