/*
  Descripción

  EL maestro Melquiades quiere saber el promedio de calificaciones de su grupo, Por lo que tu como programador le ayudaras codificando un programita que le pida una cantidad de alumnos, y en seguida las calificaciones
  Entrada

  La cantidad de Alumnos y las "n" calificaciones en escala 0 al 100, sin decimales.
  Salida

  Mostrar el promedio con dos decimales.
  Ejemplo

  Entrada Salida  Descripción

  4
  50 100 100 50

  75.00

    

  Pedir la Cantidad de alumnos, y las "n" calificaciones. Mostrar el promedio con dos decimales.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
  int studentsNum;
  int grade;
  float mean = 0;

  cin >> studentsNum;

  for (int i = 0; i < studentsNum; ++i)
  {   
    scanf("%i", &grade);
    mean += grade;  
  }

  cout << fixed << setprecision(2) << (mean / (float)studentsNum);
  return 0;
}