/*
  URL:  https://omegaup.com/arena/problem/Calificaciones-recursivas#problems
  Original title:  Calificaciones recursivas
  
  Descripción

  En cierta escuela, la calificación final de los alumnos es el promedio entero de las calificaciones de sus evaluaciones parciales. Normalmente la calificación de una evaluación parcial se denota por un dígito del 00 al 99 (en esta escuela no ponen 1010 de calificación), pero ocasionalmente una evaluación parcial está dividida en subevaluaciones. Cuando esto ocurre, la calificación de la evaluación parcial es el promedio entero de sus subevaluaciones.

  Por si fuera poco, algunas subevaluaciones pueden estar divididas en subsubevaluaciones y así sucesivamente. Cuentas con una cadena que representa las calificaciones que obtuviste durante el año y quisieras calcular tu calificación final del curso. En esta cadena, un dígito es una calificación y un grupo de caracteres entre paréntesis denota que una calificación está dada por el promedio de las calificaciones del grupo. Por ejemplo, para la cadena (5955) tu promedio final es 66 mientras que para la cadena (5(95)5) primero se calcula el promedio del grupo interno, lo que resulta en (575), y luego se calcula el promedio final, el cual es 55.

  Escribe un programa que te ayude a calcular tu calificación final.
  Entrada

  Una cadena de a lo más 200,000200,000 caracteres, la cual consiste de dígitos y paréntesis balanceados. Puedes suponer que la cadena comienza y termina en paréntesis de apertura y cierre respectivamente y que ningún grupo de caracteres delimitados por paréntesis contiene una cantidad vacía de calificaciones.
  Salida

  Un entero que sea tu calificación final.
  Ejemplo

  Entrada Salida  Descripción

  (775(9(1111)999)7) | 6 | (775(9(1111)999)7) es equivalente a (775(91999)7), que es equivalente a (77577), que es equivalente a 6
*/
#include <iostream>
#include <string>
// #include "debug.h"

using namespace std;

int getMean(string grades, int* start, int lenght)
{
  int sum = 0;
  int gradesCount = 0;
  while(*start < lenght)
  {
    if(grades[*start] == '(')
    {
      (*start)++;
      sum += getMean(grades, start, lenght);
    }
    else if(grades[*start] == ')')
      return sum / gradesCount;
    else
      sum += (int)grades[*start] - 48;
    (*start)++;
    gradesCount++;
  }

  return sum / gradesCount;
}

int main(int argc, char const *argv[])
{
  int lenght = 0;
  int start = 1;
  // char grades[200000];
  string grades; 


  // while((grades[lenght] = cin.get()) != '\n')
  // { 
  //   lenght++;
  // }
  cin >> grades;

  cout << getMean(grades, &start, grades.size());
  return 0;
}