/*
  Alicia y las llaves doradas de las puertas
  Points  11.36   Memory limit  32MB
  Time limit (case)   1s  Time limit (total)  60s
  Input limit (bytes)   10 KiB
  Descripción

  Después de su larga caída, Alicia quedó atrapada en el fondo del agujero del conejo. Afortunadamente no estaba totalmente oscuro y pudo ver que había muchas puertas (todas cerradas) y una mesa con varias llaves doradas. Seguramente alguna llave abriría alguna de estas puertas, así que Alicia lo intentó y pronto descubrió que las chapas de las puertas eran de diferentes tamaños y que estaban ordenadas en fila, de la más pequeña a la más grande. Cada llave sólo abriría la chapa del mismo tamaño. Como en verdad eran muchas puertas y muchas llaves, Alicia pensó que le tomaría mucho tiempo intentar abrir todas las puertas con las llaves correctas.
  Entrada

  Un entero MM seguido de los tamaños de las chapas P1,...,PMP1,...,PM. Posteriormente un entero NN seguido de los tamaños de las llaves L1,...,LNL1,...,LN. Puedes suponer que 1≤N,M≤100,0001≤N,M≤100,000, que los tamaños de las chapas son distintos con 1≤P1<P2<...<PM≤100,0001≤P1<P2<...<PM≤100,000 y que los tamaños de las llaves cumplen 1≤Li≤100,0001≤Li≤100,000 para toda 1≤i≤N1≤i≤N.
  Salida

  Para cada una de las NN llaves, el número de la puerta que puede ser abierta con esa llave o 00 si no corresponde con ninguna puerta.
*/
#include <iostream>
using namespace std;

int binarySearch(int v[], int lenght, int numberSearched) 
{ 
  int a = 0;
  lenght--;
  while(a < lenght)
  {
    if(v[(a + lenght) / 2] == numberSearched)
      return (a + lenght) / 2 + 1;
    else if(v[(a + lenght) / 2] < numberSearched)
      a = (a + lenght) / 2 + 1;
    else
      lenght = (a + lenght) / 2 - 1;
  }

  return v[a] == numberSearched ? a + 1 : -1;
}

int main(int argc, char const *argv[])
{
  int doorsNum;
  cin >> doorsNum;
  int doors[doorsNum];
  for (int i = 0; i < doorsNum; ++i)
    cin >> doors[i];

  int keysNum;
  cin >> keysNum;
  for (int i = 0; i < keysNum; ++i) 
  { 
    int temp;
    cin >> temp;
    int index = binarySearch(doors, doorsNum, temp);
    cout << (index != -1 ? index : 0) << " ";
  }

  return 0;
}