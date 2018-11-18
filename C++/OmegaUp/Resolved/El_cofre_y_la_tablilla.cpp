/*
  ﻿# Descripción

  Según una antigua leyenda, la historia de Gilgamesh fue escrita en tablillas de lapizlázuli. En ellas están narradas todas las pruebas que sufrió Gilgamesh para volverse el más famoso de los reyes. Según la misma leyenda, las tablillas están guardadas en un cofre de cobre con un cerrojo de bronce. El cofre está guardado en un templo de Uruk, pero en el mismo templo hay muchos cofres. Por alguna razón sabes las dimensiones A×B×CA×B×C de una tablilla y deseas saber si ésta cabe en el cofre de dimensiones X×Y×ZX×Y×Z que tienes frente a ti.
  Entrada

  Seis enteros AA, BB, CC, XX, YY, ZZ. Puedes suponer que 1≤A,B,C,X,Y,Z≤10001≤A,B,C,X,Y,Z≤1000.
  Salida

  El entero 11 si la tablilla cabe dentro del cofre o 00 en caso contrario.
  Ejemplo

  Entrada Salida

  3 4 6 6 3 5

  1

  3 4 6 5 2 7

  0
*/
#include <iostream>
#include <string>
using namespace std;

void bubbleSort(int array[], int start, int end);

int main(int argc, char* argv[]) 
{
  int lenght = 6;
  int array[lenght] = {};  

  for (int i = 0; i < lenght; ++i)
  {
    cin >> array[i];
  }

  bubbleSort(array, 0, 3);
  bubbleSort(array, 3, 3);

  if(array[0] > array[3] or array[1] > array[4] or array[2] > array[5])
    cout << 0;
  else
    cout << 1;
  return 0;
}

void bubbleSort(int arr[], int start, int lenght)
{
  lenght = start + lenght;
  for (int i = start, count = 0; i < lenght - 1; i++, count++) 
  {
    for (int j = start; j < lenght - count - 1; j++) 
    {
      if (arr[j] > arr[j + 1]) 
      {
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}