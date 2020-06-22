#include <iostream>
#include <string>
#include <sstream>// zz to string
#include <NTL/ZZ.h>
#include <vector>
#include <random>
#include <NTL/vector.h>
using namespace std;
using namespace NTL;

class RSA {
	ZZ claveprivada, p, q, phiden;
public:
	RSA(ZZ), RSA(ZZ, ZZ);
	ZZ modulozz(ZZ, ZZ), mcd(ZZ, ZZ), inversa(ZZ, ZZ), potenciar(ZZ, ZZ), modular_pow(ZZ, ZZ, ZZ), randomprimo2(int);
	ZZ stringtozz(string);
	ZZ clavepublica, n, maximo;
	int zztoint(ZZ), moduloint(int, int);
	string inttostring(int), zztostring(ZZ);
	string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
	string cifrado(string), descifrado(string),  igualar(string, ZZ), completar(string, int);
};
RSA::RSA(ZZ maximo_bits) {
	maximo = maximo_bits;
	p = RandomPrime_ZZ(18);
	p = 17;
	q = RandomPrime_ZZ(18);
	q = 59;
	n = p * q;
	phiden = (p - 1) * (q - 1);
	clavepublica = RandomPrime_ZZ(10);
	clavepublica = 3;
	claveprivada = modulozz(clavepublica, phiden);
	claveprivada = inversa(claveprivada, phiden);
	claveprivada = modulozz(claveprivada, phiden);
	cout << "p: " << p << "  " << "q: " << q << "   ";
	cout << "N: " << n << "   ";
	cout << "Fi de N: " << phiden << "   ";
	cout << "Clave publica(e): " << clavepublica << "   ";
	cout << "Clave privada(d): " << claveprivada << "   " << endl;
}

RSA::RSA(ZZ nreceptor, ZZ clave_publica) {
	clavepublica = clave_publica;
	n = nreceptor;
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
}

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

ZZ RSA::inversa(ZZ entero, ZZ modulonum){
    //ZZ N,ZZ M
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
	{
		variable1 += modulo_cero;
	}
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
ZZ RSA::modular_pow(ZZ base,ZZ expo, ZZ mod){
    ZZ cont;
    cont=1;
    ZZ enter;
    enter=2;
    while(expo!=0){
        if(modulozz(expo,enter)==1){
            cont=modulozz(cont*base,mod);
        }
        base=modulozz(base*base,mod);
        expo=expo/enter;
    }
    return cont;}

string RSA::inttostring(int a){
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

ZZ RSA::stringtozz(string str){
	ZZ z(NTL::INIT_VAL, str.c_str());
	return z;
}

int random(int max) {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> random(0, max);
	return random(rng);
}
string RSA::igualar(string letra, ZZ maximo) {
	string ret;
	ZZ hueco = ZZ(letra.size());
	hueco=maximo-hueco;
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

string RSA::cifrado(string mensaje) {
	cout << "CIFRADO :";
	string texto, conv, temp, temp2, igua, igua2;
	ZZ pos, tam, pos2;
	tam = abecedario.size();
	for (int i = 0; i < mensaje.size(); i++) {
		pos = abecedario.find(mensaje[i]);
		igua = zztostring(pos);
		igua2 = zztostring(tam);
		conv += igualar(igua, ZZ(igua2.size()));
	}
	string ntemp = zztostring(n);
	int bloques = ntemp.size() - 1;
	conv = completar(conv, bloques);
	for (int i = 0; i < conv.size(); i += bloques) {
		for (int j = 0; j < bloques; j++) {
			temp += conv[i+j];
		}
		pos2 = stringtozz(temp);
		pos2 = modular_pow(pos2, clavepublica, n);
		temp2 = zztostring(pos2);
		temp2 = igualar(temp2,ZZ(ntemp.size()));
		texto += temp2;
		temp.clear();
		temp2.clear();
	}
	return texto;
}

string RSA::descifrado(string cifrado) {
	string texto, conv, temp, temp2;
	ZZ pos, tam, pos2;
	int indice;
	string descifrado;
	string ntemp = zztostring(n);
	int bloques = ntemp.size();

	for (int i = 0; i < cifrado.size(); i += bloques) {
		for (int j = 0; j < bloques; j++) {
			temp += cifrado[i + j];
		}
		pos2 = stringtozz(temp);
		pos2 = modular_pow(pos2, claveprivada, n);
		temp2 = zztostring(pos2);
		tam = ZZ(bloques - 1);
		temp2 = igualar(temp2,tam);
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
	return descifrado;
}

int main() {
	ZZ maximo(5);
	RSA emisor(maximo);
	ZZ n, clave;
	clave = 3, n = 1003;
	RSA receptor(n, clave);

	string mensaje = "noteama";
	string cifrado = receptor.cifrado(mensaje);
	cout << "Cifrado: " << cifrado << endl;

	string cif = ("08560551100101030663082609200215");
	string descifrado = emisor.descifrado(cif);
	cout << "Descifrado :  " << descifrado << endl;
}
