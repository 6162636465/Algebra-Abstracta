#include <iostream>
#include <string>
#include <sstream>// zz to string
#include <NTL/ZZ.h>
#include <vector>
#include <random>
#include <NTL/vector.h>
#include "rca firmadigital.h"
#include "rc4.h"
using namespace std;
using namespace NTL;
int main()
{
    int opcion;
    /*
//___________________________________________RC4________________________________________________________________________
    string algo;
    ZZ a,b;
    a=250;//numnero i bits
    b=5;
    RC4 p1= RC4(a,b);
    algo=p1.principal();
    ///DES///////////////////////////////////////////////////////////////////////////////////////
    cout<<endl<<endl<<endl<<"string to DES"<<endl<<algo<<endl;
    int clave=1024;
    ZZ temp;
    string def=clavedef(clave, algo);
    cout<<"La clave de "<<clave<<" seria: "<<endl;
    cout<<def<<endl<<endl<<endl;
    cout<<"Y convertido a numero seria: "<<endl;
    cout<<convertirbit(def);
//______________________________________________________________________________________________________________________
*/

	ZZ n_otrocifrado, clave_otro, cifrado, n_otrodescifrado, clave_otrodescifrado;

	cout<<"ponga 1 si va a cifrar y 2 si va a decifrar"<<endl;
	cin>>opcion;
	if(opcion==1)
    {
	/////CIFRADO

	RSA yo(ZZ(1024));
	cout<<"Para el cifrado: "<<endl<<"Coloque la N"<<endl;
	cin>> n_otrocifrado;
	cout<<"Coloque la clave publica (e)"<<endl;
	cin>> clave_otro;
	string mensaje, cifrado_rubrica, cifrado_firma;
	RSA otro(n_otrocifrado, clave_otro);
	mensaje = "esto es un ejemplo de cifrador usando bloques";
	cifrado_rubrica = yo.cifrado_rubrica(mensaje);
	cout << cifrado_rubrica << endl;
	cifrado_firma = otro.cifrado_firma(cifrado_rubrica);
	cout << "Cifrado: " << cifrado_firma << endl;

    }
	/////DESCIFRADO
	else if(opcion==2)
    {
	RSA yo_2(ZZ(5));
	cout << "Para el descifrado: " << endl << "Coloque la N" << endl;
	cin >> n_otrodescifrado;

	cout << "Coloque la clave publica (e)" << endl;
	cin >> clave_otrodescifrado;

	string mensaje_des, sdescifrado_rubrica, sdescifrado_firma;

	RSA otro_2(n_otrodescifrado, clave_otrodescifrado);
	cout << "Ingrese el mensaje" << endl;
	cin >> mensaje_des;

	sdescifrado_firma = yo_2.descifrado_firma(mensaje_des);
	cout << sdescifrado_firma << endl << endl << endl;

	sdescifrado_rubrica = otro_2.descifrado_rubrica(sdescifrado_firma);
	cout << "Descifrado: " << sdescifrado_rubrica << endl;
    }
}
