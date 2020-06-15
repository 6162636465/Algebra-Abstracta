#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <NTL/ZZ.h>
#include <stdlib.h>
#include <fstream>

#endif // RSA_H_INCLUDED
#include <sstream>
using namespace std;
using namespace NTL;
using std::string;
class RSA {
	ZZ claveprivada;
public:
	RSA(), RSA(ZZ, ZZ);
	ZZ modulozz(ZZ, ZZ), mcd(ZZ, ZZ), extendido(ZZ, ZZ), inversa(ZZ, ZZ), potenciar(ZZ, ZZ), modular_pow(ZZ, ZZ, ZZ);
	ZZ stringtozz(string);
	ZZ clavepublica, n;
	int zztoint(ZZ), randomprimo2(int), moduloint(int, int);
	string inttostring(int), zztostring(ZZ);
	string abecedario = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
	string cifrado(string), descifrado(string);
};


RSA::RSA() {
	ZZ p = RandomPrime_ZZ(10);
	ZZ q = RandomPrime_ZZ(10);
	n = p * q;
	ZZ phiden = (p - 1) * (q - 1);
	clavepublica = RandomPrime_ZZ(10);
	claveprivada = modulozz(clavepublica, phiden);
	claveprivada = inversa(claveprivada, phiden);
	claveprivada = modulozz(claveprivada, phiden);
	cout << "p: " << p << "  " << "q: " << q << "   ";
	cout << "N: " << n << "   ";
	cout << "Fi de N: " << phiden << "   ";
	cout << "Clave publica: " << clavepublica << "   ";
	cout << "Clave privada: " << claveprivada << "   " << endl;
}

RSA::RSA(ZZ nreceptor, ZZ claveparaemisor) {
	clavepublica = claveparaemisor;
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

ZZ RSA::extendido(ZZ a, ZZ b) {
	ZZ r1, r2, s1, s2, t1, t2, r, s, t, q, i;
	r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 1, t2 = 1, i = 1;
	while (r2 > 0) {
		q = r1 / r2;

		r = r1 - q * r2;
		r1 = r2; r2 = r;

		s = s1 - q * s2;
		s1 = s2; s2 = s;

		t = t1 - q * t2;
		t1 = t2; t2 = t;
	}
	return s1;
}

ZZ RSA::inversa(ZZ a, ZZ n) {
	ZZ inv;
	inv = 0;
	if (mcd(a, n) != 1)
		cout << "Este numero no tiene inversa" << endl;

	else {
		inv = extendido(a, n);
		if (inv < 0)
			inv = modulozz(inv, n);
	}
	return inv;
}

ZZ RSA::potenciar(ZZ base, ZZ elevar) {
	ZZ total, i;
	total = 1; i = 0;
	for (i; i < elevar; i++) {
		total *= base;
	}
	return total;
}

ZZ RSA::modular_pow(ZZ x, ZZ y, ZZ z) {
	ZZ exponente, numerosSirven, sasuke, resultado, par, uno, cero, temp;
	uno = 1, cero = 0, numerosSirven = 1, exponente = 1, par = 2;
	while (y != 0){
		sasuke = modulozz(y, par);
		if (sasuke == uno){
			temp = potenciar(x, exponente);
			numerosSirven = numerosSirven * temp;
			resultado = modulozz(numerosSirven, z);
			y = y / 2;
			exponente = exponente * 2;
		}
		else if (sasuke == cero){
			exponente = exponente * 2;
			y = y / 2;
		}
	}
	return resultado;
}

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

int RSA::randomprimo2(int numero) {
	vector<int> primos;
	vector<int>::iterator temp;
	int limite = sqrt(numero);

	for (int i = 1; i <= numero; i++)
		primos.push_back(i);

	for (int j = 2; j <= limite; j++) {
		for (vector<int>::iterator it = primos.begin() + j; it != primos.end(); it++) {
			temp = it;
			if ((moduloint(*temp, j)) == 0) {
				primos.erase(temp);
				it--;
			}
		}
	}
	int pos = random(primos.size());
	vector<int>::iterator it = primos.begin() + pos;
	return *it;
}

string RSA::cifrado(string mensaje) {
	string texto;
	ZZ pos, tam;
	tam = abecedario.size();
	for (int i = 0; i < mensaje.size(); i++) {
		pos = abecedario.find(mensaje[i]);
		pos = modular_pow(pos, clavepublica, n);
		if (pos >= abecedario.size())
			pos = modulozz(pos, tam);
		texto += abecedario[zztoint(pos)];
	}
	return texto;
}

string RSA::descifrado(string cifrado) {
	string descifrado;
	ZZ pos, tamanoabecedario;
	tamanoabecedario = abecedario.size();
	for (int i = 0; i < cifrado.size(); i++) {
		pos = abecedario.find(cifrado[i]);
		pos = modular_pow(pos, claveprivada, n);
		if (pos >= abecedario.size())
			pos = modulozz(pos, tamanoabecedario);
		cifrado += abecedario[zztoint(pos)];
	}
	return cifrado;
}
