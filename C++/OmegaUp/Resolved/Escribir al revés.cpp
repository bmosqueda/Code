/*
  Descripción

  Pediras una cadena de caracteres, y la desplegaras al revés
  Entrada

  cadena
  Salida

  cadena desplegada al revés
  Ejemplo

  Entrada Salida

  Pedro

  ordeP

  Límites

      No especificado
*/
#include <iostream> 
// #include <string> 
using namespace std;

int main(int argc, char const *argv[])
{
  string str = "";
  char character;
  while((character = cin.get()) != '\n')  
  {
    str = character + str;
  }

  cout << str;
/*
  getline(cin, str);
;

  for (int i = str.length(); i >= 0; --i)
  {
    cout << str[i];
  }*/

  return 0;
}