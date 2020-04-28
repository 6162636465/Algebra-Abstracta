//javier Alvarez Reyes
#include <iostream>
#include<string>
#include <sstream>
using std::string;
using namespace std;
class Laboratorio
{
  public:
  Laboratorio();
  void A();
  void B();
  void C();
  void D();
  void F();
  void G();
  void H();
  void I();
  void J();
  void K();
  void L();
};
Laboratorio::Laboratorio()
{

}
void Laboratorio::A()
{
  cout<<"convertir un char a un objeto tipo string"<<endl;
  string cadena;
  char x[12]="algebra";
  for(int i=0; x[i]!=x[-1];i++)
  {
    cadena=cadena+x[i];
  }
  cout<<cadena<<endl;
  cout<<"convertir un string a char"<<endl;
  string objeto("samsung");
  char y[15];
  for(int n=0;n<objeto.length();n++)
    {
      y[n]+=objeto[n];
    }
  cout<<y<<endl;
}
void Laboratorio::B()
{
  cout<<"en que la funcion capacity te devuelve el numero total de caracteres que puedes almacenar mientras que size te devuelve el numero de caracteres que tienes"<<endl;
}
void Laboratorio::C()
{
  string minusculas( "abcdefghijklmnopqrstuvwxyz" );
  string mayusculas( "ABCDEFGHIJKLMNOPQRSTUVWXYZ" );
  string palabra("MiGuel AlonSo TaPIa JimeneS");
  cout<<"antes:"<<palabra<<endl;
  for(int i=0;i<palabra.length();i++)
  {
    for(int j=0;j<minusculas.length();j++)
    {
      if(palabra[i]==mayusculas[j])
      {
        palabra[i]=minusculas[j];
      }
      else if(palabra[i]==minusculas[j])
      {
        palabra[i]=mayusculas[j];
      }
    }
  }
  cout<<"despues:"<<palabra<<endl;
}
void Laboratorio::D()
{
  int x,y,z;
   cout<<"coloque un numero"<<endl;
   cin>>x;
   cout<<"coloque otro numero"<<endl;
   cin>>y;
   string conector;
   string A="";
   string B="";
   A =to_string(x);
   B =to_string(y);
   conector=A+B;
   cout<<conector<<endl;
    stringstream geek(conector); 
    geek >> z; 
    cout <<z*2<<endl; 
}
void Laboratorio::F()
{
string b,a="a"; for(int i=0;i<1000;i++,b+=a="a"){}cout<<b.length()<<endl;
}
void Laboratorio::G()
{
 string x("aprobe");
  string texto("Yo desaprobe el curso de Algebra Abstracta");
  istringstream iss(texto);
  string token;
  string cadena;
  string espacio(" ");
  cout<<texto<<endl;
  while (getline(iss, token,' '))
    {
      if(token=="desaprobe")
      {
        token="aprobe";
      }
      cadena=cadena+espacio+token;
    }
  cout<<cadena<<endl;
}
void Laboratorio::H()
{
  string A("como poco coco como poco coco compro coco");
  string B("coco");
  istringstream iss(A);
  string token;
  int i=0;
  while (getline(iss, token,' '))
    {
      if(token==B)
      {
        i=i+1;
      }
    }
  cout<<"la palabra "<<B<<" se repite:"<<i<<endl;
}
void Laboratorio::I()
{
  string letra;
  cout<<"coloque un texto para el objeto string"<<endl;
  getline(cin,letra);
  for(int i=0;i<letra.length();i++)
  {
    cout<<letra[i]<<endl;
  }
}
void Laboratorio::J()
{
  string A;
  string B;
  cout<<"coloque un texto para el objeto string"<<endl;
  getline(cin,A);
  cout<<"coloque un texto para el medio del objeto string"<<endl;
  getline(cin,B);
  int c=A.length()/2;
  A.insert(c,B);
  cout<<A<<endl;
}
void Laboratorio::K()
{
  string A;
  string B;
  string C;
  cout<<"coloque un texto para el objeto string "<<endl;
  getline(cin,A);
  cout<<"coloque una palabra del texto anterior"<<endl;
  getline(cin,B);
  cout<<"coloque una palabra para remplazarla"<<endl;
  getline(cin,C);
  istringstream iss(A);
  string token;
  string cadena;
  string espacio(" ");
  int i=0;
  while (getline(iss, token,' '))
    {
      if(token==B)
      {
        token=C;
      }
      cadena=cadena+espacio+token;
    }
  cout<<A<<endl;
  cout<<cadena<<endl;
}
void Laboratorio::L()
{
  string A("blodborne");
  string B("darksoul");
  string abecedario( "abcdefghijklmnñopqrstuvwxyz" );
  int j=0,k=0;
  for(int e=0;e<A.length();e++)
    {
      for(int x=0;x<abecedario.length();x++)
        {
          if(A[e]==abecedario[x])
          {
            j=j+x;
          }
          else if(B[e]==abecedario[x])
          {
            k=k+x;
          }
        }
      if(j<k)
        {
          cout<<B<<endl;
          break;
        }
      else if(k<j)
      {
        cout<<A<<endl;
        break;
      }
    }
}
int main() 
{
int q=0;
  Laboratorio p1=Laboratorio();
  cout<<"seleccione un ejercicio del WORD del 1 al 13"<<endl;
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
    p1.F();
  }
  else if(q==6)
  {
    p1.G();
  }
  else if(q==7)
  {
    p1.H();
  }
  else if(q==8)
  {
    p1.I();
  }
  else if(q==9)
  {
    p1.J();
  }
  else if(q==10)
  {
    p1.K();
  }
  else if(q==11)
  {
    p1.L();
  }
}