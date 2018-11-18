/*
  Dados NN números enteros positivos, encuentra un subconjunto no vacío de ellos cuya suma sea múltiplo de NN. Los números no son necesariamente diferentes.
  Entrada

  La primera línea contiene NN, la cantidad de números. La segunda línea contiene los NN números aiai.
  Salida

  La primera línea debe indicar el tamaño del subconjunto. La siguiente línea debe contener los números del subconjunto, separados por un espacio.

  Eres libre de imprimir cualquier subconjunto. En caso de no haber solución, debes imprimir una única línea conteniendo el valor 00.

  5               Salida:   2         porque 2+8=102+8=10, múltiplo de 5.
  1 2 4 8 1                 2 8
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int elementsNo;
  cin >> elementsNo;
  int numbers[elementsNo];
  int subset[elementsNo];

  for (int i = 0; i < elementsNo; ++i)
  {
    cin >> numbers[i];  
  }


  for (int i = 0; i < elementsNo; ++i)
  {
    for (int j = i; j < elementsNo; ++j)
    {
      subset[i]
    }
  }
  return 0;
}