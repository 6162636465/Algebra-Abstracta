#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <fstream>

#include <string>
#include <sstream>// zz to string
#include <NTL/ZZ.h>
#include <vector>
#include <random>
using namespace std;
using namespace NTL;
using namespace std;

class RC4
{
private:
    ZZ semilla;
    ZZ A;
    ZZ B;
public:
    vector<string> K;
    vector<string> S;
    DWORD nicks=0*459849;
    RC4(ZZ,ZZ);
    ZZ generadorS();
    ZZ principal();
    ZZ stringtozz(string);
    string zztostring(ZZ);
    vector<string> rellenarA();
    string rellenarB();
};
RC4::RC4(ZZ _A,ZZ _B)
{
    semilla=generadorS();
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
ZZ RC4::principal()
{
    cout<<semilla<<" "<<B<<" "<<A<<endl;
    cout<<"a :"<<A<<endl;
    ZZ c,x;
    c=1;
    for(x=1;x<A+c;x++){
        K.push_back(zztostring(x));
    }
    vector<string>::iterator indice=K.begin();
    for (indice; indice != K.end(); indice++) {
    }
}
int main()
{
    ZZ a,b;
    a=250;
    b=5;
    RC4 p1= RC4(a,b);
    p1.principal();
}