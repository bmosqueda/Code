/*
  Se dice que aa es divisor de bb si existe un número entero cc tal que ac=bac=b.

  Por ejemplo 3 tiene solamente 2 divisores positivos: 1 y 3. Pero en cambio 12 tiene 6 divisores positivos: 1, 2, 3, 4, 6, y 12.
  Problema

  Dado NN, deberás encontrar el minimo número entero positivo con al menos NN divisores enteros positivos.
  Entrada

  un solo número entero NN.
  Salida

  El menor número entero positivo con al menos NN divisores enteros positivos.
  
  ejemplo     Salida  
  6             12
*/
#include <iostream>   
using namespace std;

int numeroDivosores(int num) {
  int divisoresNo = num != 1 ? 2 : 1;
  for (int i = num / 2; i > 1; --i)
  {
    if(num % i == 0)
      divisoresNo++;
  }

  return divisoresNo;
}

int main(int argc, char const *argv[])
{
  int num = 0;
  int i = 1;
  int N;
  cin >> N;

  while(num == 0) {
    if(numeroDivosores(i) == N)
      num = i;
    else
      i++;
  }

  cout << num;
  return 0;
}
