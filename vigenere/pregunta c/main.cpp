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
  int aea;
  string m("Pablo Neruda");
  string sifrado;
  cout << "seleccione(1) si va a cifrar o (2) si va a decifrar" << endl;
  cin >> aea;
  if(aea==1)
  {
    string n("Puedo escribir los versos mas tristes esta noche. Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise, y a veces ella tambien me quiso.");
    cifrado p1 = cifrado(m,n,sifrado);
    p1.cifrar();
  }
  else if(aea==2)
  {
    string n("CufoBZRwtKlbXrAwBRlzvKvof nlFZevzLwef fCG lrEwkeO FCqQVfzKb cosKsIRqFEr zaAyBBUiQyvtP fCGQRpBugaN zKGHcmJuq,na EzDdcQErsnatDENdcQuClb mpxNddQYo iifyGNlhvToannpnvDlkzKd TnApzZPmvEr l dlASNdQhxeSoApFBcmsBu ,otKIDcwELCmPsADEHdxvLCeftbKANPlvtCYb mlNPfmIyb l bKIDPiIThl,aADoLOmvGCmT rEwR.d");
    cifrado p1 = cifrado(m,n,sifrado);
    p1.decifrar();
  }
}
