//javier Alvarez Reyes
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
using std::string;
using namespace std;
class cifrado
{
private:
  string n;//mensaje
public:
  cifrado(string);
  void cifrar();
  void decifrar();
};
cifrado::cifrado(string _n)
{
  n=_n;//mensaje
}
void cifrado::decifrar()
{
  cout <<"mensaje encriptado:" << endl;
  cout <<n << endl;
  int longitud=n.length();
  cout <<"la longitud es:"<<longitud<< endl;
  int dividir=longitud/14;
  cout <<"se dividira en: "<<dividir<<" grupos de caracteres"<< endl;
}