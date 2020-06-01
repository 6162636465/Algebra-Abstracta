#include <iostream>
#include <string>
#include "cifrado.h"
using std::string;
using namespace std;

int main() {
  string mensaje="MIRA ESA COLINA ";
  monobi algo;
  string cifrado=algo.cifrar(mensaje);
  cout<<cifrado<<endl<<endl;
  string descifrado=algo.descifrar(cifrado);
  cout<<descifrado<<endl;
  return 0;
}