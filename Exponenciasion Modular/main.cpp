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
ZZ modulo(ZZ a, ZZ b){
    if(a>=0)
        return a-(a/b)*b;
    else
        return a-((a/b)-1)*b;
}
ZZ madara(ZZ base, ZZ elevar)//esponente
{
    ZZ total, i;
	total = 1; i = 0;
	for (i; i < elevar; i++) {
		total *= base;
	}
	return total;
}
ZZ exponenciasionModular(ZZ x,ZZ y,ZZ z)// (alfabeto[i],n,mod(x))
{
    ZZ exponente,numerosSirven,sasuke,resultado,par,uno,cero,temp;
    uno=1;
    cero=0;
    numerosSirven=1;
    exponente=1;
    par=2;
    //cout<<"binario : ";
    while(y!=0)
        {
            sasuke=modulo(y,par);
            //cout<<sasuke;
            if (sasuke==uno)
                {
                    temp=madara(x,exponente);
                    numerosSirven=numerosSirven*temp;
                    resultado=modulo(numerosSirven,z);
                    y=y/2;
                    exponente=exponente*2;
                }
            else if(sasuke==cero)
                {
                    exponente=exponente*2;
                    y=y/2;
                }
        }
        cout<<endl;
        cout<<resultado<<endl;

}
int main()
{
   ZZ a, b, c;
    ifstream fe("numerosA.txt");
    while (!fe.eof()) {
    fe >> b;
    }
    fe.close();
    ifstream fa("numerosB.txt");
    while (!fa.eof()) {
    fa>> c;
    }
    fa.close();
    ifstream fi("numerodelabecedario.txt");
    while (!fi.eof())
        {
    fi>> a;
    }
    fi.close();
    //_______________________________________________
    exponenciasionModular(a,b,c);// alfabeto[i],n,mod(x)
}
