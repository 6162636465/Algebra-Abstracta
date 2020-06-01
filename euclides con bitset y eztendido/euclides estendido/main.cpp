#include <iostream>
#include<math.h>
#include<vector>
using namespace std;

void AlgoritmoDeEclidesExtendido(int a,int b){
  int d,x2=1,x1=0,y2=0,y1=1,q,r,x,y;
  if (b==0){
    d=a;
    x=1;
    y=0;
  }
  while (b>0){
    cout<<"aqui"<<endl;
    q=a/b; cout<<q<<endl;
    r=a-q*b;cout<<r<<endl;
    x=x2-q*x1;cout<<x<<endl;
    y=y2-y1*q;cout<<y<<endl;
    a=b;cout<<a<<endl;
    b=r;cout<<b<<endl;
    x2=x1;cout<<x2<<endl;
    x1=x;cout<<x1<<endl;
    y2=y1;cout<<y2<<endl;
    y1=y;cout<<y1<<endl;
     }
  d=a;
  x=x2;
  y=y2;
  cout<<"final"<<endl;
  cout<<" d:"<<d<<" x: "<<x<<" y: "<<y<<endl;
}


int main()

{
    AlgoritmoDeEclidesExtendido(816,2260);
}