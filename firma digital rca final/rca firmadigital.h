#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>// zz to string
#include <NTL/ZZ.h>
#include <vector>
#include <random>
#include <NTL/vector.h>
using namespace std;
using namespace NTL;
#ifndef RCA_FIRMADIGITAL_H_INCLUDED
#define RCA_FIRMADIGITAL_H_INCLUDED
#endif // RCA_FIRMADIGITAL_H_INCLUDE

class RSA {
	ZZ claveprivada;//e
	ZZ semilla;
	ZZ semillaB;
	ZZ p;
	ZZ q;
	ZZ semillabits;
	ZZ semillabitsB;
	ZZ phiden;
	ZZ n_priv;
    ZZ clavepublica_mia;//e
	ZZ resto_chino(ZZ pos);
	ZZ primalidad();
	ZZ bits;
	string abecedario;
public:
    DWORD nicks=0*459859;
	RSA(ZZ), RSA(ZZ, ZZ);
	ZZ modulozz(ZZ, ZZ);
	ZZ mcd(ZZ, ZZ);
	ZZ inversa(ZZ, ZZ);
	ZZ potenciar(ZZ, ZZ);
	ZZ modular_pow(ZZ, ZZ, ZZ);
	ZZrandomprimo2(int);
	ZZ stringtozz(string);
	ZZ clavepublica_otro, n_otro, maximo;
	ZZ generadorS();
	ZZ generadorA();
	ZZ usobits(ZZ);
	int zztoint(ZZ), moduloint(int, int);
	string inttostring(int), zztostring(ZZ);
	string cifrado_firma(string);
	string cifrado_rubrica(string);
	string descifrado_firma(string);
	string descifrado_rubrica(string);
	string igualar(string, ZZ);
	string completar(string, int);
};
RSA::RSA(ZZ maximo_bits) {
    bits=maximo_bits;
    semilla=generadorS();
    semillaB=generadorA();
    semillabits=usobits(semilla);
    semillabitsB=usobits(semillaB);
	maximo = maximo_bits;
	string tempp, tempq, temppublica;
	p = semillabits;
	tempp = "252869";//p
	//p = stringtozz(tempp);//guardar p
	q = semillabitsB;
	tempq = "215909";//q
	//q = stringtozz(tempq);//guardar q
	n_priv = p * q;
	phiden = (p - 1) * (q - 1);
	clavepublica_mia = RandomPrime_ZZ(10);
	temppublica = "1021";//clave publica
	clavepublica_mia = stringtozz(temppublica);//guardar clave publica
	claveprivada = modulozz(clavepublica_mia, phiden);
	claveprivada = inversa(claveprivada, phiden);
	abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
	cout << "abecedario : " << semillabits<< endl << endl;
	cout << "semilla : " << semillaB << endl << endl;
	cout << "p: " << p << endl << endl << "q: " << q << endl << endl;
	cout << "N: " << n_priv<< endl << endl;
	cout << "Fi de N: " << phiden << endl << endl;
	cout << "Clave publica(e): " << clavepublica_mia << endl << endl;
	cout << "Clave privada(d): " << claveprivada << endl << endl;;
}
RSA::RSA(ZZ nreceptor, ZZ clave_publica) {
	clavepublica_otro = clave_publica;
	n_otro = nreceptor;
}
ZZ RSA::generadorS(){
    HWND ventana;
    DWORD pid;
    HANDLE hp;
    char buffer[222];//char usado para almacenar una direccion de memoria no afecta al codigo
    ventana=FindWindow(0,"Discord");//aplicacion determinada
    GetWindowThreadProcessId(ventana,&pid);
    hp=OpenProcess(PROCESS_ALL_ACCESS,true,pid);
    ReadProcessMemory(hp,(PBYTE*)nicks,&buffer,sizeof(buffer),0);
    ZZ x = conv<ZZ>(pid);//convierto int a zz
    return x;
}
ZZ RSA::generadorA(){
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
ZZ RSA::usobits(ZZ wuw){
    ZZ x,i,minimo,maximo,valor1,valor2;
    x=1;
    for(i=0;i<bits;i++)
        x=x*2;

    minimo=x/2;
    maximo=x-1;
    ZZ adan;
    adan=wuw;
    bool popa=true,papa=true;
    string nani=zztostring(minimo);
    string te=zztostring(adan);
    valor1=nani.length();
    valor2=te.length();
    if(valor2<valor1){
        ZZ gaa,xddd;
        xddd=valor1-valor2;
        for(int jo=0,gaa=0;gaa<xddd;gaa++,jo++)
            te=te+te[jo];

        adan=stringtozz(te);
    }
    else{
        while(popa==true){
            string tempe=zztostring(adan);
            if(minimo<adan && adan<maximo){
                adan=stringtozz(tempe);
                popa=false;
            }
            else{

                adan=stringtozz(tempe);
            }
            popa=false;
            i++;
        }
    }
    cout<<"interbalo de bits de "<<x/2<<" a "<<x-1 <<endl;
    return adan;
}
int RSA::moduloint(int a, int b) {
	if (a >= 0)
		return a - (a / b) * b;
	else
		return a - ((a / b) - 1) * b;
}
ZZ RSA::modulozz(ZZ a, ZZ b) {
	if (a >= 0)
		return a - (a / b) * b;
	else
		return a - ((a / b) - 1) * b;
}/*
ZZ RSA::primalidad()
{
    semillabits
}*/
ZZ RSA::mcd(ZZ a, ZZ b) {
	ZZ r;
	while (true) {
		r = modulozz(a, b);
		if (r == 0)
			return b;
		if (r > (b / 2)) {
			r = b - r;
		}
		a = b;
		b = r;
	}
}
ZZ RSA::inversa(ZZ entero, ZZ modulonum) {
	if (mcd(entero, modulonum) != 1) {
		cout << "Este numero no tiene inversa" << endl;
		return ZZ(0);
	}

	ZZ modulo_cero = modulonum, variable, cociente;
	ZZ variable0, variable1;
	variable0 = 0, variable1 = 1;
	while (entero > 1) {
		cociente = entero / modulonum;
		variable = modulonum;
		modulonum = modulozz(entero, modulonum);
		entero = variable;
		variable = variable0;
		variable0 = variable1 - cociente * variable0;
		variable1 = variable;
	}
	if (variable1 < 0)
		variable1 += modulo_cero;
	return variable1;
}
ZZ RSA::potenciar(ZZ base, ZZ elevar) {
	ZZ total, i;
	total = 1; i = 0;
	for (i; i < elevar; i++) {
		total *= base;
	}
	return total;
}
ZZ RSA::modular_pow(ZZ base, ZZ exponenete, ZZ mod) {
	ZZ result, dos;
	result = 1, dos = 2;
	while (exponenete > 0) {
		if (modulozz(exponenete, dos) == 1)
			result = modulozz((result * base), mod);
		exponenete >>= 1;
		base = (base * base) % mod;
	}
	return result;
}
string RSA::inttostring(int a) {
	ostringstream temp;
	temp << a;
	return temp.str();
}
string RSA::zztostring(ZZ num) {
	stringstream buffer;
	buffer << num;
	return buffer.str();
}
int RSA::zztoint(ZZ num) {
	string temp = zztostring(num);
	int numero = stoi(temp);
	return numero;
}
ZZ RSA::stringtozz(string str) {
	ZZ z(NTL::INIT_VAL, str.c_str());
	return z;
}
int random(int max) {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> random(0, max);
	return random(rng);
}

string RSA::igualar(string letra, ZZ maximo) {//agregar 0
	string ret;
	ZZ hueco = ZZ(letra.size());
	hueco = maximo - hueco;
	for (int i = 0; i < hueco; i++)
		ret += "0";
	ret += letra;
	return ret;
}
string RSA::completar(string mensaje, int division) {
	string dev;
	int size = mensaje.size();
	size = moduloint(size, division);
	size = division - size;
	if (moduloint(size, 2) == 0) {
		for (int i = 0; i < size / 2; i++)
			mensaje += "25";
	}
	if (moduloint(size, 2) != 0) {
		for (int i = 0; i < size / 2; i++)
			mensaje += "25";
		mensaje += "7";
	}
	return mensaje;
}
ZZ RSA::resto_chino(ZZ pos) {
	ZZ dp, dq, expP, expQ, p_resto, p1, p2, q1, q2, res, d1, d2;
	expP = modulozz(claveprivada, p - 1);
	expQ = modulozz(claveprivada, q - 1);
	dp = modular_pow(modulozz(pos, p), expP, p);
	dq = modular_pow(modulozz(pos, q), expQ, q);
	p1 = n_priv / p;
	p2 = n_priv / q;
	q1 = inversa(modulozz(p1, p), p);
	q2 = inversa(modulozz(p2, q), q);
	d1 = modulozz(dp * p1 * q1, n_priv);
	d2 = modulozz(dq * p2 * q2, n_priv);
	res = d1 + d2;
	res = modulozz(res, n_priv);
	return res;
}
string RSA::cifrado_rubrica(string mensaje) {
	cout << "RUBRICA" << endl;
	string texto, conv, temp, temp2, igua, igua2;
	ZZ pos, tam, pos2;
	tam = abecedario.size();
	for (int i = 0; i < mensaje.size(); i++) {
		pos = abecedario.find(mensaje[i]);
		igua = zztostring(pos);
		igua2 = zztostring(tam);//cambio
		conv += igualar(igua, ZZ(igua2.size()));//letra i , tamaño de abecedario
	}
	string ntemp = zztostring(n_priv);
	int bloques = ntemp.size() - 1;
	conv = completar(conv, bloques);
	for (int i = 0; i < conv.size(); i += bloques) {
		for (int j = 0; j < bloques; j++) {
			temp += conv[i + j];
		}
		pos2 = stringtozz(temp);
		pos2 = resto_chino(pos2);
		temp2 = zztostring(pos2);
		temp2 = igualar(temp2, ZZ(ntemp.size()));
		texto += temp2;
		temp.clear();
		temp2.clear();
	}
	return texto;
}

string RSA::cifrado_firma(string mensaje) {
	cout << "FIRMA" << endl;
	string texto, conv, temp, temp2, igua, igua2;
	ZZ pos, tam, pos2;
	tam = abecedario.size();
	for (int i = 0; i < mensaje.size(); i++) {
		pos = abecedario.find(mensaje[i]);
		igua = zztostring(pos);
		igua2 = zztostring(tam);
		conv += igualar(igua, ZZ(igua2.size()));
	}
	string ntemp = zztostring(n_otro);
	int bloques = ntemp.size() - 1;
	conv = completar(conv, bloques);
	for (int i = 0; i < conv.size(); i += bloques) {
		for (int j = 0; j < bloques; j++) {
			temp += conv[i + j];
		}
		pos2 = stringtozz(temp);
		pos2 = modular_pow(pos2, clavepublica_otro, n_otro);
		temp2 = zztostring(pos2);
		temp2 = igualar(temp2, ZZ(ntemp.size()));
		texto += temp2;
		temp.clear();
		temp2.clear();
	}
	return texto;
}

string RSA::descifrado_firma(string cifrado) {
	cout << "FIRMA" << endl;
	string texto, conv, temp, temp2;
	ZZ pos, tam, pos2;
	int indice;
	string descifrado;
	string ntemp = zztostring(n_priv);
	int bloques = ntemp.size();

	for (int i = 0; i < cifrado.size(); i += bloques) {
		for (int j = 0; j < bloques; j++) {
			temp += cifrado[i + j];
		}
		pos2 = stringtozz(temp);
		pos2 = resto_chino(pos2);
		temp2 = zztostring(pos2);
		tam = ZZ(bloques - 1);
		temp2 = igualar(temp2, tam);
		conv += temp2;
		temp.clear();
		temp2.clear();
	}

	int tamabc = abecedario.size();
	string tama = inttostring(tamabc);
	tamabc = tama.size();
	for (int i = 0; i < conv.size(); i += tamabc) {
		for (int j = 0; j < tamabc; j++) {
			temp += conv[i + j];
		}
		indice = stoi(temp);
		temp2 = abecedario[indice];
		descifrado += temp2;

		temp.clear();
	}
	int sizedes = descifrado.size() - 1;
	bool ga = descifrado[sizedes] == descifrado[sizedes - 1];
	for (; ga == true; sizedes = descifrado.size() - 1, ga = descifrado[sizedes] == descifrado[sizedes - 1]) {
		descifrado.pop_back();
	}
	descifrado.pop_back();
	return descifrado;
}
string RSA::descifrado_rubrica(string cifrado) {
	cout << "RUBRICA :"<< endl;
	string texto, conv, temp, temp2;
	ZZ pos, tam, pos2;
	int indice;
	string descifrado;
	string ntemp = zztostring(n_otro);
	int bloques = ntemp.size();

	for (int i = 0; i < cifrado.size(); i += bloques) {
		for (int j = 0; j < bloques; j++) {
			temp += cifrado[i + j];
		}
		pos2 = stringtozz(temp);
		pos2 = modular_pow(pos2, clavepublica_otro, n_otro);
		temp2 = zztostring(pos2);
		tam = ZZ(bloques - 1);
		temp2 = igualar(temp2, tam);
		conv += temp2;
		temp.clear();
		temp2.clear();
	}

	int tamabc = abecedario.size();
	string tama = inttostring(tamabc);
	tamabc = tama.size();
	for (int i = 0; i < conv.size(); i += tamabc) {
		for (int j = 0; j < tamabc; j++) {
			temp += conv[i + j];
		}
		indice = stoi(temp);
		//cout << "tam abc = " << abecedario.size() << endl;
		//cout << indice << endl;
		temp2 = abecedario[indice];
		descifrado += temp2;

		temp.clear();
	}
	int sizedes = descifrado.size() - 1;
	bool ga = descifrado[sizedes] == descifrado[sizedes - 1];
	for (; ga == true; sizedes = descifrado.size() - 1, ga = descifrado[sizedes] == descifrado[sizedes - 1]) {
		descifrado.pop_back();
	}
	descifrado.pop_back();
	return descifrado;
}
