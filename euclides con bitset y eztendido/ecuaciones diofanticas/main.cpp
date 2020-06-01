#include <iostream>
#include <string>
using namespace std;
int x,d,y;
void Divicibilidad(int x,int y)
{
  cout<<"Propiedad 1: if a|1, entonces a = ±1."<<endl;
  cout<<"Propiedad 2: if a|b y b|a, entonces a = ±b."<<endl;
  cout<<"Propiedad 3: if a|b y b|c, entonces a|c"<<endl;
  cout<<"Propiedad 4: if a|b ya|c, entonces a|(m × b + n × c), donde m"<<endl;
  cout<<"y n son enteros arbitrarios."<<endl;
  cout <<   "la formula de la divicibilidad es "<<endl; 
  cout <<   "   a=b*n "<<endl;
  int n;
  if(x<y)
  {
    if(y%x!=0)
    {
      int c=y%x;
      n=y/x;
      cout <<x<<"="<<y<<"*"<<n<<"+"<<c<<endl;
      cout<<"no divide exactamente"<<endl;
    }
    else if(y%x==0)
    {
      n=x/y;
      cout <<x<<"="<<y<<"*"<<n<<endl;
    }
  }
  else if(y<x)
  {
    if(x%y!=0)
    {
      int c=x%y;
      n=x/y;
      cout <<x<<"="<<y<<"*"<<n<<"+"<<c<<endl;
      cout<<"no divide exactamente"<<endl;
    }
    else if(x%y==0)
    {
      n=x/y;
      cout <<x<<"="<<y<<"*"<<n<<endl;
    }
  }
}
void ExtendidoEuclides(int a,int b)
{ 
  int x2=1,x1=0,y2=0,y1=1,q,r;
  if (b==0){
    d=a;
    x=1;
    y=0;
  }
  while (b>0){
    q=a/b;
    r=a-q*b;
    x=x2-q*x1;
    y=y2-y1*q;
    a=b;
    b=r;
    x2=x1;
    x1=x;
    y2=y1;
    y1=y;
     }
  d=a;
  x=x2;
  y=y2;
  cout<<"final"<<endl;
  cout<<"(mcd) d:"<<d<<" x: "<<x<<" y: "<<y<<endl;
}
void Diofanticas(int a,int b,int c)
{
  float xa=a,ya=b,e,x0,y0;
  float kx,ky;
  ExtendidoEuclides(a,b);
  e=c/d;
  cout<<"e = "<<e<<endl;
  cout<<"x0="<<"x*e"<<endl;
  cout<<"x0="<<x*e<<endl;
  cout<<"y0="<<"y*e"<<endl;
  cout<<"y0="<<y*e<<endl;
  cout<<"para allar el valor de k :"<<endl;
  cout<<"para x"<<endl;
  kx=(x*e)/(b/d);
  cout<<"x="<<(x*e)<<"+k*"<<(b/d)<<endl;
  cout<<"para y"<<endl;
  cout<<"y="<<(y*e)<<"-k*"<<(a/d)<<endl;
  ky=(y*e)/(a/d);
  if(ky<0)
  {
    ky=ky*-1;
  }
  int ux=kx,uy=ky;
  cout<<"k:"<<endl;
  if(ux<=uy)
  {
    cout<<kx<<"<k<"<<ky<<endl;
    int remplas=kx,remplasado=ky;
    while(remplas<remplasado)
    {
      cout<<"para :"<<remplas<<endl;
      int equis=(x*e)+-1*(remplas*(b/d)) ,ye=(y*e)+-1*(-remplas*(a/d));
      cout<<"x = "<<equis<<endl;
      cout<<"y = "<<ye<<endl;
      remplas++;
    }
    
  }
  else if(uy<=ux)
  {
    cout<<ky<<"<=k<="<<kx<<endl;
    int remplas=ky,remplasado=kx;
    while(remplas<remplasado)
    {
      cout<<"para :"<<remplas<<endl;
      int equis=(x*e)+-1*(remplas*(b/d)) ,ye=(y*e)+-1*(-remplas*(a/d));
      cout<<"x = "<<equis<<endl;
      cout<<"y = "<<ye<<endl;
      remplas++;
    }
  }
}

int main()
{
  //Divicibilidad(2490,1);
  //ExtendidoEuclides(33,29);
  Diofanticas(6,10,104);//y,x,respuesta
}
