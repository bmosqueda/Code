/*
  CAJAS
  Descripción

  El encargado de "Empresa productora de cartón" decidió lanzar una línea nueva de cajas. La línea consiste en una colección de cajas cúbicas de diferentes tamaños. Como promoción de lanzamiento se hicieron paquetes de cajas de tal forma que al abrir una puedas encontrar otra y dentro de esta una más pequeña y así sucesivamente hasta abrir la caja más pequeña incluida en el paquete.

  De improviso llega un cliente a la fábrica pidiendo un paquete de lanzamiento; desafortunadamente todos los paquetes ya fueron enviados a las tiendas. Dado que tú eres el responsable de armarlos decides formar uno con el mayor número posible de cajas existentes en la fábrica
  Problema

  Hacer un programa que lea el tamaño de cada una de las cajas que hay en la fábrica y escriba el mayor número de cajas que puede tener el paquete. Dentro de una caja de tamaño TT Puedes meter otra de tamaño tt sólo sí t<Tt<T.
  Entrada

  En la primera línea de la entrada contendrá un solo número NN entero que indica cuantas cajas hay, en la siguiente línea el tamaño de cada caja separado por un espacio. La entrada la deberá leer del teclado.
  Salida

  Deberas imprimir el resultado en la pantalla.

  11
  1 2 3 8 5 7 9 6 10 11 4         Salida: 11

  1
  10    Salida: 1

  4
  2 2 2 2   Salida: 1

  5
  1 2 2 10 3  Salida: 4
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int boxesNo;
  int total = 1;
  int greatestIndex = 1;

  cin >> boxesNo;
  
  bool boxesSize[100001] = {false};

  for (int i = 0; i < boxesNo; ++i)
  {
    int temp;
    cin >> temp;

    boxesSize[temp] = true;
    if(temp > greatestIndex)
      greatestIndex = temp;
  }

  for (int i = 0; i < greatestIndex; ++i)
  {
    if(boxesSize[i])
      total++;
  }

  cout << total;
  return 0;
}