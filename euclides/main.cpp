#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
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
  while(true){
    r=modulo(a,b);
    //cout<<"r= "<<r<<endl;
    if(r==0)
      return b;
    a=b;
    //cout<<"a= "<<a<<endl;
    b=r;
    //cout<<"b= "<<b<<endl<<endl;
  }
}


//Execution Time: 2e-06
ZZ algoritmo2(ZZ a,ZZ b){
  //cout<<"Ingreso con los numeros "<<a<<" y "<<b<<endl;
  ZZ r;
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
  }
}



//Execution Time: 3e-06
ZZ algoritmo3(ZZ a, ZZ b){
  if(a<0||b<0){
    cout<<"Numero negativo detectado"<<endl;
  }
  if(b==0)
    return a;
  cout<<"Retornmos MCD("<<b<<", "<< modulo(a,b)<<")"<<endl;
  return algoritmo3(b, modulo(a,b));
}



//Execution Time: 4e-06
ZZ algoritmo4(ZZ a,ZZ b){
  ZZ x;
  x=2;
  if(positivo(b) > positivo(a))
    {
    cout<<"Retornmos MCD("<<b<<", "<< a<<")"<<endl;
    return algoritmo4(b,a);
    }
  if(b==0)
    return a;
  if( (modulo(a,x)==0) && (modulo(b,x)==0) ){
    cout<<"Retornmos MCD 2*("<<a/x<<", "<< b/x<<")"<<endl;
    return 2*algoritmo4(a/x, b/x);}
  if( (modulo(a,x)==0) && (modulo(b,x)!=0) ){
    cout<<"Retornmos MCD("<<a/2<<", "<< b<<")"<<endl;
    return algoritmo4(a/x, b);}
  if( (modulo(a,x)!=0) && (modulo(b,x)==0) ){
    cout<<"Retornmos MCD("<<a<<", "<< b/x<<")"<<endl;
    return algoritmo4(a, b/x);}
  cout<<"Retornmos MCD("<<(positivo(a)- positivo(b) )/2<<", "<< b<<")"<<endl;
  return algoritmo4( (positivo(a)- positivo(b) )/2,b );
}


//Execution Time: 3e-06
ZZ algoritmo5(ZZ x,ZZ y){
 cout<<"Ingreso con los numeros "<<x<<" y "<<y<<endl;
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
    cout<<"Ambos son pares"<<endl;
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
  return (g*y);
}


//Execution Time: 2e-06
ZZ algoritmo6(ZZ a,ZZ b){
  while(a!=b){
    //cout<<"a= "<<a<<", b= "<<b<<endl;
    if( a > b ){
      a-=b;//cout<<"a= "<<a<<endl;
      }
    else {
      b-=a;//cout<<"b= "<<b<<endl;
    }
  }
  return a;
}

//4
int main(){
clock_t t0=clock();
ZZ a, b, c;
b=4666666666666666666666666666666666666666666666666666666;
c=33333222222222222222222222222222222222222222222222222222222;
a=algoritmo6(b,c);
cout<<"MCD= "<<a<<endl;
clock_t t1 = clock();

double time = (double(t1-t0)/CLOCKS_PER_SEC);
cout << "Execution Time: " << time << endl;
return 0;
}
