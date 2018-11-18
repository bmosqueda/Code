#include <iostream>
using namespace std;

class Node
{
  public:
    int pos;
    Node *next;

  Node(int pos)
  {
    this->pos = pos;
    this->next = NULL;
  }

  Node()
  {
    this->pos = -1;
    this->next = NULL;
  }

  ~Node()
  {
    delete next;
  }
};

/*void printArray(Node v[], int length)
{
  for(int i = 0; i < length; i++)
    cout << v[i].pos << ",  ";
  cout << endl;
}*/


int main(int argc, char const *argv[])
{
  Node chars[122] = {};

  char chr;
  int i = 0;
  while((chr = cin.get()) != '\n') 
  {
    int index = (int)chr;
    if(chars[index].pos != -1)
    {
      delete chars[index].next;
      Node *tempNode = new Node(i);
      chars[index].next = tempNode;
    }
    else
    {
      chars[index].pos = i;
    }
    i++;
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    int start, end;
    cin >> chr;
    cin >> start;
    cin >> end;

    end += start - 1;

    if(chars[(int)chr].pos != -1)
    {
      if(chars[(int)chr].next == NULL)
      {
        // cout << endl << "Result: ";
        cout << (chars[(int)chr].pos >= start && chars[(int)chr].pos <= end ? 1 : 0);
      }  
      else
      {
        // cout << endl << "Result: ";
        if(
            (chars[(int)chr].pos >= start && chars[(int)chr].pos <= end) ||
            (chars[(int)chr].next->pos >= start && chars[(int)chr].next->pos <= end) ||
            (chars[(int)chr].pos <= start && chars[(int)chr].next->pos >= end) 
          )
          cout << 1;
        else
          cout << 0;
      }
    }
    else
      cout << 0;
  }  

  return 0;
}