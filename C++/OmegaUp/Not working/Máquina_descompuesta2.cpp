/*
  Descripción

  En este caso, tenemos una máquina de escribir que cambia entre mayúsculas y minúsculas de manera arbitraria. Pero ahora la utilizaremos para escribir títulos y subtítulos de películas. Por ejemplo:

      duRO De mAtaR 3: La VENgaNzA

  debería convertirse en:

      Duro De Matar 3: "La Venganza"

  La reglas serán:

      La primera letra de cada palabra debe ser mayúscula y todas las demás letras deben ser minúsculas.

      Si aparece el signo de dos puntos (:) lo siguiente es un subtítulo y debe aparecer entre comillas.

  Entrada

  Consiste de una cadena SS de longitud entre 1 y 80. Los caracteres de esa cadena podrán ser letras (sin acentos), dígitos, dos puntos y espacios.
  Salida

  Consiste de una cadena TT en la cual se han arreglado las mayúsculas y las minúsculas, y cuando sea necesario agregar comillas al subtítulo.
*/
#include <iostream>
#include <string>
using namespace std;

bool isLetter(int chr) {
  return (chr >= 65 && chr <= 90) || (chr >= 97 && chr <= 122);
}

char convertUpperToLower(int chr) {
  if(chr >= 65 && chr <= 90)
    return (char)(chr + 32);
  return (char)chr;
}

char convertLowerToUpper(int chr) {
  if(chr >= 97 && chr <= 122)
    return (char)(chr - 32);
  return (char)chr;
}

int main(int argc, char* argv[]) 
{
  char x;
  string str = "";
  bool hayEspacio = true;
  bool pusoComillas = false;
  bool primeraComilla = false;

  while(cin.get(x)) {
    int ascci = (int)x;
    if(isLetter(ascci)) 
    {
      if(hayEspacio) 
      {
        str += convertLowerToUpper(ascci);
        hayEspacio = false;
      }
      else 
      {
        str += convertUpperToLower(ascci);
      }
    }
    else if(x == ' ') 
    {
      hayEspacio = true;
      str += x;

      if(primeraComilla) 
      {
        primeraComilla = false;
        str += '"';
      } 
    }
    else if(x == ':') 
    {
      pusoComillas = true;
      primeraComilla = true;
      str += x;
    }
    else if(ascci != '\n') 
    {
      str += x;
    }
    else 
    {
      if(pusoComillas)
        str += '"';
      break;
    }
  }

  cout << str << endl;
}