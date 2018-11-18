/*
  Descripción

  Dada una cadena ss de caracteres, escribe un programa que responda correctamente si el caracter cc aparece en la subcadena de ss que empieza en la posición ii y tiene longitud tt.
  Entrada

  La cadena ss formada de caracteres alfanuméricos y de longitud a lo más 1,000,0001,000,000. Posteriormente un entero nn seguido de nn tripletas c,i,tc,i,t. Puedes suponer que 1≤n≤10,0001≤n≤10,000, que 0≤i<|s|0≤i<|s| y 1≤t≤|s|−i1≤t≤|s|−i.
  Salida

  Para cada pregunta, una línea con un 11 si el caracter aparece en la subcadena indicada y 00 en otro caso.
  Ejemplo

  Entrada Salida

  gatito
  3
  g 0 6
  g 1 5
  g 0 3

  1
  0
  1
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  string str = "";
  char character;
  cin >> str;
  // int length = 0;
  // while((character = cin.get()) != '\n')  
  // {
  //   length++;
  //   str += character;
  // }

  int n;
  cin >> n;
  for (int i = 0, j = 0; i < n; ++i)
  {
    int temp, temp2;
    cin >> character;
    cin >> temp;
    cin >> temp2;

    for (j = 0; j < temp2; ++j)
    {
      if(str[temp++] == character)
      {
        cout << 1 << endl;
        break;
      }
    }

    if(j == temp2)
      cout << 0 << endl;
  }  
  return 0;
}