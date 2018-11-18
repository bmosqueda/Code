/*
  URL: https://omegaup.com/arena/problem/patos#problems  
  Original title: Patos

  Descrípción:
  El señor Dengklek vive en el Reino de los Patos, donde humanos y patos viven juntos en paz y harmonía. Los patos estan numerados por números enteros positivos distintos de AA a BB, inclusive, donde AA ≤≤ BB.

  La última noche, el señor Dengklek no podía dormir, así que salió de su casa a intentar contar todos los patos en el reino. Cada vez que veía a un nuevo pato, decía su número en voz alta. El señor Dengklek sólo decía sus números (números que van de AA a BB). Nunca dijo el mismo número dos veces ni tampoco se tomó la molestia de decirlos en orden.

  Es posible que el señor Dengklek no haya visto a algunos patos. Obviamente, el número de patos que no vió depende de los valores de AA y BB. Los valores AA y BB son desconocidos para tí. Calcula el menor número de patos que el señor Dengklek se pudo haber perdido.
  Entrada

  Un entero positivo 1≤N≤501≤N≤50 con la cantidad de patos que el señor Dengklek vio. En la siguiente línea, habrá NN números, representando los números de los patos que fueron vistos. Cada número de pato es un entero entre el 1 y el 100, inclusive.

  Todos los números en la entrada son distintos.
  Salida

  Un entero representando el menor número de patos que el señor Denglklek se pudo haber perdido.

  Entrada Salida
  3
  5 3 2     1
*/
#include <iostream>
// #include "debug.h"

using namespace std;

int main(int argc, char const *argv[])
{
  short N, biggest = 0, minor = 101;
  cin >> N;

  for (int i = 0; i < N; ++i)
  {
    short temp;
    cin >> temp;

    if(temp < minor)
      minor = temp;
    if(temp > biggest)
      biggest = temp;
  }

  if(minor == biggest)
    minor = 1;

  // cout << "biggest: " << biggest << endl;
  // cout << "minor: " << minor << endl;

  // short elementsNo = biggest - minor + 1;
  cout << biggest - minor + 1 - N;
  return 0;
}