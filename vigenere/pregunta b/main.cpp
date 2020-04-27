//javier Alvarez Reyes
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
using std::string;
#include "vigenere.h"
using std::string;
using namespace std;
int main()
{
  int x;
  int aea;
  string n("aea policia");
  string m;
  string sifrado;
  cout << "coloque la clave" << endl;
  getline(cin, m);
  cout << "seleccione el alfabeto: (1)ASCCI,(2)HEX,(3)NUMERICO" << endl;
  cin >> x;
  cout << "seleccione(1) si va a cifrar o (2) si va a decifrar" << endl;
  cin >> aea;
  if(aea==1)
  {
    cifrado p1 = cifrado(x, m,n,sifrado);
    p1.cifrar();
  }
  else if(aea==2)
  {
    cifrado p1 = cifrado(x, m,n,sifrado);
    p1.decifrar();
  }
}