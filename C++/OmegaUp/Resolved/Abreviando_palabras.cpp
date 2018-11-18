/*
  URL:  https://omegaup.com/arena/problem/Abreviando-palabras#problems
  Original title:  Abreviando palabras

  Descripción

  Muchas veces varias palabras cómo "AnitaLavaLaTina" o "internacionalizar" son demasiadas largas como para escribirlo muchas veces en un solo texto y es algo cansado.

  Vamos a considerar una palabra muy larga, sí su tamaño es estrictamente mayor a 10 caracteres. Todas las palabras muy largas serán remplazadas con una abreviación especial.

  Una palabra se abrevia de tal forma: Escribimos la primera y la última letra de la palabra y entre ellas escribimos la cantidad de letras entre el primer y última letra. Tal número deberá estar en el sistema decimal y no debe iniciar con 0's.

  Entonces, la palabra "AnitaLavaLaTina" se debe de abreviar como "A13a", y "internacionalizar" como "i15r".

  Tu tarea es; Dada una palabra abreviarla si es necesario.
  Entrada

  En la primera línea un entero nn (1≤n≤100)(1≤n≤100), el tamaño de la palabra a procesar.

  En la segunda línea nn caracteres, representando la palabra a procesar.
  Salida
  Ejemplo

  Entrada Salida

  15 | AnitaLavaLaTina | A13a


  7 | palabra | palabra
*/
#include <iostream>
// #include "debug.h"

using namespace std;

int main(int argc, char const *argv[])
{
  int length;  
  cin >> length;
  char chr[length];
  int count = 0;

  for (int i = 0; i < length; ++i)
  {
    cin >> chr[i];  
    if(chr[i] != ' ')
      count++;
  }
  if(count > 10)
    cout << chr[0] << (length - 2) << chr[length - 1];
  else
    for (int i = 0; i < count; ++i)
      cout << chr[i];
  return 0;
}