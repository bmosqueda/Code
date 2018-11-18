#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

bool isLetter(int chr) {
  return (chr >= 65 && chr <= 90) || (chr >= 97 && chr <= 122);
}

char convertUpperToLower(int chr) {
  if(chr >= 65 && chr <= 90)
    return (char)(chr + 32);
  return (char)chr;
}

char convertLowerToUpper(int chr) {
  if(chr >= 97 && chr <= 122)
    return (char)(chr - 32);
  return (char)chr;
}

void printArray(int v[], int length)
{
  for(int i = 0; i < length; i++)
    cout << v[i] << "  ";
  cout << endl;
}

void printArray(bool v[], int length)
{
  for(int i = 0; i < length; i++)
    cout << v[i] << "  ";
  cout << endl;
}

void printArray(char v[], int length)
{
  for(int i = 0; i < length; i++)
    cout << v[i];
}

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

  return v[a] == numberSearched ? a : -1;
}

/*struct Node
{
  int index = -1;
  Node *next = NULL;
  Node *last = NULL;
};*/ 

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
};

int greatestCommonDivisorRecursive(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return greatestCommonDivisorRecursive(b % a, a); 
} 


int greatestCommonDivisor(int a, int b)
{

  if(a==0 || b==0)
    return 1;

  int r = (a%b);

  while ( r < 0 || r > 0)
  {
    a = b;
    b = r;
    r = (a%b);
  }

  return b;
}
  
int lowestCommonMultiple(int a, int b) 
{ 
  return (a * b) / greatestCommonDivisor(a, b); 
} 

void SieveOfAtkin(bool sieve[], int limit) 
{ 
  sieve[2] = true;
  sieve[3] = true;

  /* 
    Mark siev[n] is true if one  
       of the following is true: 
    a) n = (4*x*x)+(y*y) has odd number of  
       solutions, i.e., there exist 
       odd number of distinct pairs (x, y)  
       that satisfy the equation and 
        n % 12 = 1 or n % 12 = 5. 
    b) n = (3*x*x)+(y*y) has odd number of  
       solutions and n % 12 = 7 
    c) n = (3*x*x)-(y*y) has odd number of  
       solutions, x > y and n % 12 = 11 
  */
  for (int x = 1; x * x < limit; x++) { 
    for (int y = 1; y * y < limit; y++) {           
      // Main part of Sieve of Atkin 
      int n = (4 * x * x) + (y * y); 
      if (n <= limit && (n % 12 == 1 || n % 12 == 5)) 
        sieve[n] ^= true; 

      n = (3 * x * x) + (y * y); 
      if (n <= limit && n % 12 == 7) 
        sieve[n] ^= true; 

      n = (3 * x * x) - (y * y); 
      if (x > y && n <= limit && n % 12 == 11) 
        sieve[n] ^= true; 
    } 
  } 
  
  // Mark all multiples of squares as non-prime 
  for (int r = 5; r * r < limit; r++) { 
    if (sieve[r]) { 
      for (int i = r * r; i < limit; i += r * r) 
        sieve[i] = false; 
    } 
  } 
}

void toBinary(int num)
{
  string binaryNum = "";
  for (int i = 0; i < 32; ++i)
  {
    binaryNum = (num % 2 == 1 ? "1" : "0") + binaryNum;

    num = num >> 1;
    
    if(num == 0)
      break;
  }

  cout << binaryNum << endl;
}

bool isPrime(int n) 
{
  if (n == 1) 
    return false;
  else if(n == 2)
    return true;
  else if(n % 2 == 0)
    return false;

  int i = 2;

  // This will loop from 2 to int(sqrt(x))
  while (i*i <= n) {
    // Check if i divides x without leaving a remainder
    if (n % i == 0) {
      // This means that n has a factor in between 2 and sqrt(n)
      // So it is not a prime number
      return false;
    }
    i += 1;
  }
  
  // If we did not find any factor in the above loop,
  // then n is a prime number
  return true;
}