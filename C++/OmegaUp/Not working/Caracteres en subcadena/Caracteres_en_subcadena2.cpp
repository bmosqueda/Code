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

struct Node
{
  int index;
  Node *next;
  Node *last;
};  

void printArray(Node v[], int length)
{
  for(int i = 0; i < length; i++) 
  {
    cout << "i: " << i << "   ";
    if(v[i].index != -1)
    {
      cout << "v[i]: " << v[i].index << "   ";
      Node *temp = v[i].next;
      cout << "temp: " << temp << "   ";
      while(temp != NULL)
      { 
        cout << "node: " << (*temp).index << "   ";
        temp = (*temp).next;
      }
    }
    cout << endl;
  }
}

void printArrayIndexes(Node v[], int length)
{
  for(int i = 0; i < length; i++)
    cout << v[i].index << ",  ";
  cout << endl;
}

int main(int argc, char const *argv[])
{
  Node characters[122] = {};
  // cout << "characters[0].index: " << characters[0].index << endl << endl;
  // characters[0].next = &characters[1];
  // cout << (*characters[0].next).index << endl << endl;
  // printArray(characters, 122);
  char chr;
  int length = 0;
  while((chr = cin.get()) != '\n')  
  {
    if(characters[(int)chr].index != -1)
    {
      /*Insert new element*/
        if(characters[(int)chr].next == NULL)
        {
          characters[(int)chr].next = {length, NULL}; 
          characters[(int)chr].last = *characters[(int)chr].next; 

          cout << "length: " << length << endl;
          cout << "characters[(int)chr].next: " << characters[(int)chr].next << endl;
          cout << "characters[(int)chr].last: " << characters[(int)chr].last << endl;
          cout << endl;
        }
        else
        {
          Node node = {length, NULL};
          (*characters[(int)chr].last).next = &node;
          characters[(int)chr].last = &node;
        }
    } 
    else
    {
      characters[(int)chr].index = length;
      characters[(int)chr].next = NULL;
    }   

    length++;
  }

  printArrayIndexes(characters, 122);
  // printArray(characters, 122);

  cout << "characters[116].index: " << characters[116].index << endl;
  cout << "characters[116].next: " << characters[116].next << endl;
  cout << "(*characters[116].next).index: " << (*characters[116].next).index << endl;
  cout << "(*characters[116].next).next:" << (*characters[116].next).next << endl;
  cout << "(*(*characters[116].next).next).index:" << (*(*characters[116].next).next).index << endl;

 return 0;
}