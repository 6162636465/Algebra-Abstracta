#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <NTL/ZZ.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;
using namespace NTL;
using std::string;
ZZ positivo(ZZ a){
  if(a<0)
    a*=-1;
  return a;
}

ZZ modulo(ZZ a, ZZ b){
    if(a>=0)
        return a-(a/b)*b;
    else
        return a-((a/b)-1)*b;
}


//Execution Time: 8e-06
ZZ algoritmo1(ZZ a,ZZ b){
  //cout<<"Ingreso con los numeros "<<a<<" y "<<b<<endl;
  ZZ r;
  int contador=0;
  clock_t t1 = clock();
  clock_t t0=clock();
  while(true){
    r=modulo(a,b);
    //cout<<"r= "<<r<<endl;
    if(r==0)
      return b;
    a=b;
    //cout<<"a= "<<a<<endl;
    b=r;
    //cout<<"b= "<<b<<endl<<endl;
    contador+=1;
  }
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;
}


//Execution Time: 2e-06
ZZ algoritmo2(ZZ a,ZZ b){
  //cout<<"Ingreso con los numeros "<<a<<" y "<<b<<endl;
  ZZ r;
  int contador=0;
  while(true){
    r=modulo(a,b);
    //cout<<"r= "<<r<<endl;
    if(r==0)
      return b;
    if(r>(b/2)){
      //r=b-r;cout<<"r= "<<r<<endl;
    }
    a=b;
    //cout<<"a= "<<a<<endl;
    b=r;
    //cout<<"b= "<<b<<endl<<endl;
    contador+=1;
  }
}



//Execution Time: 3e-06
ZZ algoritmo3(ZZ a, ZZ b){
  if(a<0||b<0){
  }
  if(b==0)
    return a;
  return algoritmo3(b, modulo(a,b));
}



//Execution Time: 4e-06
ZZ algoritmo4(ZZ a,ZZ b){
  ZZ x;
  x=2;
  if(positivo(b) > positivo(a))
    {
    return algoritmo4(b,a);
    }
  if(b==0)
    return a;
  if( (modulo(a,x)==0) && (modulo(b,x)==0) ){
    return 2*algoritmo4(a/x, b/x);}
  if( (modulo(a,x)==0) && (modulo(b,x)!=0) ){
    return algoritmo4(a/x, b);}
  if( (modulo(a,x)!=0) && (modulo(b,x)==0) ){
    return algoritmo4(a, b/x);}
  return algoritmo4( (positivo(a)- positivo(b) )/2,b );
}


//Execution Time: 3e-06
ZZ algoritmo5(ZZ x,ZZ y){
  if(y>x){
    ZZ temp=x;
    x=y;
    y=temp;
    //cout<<"Swap entre x y y"<<endl;
  }
  ZZ g,j;
  g=1;
  j=2;
  while( (modulo(x,j)==0) && (modulo(y,j)==0) ){
    x/=j;
    //cout<<"x= "<<x<<endl;
    y/=j;
    //cout<<"y= "<<y<<endl;
    g=j*g;
   // cout<<"g= "<<g<<endl;
  }
  while(x!=0){
    while(modulo(x,j)==0){
     // cout<<"x es par"<<endl;
      x=x/j;
      //cout<<"x= "<<x<<endl;
      }
    while(modulo(y,j)==0){
     // cout<<"y es par"<<endl;
      y=y/j;
    //  cout<<"y= "<<x<<endl;
      }
    ZZ t=positivo(x-y)/j;
    //cout<<"t= (x-y)/2= "<<t<<endl;
    if(x >= y){
      x=t;
    //  cout<<"x= "<<x<<endl;
      }
    else{
      y=t;
      //cout<<"y= "<<x<<endl;
      }
  }
  return ZZ(g*y);
}


//Execution Time: 2e-06
ZZ algoritmo6(ZZ a, ZZ b){
  while(a!=b){
    //cout<<"a= "<<a<<", b= "<<b<<endl;
    if( a > b ){
      a=a-b;//cout<<"a= "<<a<<endl;
      }
    else {
      b=b-a;//cout<<"b= "<<b<<endl;
    }
  }
  return   ZZ(a);
}

//4
int main() {
    ZZ a, b, c;
    //b=9007199254740991;
    //c=6460783776271906;
    ifstream fe("numerosA.txt");
    while (!fe.eof()) {
    fe >> b;
    }
    fe.close();
    ifstream fa("numerosB.txt");
    while (!fa.eof()) {
    fa>> c;
    }
    fe.close();
    clock_t t0 = clock();
    a = algoritmo6(b, c);
    cout << "MCD= " << a << endl;
    clock_t t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    return 0;
}
