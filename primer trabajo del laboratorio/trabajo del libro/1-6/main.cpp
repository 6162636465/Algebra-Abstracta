//javier Alvarez Reyes
#include <iostream>
#include<string>
#include <sstream>
#include <cstdlib>
using std::string;
using namespace std;
#include <iomanip>
using std::setw;
class tarea
{
  public:
  tarea();
  void A();
  void B();
  void C();
  void D();
  void E();
  void F();
  void G();
};
tarea::tarea()
{
}
void tarea::A()
{
  int j=0,k=0;
  string abecedario( "abcdefghijklmnñopqrstuvwxyzabcdefghijklmnñopqrstuvwxyz" );
  string palabra("juan");
  string palabrae("nypw");
  cout<<"a.-"<<endl;
  cout<<"la palabra  es :"<<palabra<<endl;
  cout<<"la palabra  es :"<<palabrae<<endl;
  for(int e=0;e<abecedario.length();e++)
  {
   if(palabra[j]==abecedario[e])
    {
      palabra[j]=abecedario[e+13];
      j=j+1;
      e=0; 
    }
  }
  cout<<"la encriptacion es :"<<palabra<<endl;
  for(int n=0;n<abecedario.length();n++)
  {
   if(palabrae[k]==abecedario[n])
    {
      palabrae[k]=abecedario[n-13];
      k=k+1;
      n=0; 
    }
  }
  cout<<"la encriptacion es :"<<palabrae<<endl;
  cout<<"respuesta c:considero que seria un poco complicado pero con la ayuda de las computadoras detectaria con los patrones del encriptado "<<endl;
}
void tarea::B()
{
  string nombre("miguel");
  string apellido(" vizcarra");
  string juntar;

  juntar=(nombre+apellido);
  cout<<"nombre:"<<nombre<<endl;
  cout<<"apellido:"<<apellido<<endl;
  cout<<juntar<<" :palabra concatenada"<<endl;
}
void tarea::C()
{
  int p=rand()&4;
  string palabra;
  if(p==1)
  {
    palabra="automata";
  }
  else if(p==2)
  { 
    palabra="federico";   
  }
  else if(p==2)
  { 
    palabra="yacerian";   
  }
  else if(p==3)
  { 
    palabra="xenofoba";   
  }
  else if(p==4)
  { 
    palabra="yacieron";   
  }
  string cifrado("********");
  string respaldo("********");
  string respaldoB("********");
  string letra;
  int intentos=0,vidas=8,i=0,z;
  while(i<1)
  {
    cout<<"intentos:"<<intentos<<"  vidas:"<<vidas<<endl;
    cout<<"ponga una letra:"<<endl;
    getline(cin,letra);
    //buscar letra
    for(int x=0;x<palabra.length();x++)
    {
      if(letra[0]==palabra[x])
      {
        cifrado[x]=palabra[x];
      }
    }
    cout<<cifrado<<endl;
    if(respaldo==cifrado)
    {
      vidas=vidas-1;
      intentos+=1;
      if(vidas==7)
      {
        cout<<" "<<0<<" "<<endl;
      }
      if(vidas==6)
      {
         cout<<" "<<0<<" "<<endl;
        cout<<"/"<<" "<<" "<<endl;
      }
      else if(vidas==5)
      {
        cout<<" "<<0<<" "<<endl;
        cout<<"/"<<"!"<<" "<<endl;
      }
      else if(vidas==4)
      {
        cout<<" "<<0<<" "<<endl;
        cout<<"/"<<"!"<<"/"<<endl;
      }
      else if(vidas==3)
      {
       cout<<" "<<0<<" "<<endl;
      cout<<"/"<<"!"<<"/"<<endl;
      cout<<" "<<"I"<<" "<<endl;  
      }
      else if(vidas==2)
      {
        cout<<" "<<0<<" "<<endl;
      cout<<"/"<<"!"<<"/"<<endl;
      cout<<" "<<"I"<<" "<<endl; 
      cout<<" "<<"/ "<<" "<<endl;
      }
      else if(vidas==1)
      {
        cout<<" "<<0<<" "<<endl;
      cout<<"/"<<"!"<<"/"<<endl;
      cout<<" "<<"I"<<" "<<endl;
      cout<<" "<<"//"<<" "<<endl; 
      }
      else if(vidas==0)
      {
        cout<<"game over"<<endl;
        break;
      }
    }
    else if(respaldo!=cifrado)
    {
      intentos+=1;
      if(cifrado==palabra)
      {
        cout<<"felicidades!!! adivino mi palabra. desea jugar otra ves/si(1),no(2)/"<<endl;
        cin>>z;
        if (z==1)
        {
          vidas=7;
          intentos=0;
          cifrado=respaldo=respaldoB;
        }
        else if(z==2)
        {
          break;
        }
      }
      respaldo=cifrado;
    }
  }
}
void tarea::D()
{
  string nombre("sebastian");
  string insertar("******");
  int c=nombre.length()/2;
  nombre.insert(c,insertar);
  cout<<nombre<<endl;

}
void tarea::E()
{
  string texto("quedate.en.casa.por.la.cuarentena");
  istringstream iss(texto);
  string token;
  string cadena;
  string espacio(" ");
  cout<<texto<<endl;
  while (getline(iss, token,'.'))
    {
      cadena=cadena+espacio+token;
    }
    cout<<cadena<<endl;
}
void tarea::F()
{
  string dota("sony santamonica");
  string rec("aaaaaaaaaaaaaaaa");
  int f=dota.length();
  for(int e=0;e<dota.length();e++)
  {
    rec[e]=dota[f-1-e];
  }
  cout<<rec<<endl;
}
int main() {
  int q=0;
  tarea p1=tarea();
  cout<<"seleccione un ejercicio del libro del 1 al 7"<<endl;
  cin>>q;
  if(q==1)
  {
    p1.A();
  }
  else if(q==2)
  {
    p1.B();
  }
  else if(q==3)
  {
    p1.C();
  }
  else if(q==4)
  {
    p1.D();
  }
  else if(q==5)
  {
    p1.E();
  }
  else if(q==6)
  {
    p1.F();
  }
}
