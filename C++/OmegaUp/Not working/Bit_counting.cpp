/*
  URL: https://omegaup.com/arena/problem/bitcounting#problems
  Original title: Bit counting 
  Descripción:
  Definimos NiNi como un entero mayor que 0. Sea N1N1 la cantidad de unos de la representación binaria de N0N0 (por ejemplo, si N0N0 = 27 entonces N1N1 = 4). Análogamente NiNi es la cantidad de unos de la representación binaria de Ni−1Ni−1. Definimos KK como al mínimo valor de ii ≥ 0 tal que NiNi =1. Por ejemplo si N0N0 = 35 entonces N1N1 = 3, N2N2 = 2, N3N3 = 1 por lo tanto KK = 3. Dado un intervalo cerrado de números y un valor XX, encuentra cuántos números existen dentro de ese intervalo tal que su valor KK sea igual a XX.
  Entrada

  Tres enteros LO HI XX, el intervalo cerrado [LO,HI] y el valor XX.
  Salida

  La cantidad de numeros en el intervalo [LO,HI] tal que su KK es igual a XX.
  Ejemplo

  Entrada       Salida

  27 31 2         3

  1023 1025 1     1

  Límites
      0 ≤ XX ≤ 10
      1 ≤ LO ≤ HI ≤ 10^18
*/
#include <iostream>
// #include "debug.h"

using namespace std;
//Sirve pero es lento
int onesByIndex[45] = {};

// int onesInNumber(long long num)
// {
//   int ones = 0;
//   while(num != 0)  
//   {
//     if(num % 2 == 1)
//       ones++;

//     num = num >> 1;
//   }

//   return ones;
// }
// https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
// int onesInNumber(long long n) 
// { 
//     int count = 0; 
//     while(n != 0) 
//     { 
//       n &= (n-1); 
//       count++; 
//     } 
//     return count; 
// } 

int getK(int num, int k)
{
  if(num == 1)
    return k;

  if(k > 10)
    return -1;

  if(onesByIndex[num] == 0)
    onesByIndex[num] = __builtin_popcount(num);

  return getK(onesByIndex[num], k + 1);
}

int main(int argc, char const *argv[])
{
  long long lowerLimit;
  long long superiorLimit;
  short X;
  long long matches = 0;

  cin >> lowerLimit >> superiorLimit >> X;

  for (; lowerLimit <= superiorLimit; lowerLimit++)
  {          
    if(getK(__builtin_popcount(lowerLimit), 1) == X)
      matches++;
  }

  cout << matches;
  return 0;
}