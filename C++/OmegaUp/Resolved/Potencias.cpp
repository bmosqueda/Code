/*
  La tarea a realizar es simple, recibirás un único entero nn, tendrás que calcular la suma de las potencias de 2 hasta 2n2n incluyendo 2020, e imprimirla.
  Entrada

  Un único entero no negativo nn.
  Salida

  La suma de las potencias de 2 desde 2020 hasta 2n2n.
  Ejemplo

  Entrada Salida  Descripción

  3

  15

  20+21+22+23=15
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  short exp;
  cin >> exp;
  int temp = 1; //2 to 0
  int result = 1;
  for (char i = 1; i <= exp; ++i)
  {
    temp *= 2;
    result += temp;
  }

  cout << result;
  return 0;
}