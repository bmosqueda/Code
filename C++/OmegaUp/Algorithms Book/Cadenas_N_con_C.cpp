/*
  URL: Problemas y algoritmos (pág. 61)
  Escribe un programa que dados dos números enteros n y c, imprima
  todas las cadenas de caracteres de longitud n que utilicen solamente
  las primeras c letras del abecedario (todas minúsculas), puedes 
  asumir que n < 20
*/
#include <iostream>
#include "debug.h"

using namespace std;

char C[21];

void cadenas(int 
  n, int c)
{
  int i;
  if(n == 0)
    printArray(C, 21);
  else
  {
    for (i = 'a'; i < 'a' + c; ++i)
    {
      C[n] = i;
      cadenas(n - 1, c);
    }
  }
}

int main(int argc, char const *argv[])
{
  cadenas(2, 3);
  return 0;
}