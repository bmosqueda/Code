/*
  Descripci?n

  Considera el siguiente juego entre dos personas. El juego consiste en una secuencia de nn enteros positivos. Los dos jugadores mueven en turnos alternados. A cada paso el jugador en turno selecciona el n?mero del extremo izquierdo o el del extremo derecho de la secuencia, dicho n?mero es entonces eliminado de la secuencia. El juego termina cuando todos los n?meros han sido eliminados. Cada uno de los dos jugadores desean maximizar su puntaje personal.

  Dado que el primer jugador siempre inicia el juego debes encontrar el m?ximo puntaje m?nimo que el primer jugador puede garantizar suponiendo que el segundo jugador juega ?ptimamente. En otras palabras, de todos lo puntajes m?nimos que el primer jugador puede garantizar debes encontrar el m?ximo.
  Entrada

  L?nea 1: El entero nn

  L?nea 2: nn enteros representando los n?meros en la secuencia del juego.
  Salida

  Un entero representando el m?ximo puntaje m?nimo que el primer jugador puede garantizar.
  Ejemplo

  Entrada               Salida:   35

  10 
  1 8 8 9 1 2 7 3 1 13
*/
#include <iostream>
using namespace std;

void printArray(int v[], int from, int to) {
  for (int i = from; i <= to; ++i)
    cout << v[i] << " ";
  cout << endl;
}

int main(int argc, char const *argv[])
{
  int N;
  int points = 0, against = 0;
  cin >> N;
  int numbers[N];
  for (int i = 0; i < N; ++i)
    cin >> numbers[i];

  int length = N - 3;
  int i, j, count;
  for (i = 0, j = N - 1, count = 0; count < length; count++)
  {
    int index;
    int isI;
    printArray(numbers, i, j);
    cout << "i: " << i << "   v:" << numbers[i] << endl;
    cout << "j: " << j << "   v:" << numbers[i] << endl;

    if(numbers[j] > numbers[i])
    {
      if(numbers[j] >= numbers[j - 1])
      {
        index = j--;
        isI = false;
      }
      else
      {
        int diff = numbers[i + 1] - numbers[i];
        int diff2 = numbers[j - 1] - numbers[j];
        if(diff < diff2)
        {
          index = i++;
          isI = true;    
        }
        else
        {
          index = j--;
          isI = false;
        }
      }
    }
    else
    {
      if(numbers[i] >= numbers[i + 1])
      {
        index = i++;
        isI = true;
      }
      else
      {
        int diff = numbers[i + 1] - numbers[i];
        int diff2 = numbers[j - 1] - numbers[j];
        if(diff < diff2)
        {
          index = i++;
          isI = true;    
        }
        else
        {
          index = j--;
          isI = false;
        }
      }
    }



    cout << "index: " << index << endl;
    cout << "indexValue: " << numbers[index] << endl;
    if(count % 2 == 0) {
      points += numbers[index];
      cout << "Points: " << points << endl;
    }
    else
      against += numbers[index];
    cout << "************************" << endl << endl;
  }

  //Si N es par el turno es de él, sino el turno es mío
  printArray(numbers, i, j);
  if(N % 2 == 0) 
  {
    if(numbers[i] > numbers[j]) 
      against += numbers[i++];
    else 
      against += numbers[j--];

    /*PRITN*/
      printArray(numbers, i, j);
    /*PRITN*/
    if(numbers[i] > numbers[j]) 
    {
      points += numbers[i];
      against += numbers[j];
    }
    else 
    {
      points += numbers[j--];
      against += numbers[i++];
    }
  }
  else
  {
    if(numbers[i] > numbers[j]) 
      points += numbers[i++];
    else 
      points += numbers[j--];

    /*PRITN*/
      printArray(numbers, i, j);
    /*PRITN*/

    if(numbers[i] > numbers[j]) 
    {
      against += numbers[i++];
      points += numbers[j];
    }
    else 
    {
      against += numbers[j--];
      points += numbers[i++];
    }
  }
  printArray(numbers, i, j);

  cout << "Points: " << points << endl;
  cout << "Against: " << against << endl;

  return 0;
}