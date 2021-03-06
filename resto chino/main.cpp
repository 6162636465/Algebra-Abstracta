#include <iostream>
#include <string>
#include <sstream>// zz to string
#include <NTL/ZZ.h>
#include <vector>
#include <random>
#include <NTL/vector.h>
using namespace std;
using namespace NTL;

ZZ modulozz(ZZ a, ZZ b)
 {
	if (a >= 0)
		return a - (a / b) * b;
	else
		return a - ((a / b) - 1) * b;
}

int modulo(int a, int b)
 {
	if (a >= 0)
		return a - (a / b) * b;
	else
		return a - ((a / b) - 1) * b;
}


string zztostring(ZZ num)
 {
	stringstream buffer;
	buffer << num;
	return buffer.str();
}

int zztoint(ZZ num)
 {
	string temp = zztostring(num);
	int numero = stoi(temp);
	return numero;
}

ZZ mcd(ZZ a, ZZ b)
 {
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

ZZ inversa(ZZ entero, ZZ modulonum)
 {
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

ZZ restoChino(ZZ num)
 {
	int ishigami;
	int kaguya[100];
	int chika[100];
	int maid[100];

	cout << "Introduzca los coeficientes de x" << endl;
	for (ZZ i(0); i < num; i++) {
		cin >> ishigami;
		kaguya[zztoint(i)]=ishigami;
	}


	cout << "Introduzca los valores naturales" << endl;
	for (ZZ i(0); i < num; i++) {
		cin >> ishigami;
		chika[zztoint(i)] = ishigami;
	}


	cout << "Introduzca los modulos" << endl;
	for (ZZ i(0); i < num; i++) {
		cin >> ishigami;
		maid[zztoint(i)] = ishigami;
	}
	int size1 = zztoint(num);

	for (int i = 0; i<size1; i++) {
		if (kaguya[i] != 1) {
			int temp = chika[i];
			chika[i] = zztoint(inversa(ZZ(kaguya[i]),ZZ(maid[i])));
			chika[i] = chika[i] * temp;
			kaguya[i] = 1;
		}
	}


	cout << "Ecuaciones: " << endl;
	for (int i = 0; i < size1; i++)
		cout << kaguya[i] << " = " << chika[i] << " mod " << maid[i] << endl;

	ZZ p(1);
	for (int i = 0; i < size1; i++) {
		p *= ZZ(maid[i]);
	}

	cout << "P= " << p << endl;

	int parr[100];
	int qarr[100];
	for (int i = 0; i < size1; i++)
		parr[i] = zztoint(p) / maid[i];


	cout << "p= ";
	for (int t = 0; t < size1; t++)
		cout<< parr[t]<<" ";
	cout << endl;

	for (int i = 0; i < size1; i++) {
		int temp = zztoint(inversa(ZZ(parr[i]), ZZ(maid[i])));
		temp = modulo(temp, maid[i]);
		qarr[i] = temp;
	}

	cout << "q= ";
	for (int t = 0; t < size1; t++)
		cout << qarr[t] << " ";
	cout << endl;

	ZZ res(0);

	for (int i = 0; i < size1; i++) {
		ZZ temp = ZZ(chika[i]) * ZZ(parr[i]) * ZZ(qarr[i]);
		res += temp;
	}

	res = modulozz(res, p);
	return res;
}


int main()
{

	restoChino(ZZ(3));
}
