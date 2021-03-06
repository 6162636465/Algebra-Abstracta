#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <fstream>

#include <string>
#include <sstream>// zz to string
#include <NTL/ZZ.h>
#include <vector>
#include <random>
#include <bitset>
using namespace std;
using namespace NTL;
using namespace std;

class RC4
{
private:
    ZZ semilla;
    ZZ semillabits;
    ZZ A;
    ZZ B;
public:
    string alfabeto = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ZZ bits = conv<ZZ>(100);//cantidad de bits
    vector<string> K;
    vector<string> S;
    DWORD nicks=0*459849;
    RC4(ZZ,ZZ);
    ZZ usobits();
    ZZ generadorS();
    ZZ principal();
    ZZ stringtozz(string);
    void iteraciones(vector<string>&);
    string zztostring(ZZ);
    string stringtoBinario(string);
    ZZ modulozz(ZZ,ZZ);
    int zztoint(ZZ);
    vector<string> secuenciacifrante(vector<string>&);
};
RC4::RC4(ZZ _A,ZZ _B)
{
    semilla=generadorS();
    semillabits=usobits();
    A=_A;
    B=_B;
}
ZZ RC4::stringtozz(string str){
    ZZ z(NTL::INIT_VAL, str.c_str());
    return z;
}
string RC4::zztostring(ZZ num) {
    stringstream buffer;
    buffer << num;
    return buffer.str();
}
ZZ RC4::usobits()
{
    ZZ x,i,minimo,maximo,valor1,valor2;
    x=1;
    for(i=0;i<bits;i++)
    {
        x=x*2;
    }
    minimo=x/2;
    maximo=x-1;
    ZZ adan;
    adan=semilla;
    bool popa=true,papa=true;
    string nani=zztostring(minimo);
    string te=zztostring(adan);
    valor1=nani.length();
    valor2=te.length();
    if(valor2<valor1)
    {
        ZZ gaa,xddd;
        xddd=valor1-valor2;
        for(int jo=0,gaa=0;gaa<xddd;gaa++,jo++)
        {
            te=te+te[jo];
        }
        adan=stringtozz(te);
    }
    else{
    while(popa==true)
        {
            string tempe=zztostring(adan);
            if(minimo<adan && adan<maximo)
                {
                    adan=stringtozz(tempe);
                    popa=false;
                }
            else
                {
                    tempe.erase(0,1);
                    adan=stringtozz(tempe);
                }
                popa=false;
                i++;
        }
    }
    cout<<"interbalo de bits de "<<x/2<<" a "<<x-1 <<endl;
    return adan;
}
ZZ RC4::generadorS()
{
    HWND ventana;
    DWORD pid;
    HANDLE hp;
    char buffer[222];//char usado para almacenar una direccion de memoria no afecta al codigo
    ventana=FindWindow(0,"steam");//aplicacion determinada
    GetWindowThreadProcessId(ventana,&pid);
    hp=OpenProcess(PROCESS_ALL_ACCESS,true,pid);
    ReadProcessMemory(hp,(PBYTE*)nicks,&buffer,sizeof(buffer),0);
    ZZ x = conv<ZZ>(pid);//convierto int a zz
    return x;
}
ZZ RC4::modulozz(ZZ a, ZZ b) {
	if (a >= 0)
		return a - (a / b) * b;
	else
		return a - ((a / b) - 1) * b;
}
int RC4::zztoint(ZZ num) {
	string temp = zztostring(num);
	int numero = stoi(temp);
	return numero;
}
void RC4::iteraciones(vector<string> &K)
{
    ZZ f,i,Si,Ki,cuatro;
    string ricardomilos;
    string KO;
    cuatro=A;//modulo a ();
    int temp,contador;
    KO=zztostring(semillabits);
    cout<<"KO ="<<KO[7]<<endl;
    string paultemp;
    int paco=KO.length();
    for(i=0;i<A;i++)
    {
        if(contador>=paco)
        {
            contador=0;
        }
        temp=zztoint(i);
        string aea=K[temp];
        paultemp=KO[contador];
        Si=stringtozz(aea);
        Ki=stringtozz(paultemp);
        f=modulozz((f+Si+Ki),cuatro);
        contador=contador+1;
        //variables cambio
        ricardomilos=K[temp];
        K[temp]=K[zztoint(f)];
        K[zztoint(f)]=ricardomilos;
    }
}
string RC4::stringtoBinario(string mensaje) {
    string algo, men;
    int indice = alfabeto.find(mensaje[0]);
    for (int i = 0; i < mensaje.size(); i++) {
        indice = alfabeto.find(mensaje[i]);
        bitset<8> m(indice);
        algo = m.to_string();
        men += algo;
    }
    return men;
}
vector<string> RC4::secuenciacifrante(vector<string> &S)
{
    ZZ I,F,axe,t,uwu;
    string ricardomilos;
    vector<string>::iterator indice=K.begin();
    for(axe=0;axe<A;axe++)
    {
        I=modulozz(I+1,A);
        F=modulozz(F+stringtozz(S[zztoint(axe+1)]),A);
        //cout<<"I :"<<I<<" F :"<<F<<endl;
        //syap
        ricardomilos=S[zztoint(I)];
        S[zztoint(I)]=S[zztoint(F)];
        S[zztoint(F)]=ricardomilos;
        uwu=stringtozz(S[zztoint(I)])+stringtozz(S[zztoint(F)]);
        t=modulozz(uwu,A);
        string oreimo=stringtoBinario(S[zztoint(t)]);
        K.push_back(oreimo);
    }
    return K;

}
ZZ RC4::principal()
{
    cout<<semilla<<" "<<B<<" "<<A<<endl;
    cout<<"semilla reducida a bits :"<<semillabits<<endl;//repitiendo la semilla
    cout<<"a :"<<A<<endl;
    ZZ c,x;
    c=1;
    for(x=1;x<A+c;x++){
        K.push_back(zztostring(x));
    }
    vector<string>::iterator indice=K.begin();
    for (indice; indice != K.end(); indice++) //vector l
        {
       cout << *indice <<",";
    }
    cout<<endl;
    cout<<"marca de agua"<<endl;
    iteraciones(K);
    string jackElDestripador;
    vector<string>::iterator aw=K.begin();
    for (aw; aw != K.end(); aw++) //vector l
        {
            jackElDestripador+=(*aw);
       cout << *aw <<",";
    }
    cout<<endl;
    cout<<"generacion de secuencia cifrante "<<endl;
    vector<string> hayasaka;//final
    hayasaka=secuenciacifrante(K);
    vector<string>::iterator kaguya;
    for(kaguya=hayasaka.begin(); kaguya!=hayasaka.end(); kaguya++)
        {
        cout<<*kaguya;
  }
    //juntar palabras oss
    cout<<endl;
    cout<<"primer paso"<<endl;
    cout<<jackElDestripador<<endl;
    //

}
int main()
{
    ZZ a,b;
    a=250;//numnero i bits
    b=5;
    RC4 p1= RC4(a,b);
    p1.principal();
    return 0;
}
