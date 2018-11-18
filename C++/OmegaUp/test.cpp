#include <iostream>
#include "debug.h"
// #include <regex>
// #include <string>

using namespace std;

int main(int argc, char* argv[]) 
{
  int num[3] = {1, 2, 3};

  printArray(num, 3);

  num = {0};

  printArray(num, 3);
/*
  int y = 5;
  int *yPtr = &y;

  cout << "y: " << y << endl; 
  cout << "yPtr: " << yPtr << endl; 
  cout << "*yPtr: " << *yPtr << endl; 
  
  Node node = {1, NULL};
  Node node2 = {2, NULL};
  node.next = &node2;
  
  cout << "node: " << &node << endl; 
  cout << "node2: " << &node2 << endl; 
  cout << "node1.next: " << node.next << endl; 
  cout << "&node1.next: " << &node2.next << endl; 

  // Node *temp = v[i].next;
*/
  // Node *temp = new Node();
  // cout << "Temp: " << new Node() << endl;

  // char arr[15] = {'a', 'b', 'c'};
  // int* i;
  // int a = 5;

  // i = &a;

  // cout << "i: " << i << endl;
  // cout << "i*: " << *i << endl;
  // cout << "i&: " << &i << endl;
  // *i += 1;
  // cout << "i*: " << *i << endl;
  // cout << "a: " << a << endl;
}