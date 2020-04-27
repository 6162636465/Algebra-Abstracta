//javier Alvarez Reyes
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
using std::string;
#include "vigenere3(d).h"
using std::string;
using namespace std;
int main()
{
  int aea;
  string n("CufoBZRwtKlbXrAwBRlzvKvof nlFZevzLwef fCG lrEwkeO FCqQVfzKb cosKsIRqFEr zaAyBBUiQyvtP fCGQRpBugaN zKGHcmJuq,na EzDdcQErsnatDENdcQuClb mpxNddQYo iifyGNlhvToannpnvDlkzKd TnApzZPmvEr l dlASNdQhxeSoApFBcmsBu ,otKIDcwELCmPsADEHdxvLCeftbKANPlvtCYb mlNPfmIyb l bKIDPiIThl,aADoLOmvGCmT rEwR.d");
  cifrado p1 = cifrado(n);
  p1.decifrar();
}