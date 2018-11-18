/*
  Descripción

  ¡El COOI se ha vuelto loco!
  Problema

  Dada una cadena de caracteres, calcula cuantos "divisores" (sí, hablamos de divisores de matemáticas) tiene dicha cadena. Bien, el COOI (aún dentro de su cordura) ha decidido explicarte como se hace este procedimiento raro. Considera los siguientes puntos:

      Primero, necesitamos convertir la cadena en un numero xx, donde xx = suma de la representación numérica de los caracteres.
      La representación numérica de los caracteres está basada en el código ASCII (http://es.wikipedia.org/wiki/ASCII#Caracteres_imprimibles_ASCII), de tal modo que: A = 65, B = 66, C = 67 ... Z = 90.
      Una vez encontrado el valor de xx, simplemente debes imprimir cuantos divisores enteros tiene. Recuerda que un número aa es divisor de xx, si y solo si xx % aa = 0.

  -> Ver el ejemplo abajo para clarificar dudas.

  Nota: Para este problema las mayúsculas son indistintas de las minúsculas, es decir A = a.
  Entrada

  Una única linea con la cadena de caracteres, con solo letras mayúsculas y minúsculas. (a-z,A-Z)
  Salida

  Un entero indicando cuantos "divisores" tiene la cadena, siguiendo las especificaciones arriba mencionadas.

  Ejemplo     Salida
  HOLa          6

  La suma de la palabra es 292, pues:

  H = 72

  O = 79

  L = 76

  a = 65

  292, tiene 6 divisores: 1, 2, 4, 73, 146 y 292.
*/
#include <iostream> 
#include <cmath> 
using namespace std;

int countDivisors(int num) {
  int count = 0;
  int sqrtNum = (int) sqrt(num);
  for (int i = 1; i <= sqrtNum; ++i)
  {
    if(num % i == 0) 
    {
      if(num / i == i) 
        count++;
      else
        count += 2;
    }
  }

  return count;
}

int main()
{
  char character;
  int sumValues = 0;
  while((character = cin.get()) != '\n') 
  {
    if(character > 90)
      character -= 32;

    sumValues += character;
  }

  cout << countDivisors(sumValues) << endl;

  return 0;
}