#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int chars[122][2];

  for (int i = 0; i < 122; ++i)
    for (int j = 0; j < 2; ++j)
      chars[i][j] = -1;

  char chr;
  int count = 0;
  while((chr = cin.get()) != '\n') 
  {
    int index = (int)chr;
    if(chars[index][0] != -1)
    {
      chars[index][1] = count;
    }
    else
    {
      chars[index][0] = count;
      chars[index][1] = count;
    }
    count++;
  }


    for (int i = 0; i < 122; ++i){
    for (int j = 0; j < 2; ++j)
      cout << chars[i][j] << " ";
    cout << endl;
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    int start, end;
    cin >> chr;
    cin >> start;
    cin >> end;
    end = start + end - 1;
    int index = (int)chr;

    if(chars[index][0] != -1)
    {
      if(chars[index][0] == chars[index][1])
      {
        cout << (chars[index][0] >= start && chars[index][0] <= end ? 1 : 0);
      }  
      else
      {
        if(
            (chars[index][0] >= start && chars[index][0] <= end) ||
            (chars[index][1] >= start && chars[index][1] <= end) ||
            (chars[index][0] <= start && chars[index][1] >= end) || 
            (start >= chars[index][0] && start <= chars[index][1]) ||
            (end >= chars[index][0] && end <= chars[index][1]) ||
            (start <= chars[index][0] && end >= chars[index][1]) 
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