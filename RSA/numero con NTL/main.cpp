#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <NTL/ZZ.h>
#include <stdlib.h>
#include <fstream>
#include "rsa.h"
#include <sstream>
using namespace std;
using namespace NTL;
using std::string;
int main() {
	/*
	int ga = 55;
	ZZ a(ga);
	cout << a << endl;
	ZZ x;
	string str("54");
	x = stringtozz(str);
	cout << x << endl;*/
	RSA algo;
	ZZ a, b, c;
	a = 246, b = 173, c = 731;
	ZZ r, s;
	r = 3, s = 5;
	ZZ q;
	q= RandomPrime_ZZ(100);
}
