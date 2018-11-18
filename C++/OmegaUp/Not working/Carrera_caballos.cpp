/*
  Descripción

  Todo está listo para la carrera de los dos caballos más famosos del mundo, pero el narrador se enfermó y no podrá asistir al evento. Afortunadamente, en la era de la información existen programas que leen lo que se les escribe con voces chistosas, pero el problema ahora es determinar qué texto darle al programa para que lo lea.

  Los organizadores del evento decidieron ponerles sensores de velocidad a los caballos para que la narración de la carrera pueda generarse con los datos entregados por los mismos. Tu labor será la de escribir un programa que lea la información de los sensores y genere la narración correspondiente.
  Entrada

  Un entero TT que es la duración en minutos de la carrera. Posteriormente TT parejas de enteros V1,V2V1,V2 que son las velocidades reportadas para los caballos 11 y 22 respectivamente a cada minuto de la carrera. Puedes suponer que 1≤T≤10001≤T≤1000 y que 0≤V1,V2≤100≤V1,V2≤10.
  Salida

  Cada vez que un caballo tome la delantera, se debe imprimir el mensaje "Al minuto mm el caballo cc toma la delantera" donde mm es el minuto tras el que ocurre el rebase y cc es el número del caballo que toma la delantera.

  Cada vez que el caballo que iba en segundo lugar alcance al que iba en primer lugar (sin rebasarlo), se debe imprimir el letrero "Al minuto mm los caballos van empatados" donde mm es el minuto tras el que ocurre el alcance.

  No se deben imprimir mensajes en los minutos en los que no ocurren cambios de posiciones (es decir, el caballo que iba ganando sigue ganando o bien, cuando los caballos iban empatados y siguen empatados). Cada mensaje debe imprimirse en su propia línea. Se considera que los caballos comienzan empatados.

  Al término de la carrera, se debe imprimir el mensaje "Termina la carrera y gana el caballo cc" donde cc es el número del caballo que ganó, o bien, el mensaje "Termina la carrera y empatan los caballos" si los caballos quedaron empatados.

  Posteriormente, se debe imprimir el mensaje "La distancia maxima entre los caballos fue de dd" donde dd es la magnitud de la distancia más grande que hubo entre los caballos durante la carrera.
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int minutes;
  int distanciaMax = 0;
  int ganando = 0;
  int avanceCaballo1 = 0;
  int avanceCaballo2 = 0;
  cin >> minutes;

  for (int i = 1; i <= minutes; ++i)
  {
    int tempAvance1, tempAvance2, tempGanando;
    cin >> tempAvance1;
    cin >> tempAvance2;

    avanceCaballo1 += tempAvance1;
    avanceCaballo2 += tempAvance2;

    if(avanceCaballo1 == avanceCaballo2)
      tempGanando = 0;
    else if(avanceCaballo1 > avanceCaballo2)
      tempGanando = 1;
    else
      tempGanando = 2;

    if(tempGanando != ganando) 
    {
      if(tempGanando == 0)
        cout << "Al minuto " << i << " los caballos van empatados";
      else if(tempGanando == 1)
        cout << "Al minuto " << i << " el caballo 1 toma la delantera";
      else
        cout << "Al minuto " << i << " el caballo 2 toma la delantera";
    }

    if(avanceCaballo1 - avanceCaballo2 > distanciaMax)
      distanciaMax = avanceCaballo1 - avanceCaballo2;
    else if(avanceCaballo2 - avanceCaballo1 > distanciaMax)
      distanciaMax = avanceCaballo2 - avanceCaballo1;

    ganando = tempGanando;
  }

  if(avanceCaballo1 == avanceCaballo2)
    cout << "Termina la carrera y empatan los caballos";
  else if(avanceCaballo1 > avanceCaballo2)
    cout << "Termina la carrera y gana el caballo 1";
  else
    cout << "Termina la carrera y gana el caballo 2";

  cout << "La distancia maxima entre los dos caballos fue de " << distanciaMax;

  return 0; 
}