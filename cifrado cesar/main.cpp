//javier Alvarez Reyes
#include <iostream>
#include<string>
#include <sstream>
using std::string;
using namespace std;
class cifrado
{
private:
    int x;
    string y;
    string abecedario;
public:
    cifrado(int, string,string);
    void cifrar();
    void decifrar();
};
cifrado::cifrado(int _x, string _y,string _abecedario)
{
    x=_x;
    y=_y;
    abecedario=_abecedario;
}
void cifrado::cifrar()
{
    string respuesta;
    string espacio(" ");
    string token;
    istringstream iss(y);
    cout <<y<< endl;
    while (getline(iss, token, ' '))
    {
      string letra("");
      for (int i = 0; i < token.size(); ++i)
        {
            for (int n = 0; n <abecedario.size(); ++n)
            {
                if(token[i]==abecedario[n])
                {
                    letra = letra+abecedario[n + x];
                }
            }
        }
        respuesta += letra;
        respuesta +=espacio;
    }
    cout <<respuesta<< endl;
}
void cifrado::decifrar()
{
  string respuesta;
    string espacio(" ");
    string token;
    istringstream iss(y);
    cout <<y<< endl;
    while (getline(iss, token, ' '))
    {
      string letra("");
      for (int i = 0; i < token.size(); ++i)
        {
            for (int n = 0; n <abecedario.size(); ++n)
            {
                if(token[i]==abecedario[n])
                {
                    letra = letra+abecedario[n - x];
                }
            }
        }
        respuesta += letra;
        respuesta +=espacio;
    }
    cout <<respuesta<< endl;
}
int main()
{
    int z=1;//variable para cifrar o decifrar
    int x;
    string y;
    string abecedario("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    cout << "coloque su mensaje" << endl;
    getline(cin, y);
    cout << "coloque un numero para la clave" << endl;
    cin >> x;
    cout << "si decea cifrar pong (1) si desea decifrar ponga(2)" << endl;
    cin >> z;
    cifrado p1 = cifrado(x, y,abecedario);
    if(z==1)//cifrar
    {
      p1.cifrar();
    }
    else if(z==2)//decifrar
    {
      p1.decifrar();
    }
}