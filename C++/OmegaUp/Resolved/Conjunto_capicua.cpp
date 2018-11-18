/*
  Descripción

  Dado un conjunto de 1<=N<=1000 dígitos, determinar si se trata de un conjunto capicúa. Un conjunto capicúa se lee igual de izquierda a derecha que de derecha a izquierda, por ejemplo: 1 3 4 3 1, es un conjunto capicúa, mientras que 1 3 4 5 1 no lo es.
  Entrada

  En la primera línea el número de dígitos en el conjunto. En la segunda línea los N dígitos separados por espacios.
  Salida

  La palabra SI, si es un conjunto capicúa, o NO si no lo es.

  Entrada
  5
  1 3 4 3 1
*/
#include <iostream> 
using namespace std;

int main(int argc, char const *argv[])
{
  string str1 = "";
  string str2 = "";
  short lenght;
  cin >> lenght;

  for (short i = 0; i < lenght; ++i)
  {
    char temp;
    cin >> temp;

    str1 += temp;
    str2 = temp + str2;
  }

  cout << (str1 == str2 ? "SI" : "NO");
  return 0;
}