//javier Alvarez Reyes
#include <cstdlib>
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
#include "playfair.h"
using std::string;
using namespace std;

int main() {
  string y;//mensaje
  string x;//clave
  string abecedario("abcdefghijklmnopqrstuvwxyz");
  int aea;//condicional
  cout << "coloque su mensaje" << endl;
  getline(cin, y);
  cout << "coloque la clave" << endl;
  getline(cin, x);
  cout << "seleccione(1) si va a cifrar o (2) si va a decifrar" << endl;
  cin >> aea;
  if(aea==1)
  {
    cifrado p1 = cifrado(x,y,abecedario);
    p1.cifrar();
  }
  else if(aea==2)
  {
    //p1.decifrar();
  }
}