  #include <iostream>
  using namespace std;

  int main(int argc, char const *argv[])
  {
    int N;
    cin >> N;
    if(N == 1)
    {
      int num; 
      cin >> num;
      cout << num << endl;
    }
    else if(N == 2)
    {
      int num, num2; 
      cin >> num;
      cin >> num2;
      if(num > num2)
        cout << num << endl;
      else
        cout << num2 << endl;
    }
    else
    {
      int points = 0;
      int numbers[N];
      for (int i = 0; i < N; ++i)
        cin >> numbers[i];

      int length = N - 3;
      int i = 0, j = N - 1, count = 0;
      for (; count < length; count++)
      {
        int index;
        if(numbers[j] > numbers[i])
        {
          if(numbers[j] >= numbers[j - 1])
          {
            index = j--;
          }
          else
          {
            int diff = numbers[i + 1] - numbers[i];
            int diff2 = numbers[j - 1] - numbers[j];
            if(diff < diff2)
            {
              index = i++;
            }
            else
            {
              index = j--;
            }
          }
        }
        else
        {
          if(numbers[i] >= numbers[i + 1])
          {
            index = i++;
          }
          else
          {
            int diff = numbers[i + 1] - numbers[i];
            int diff2 = numbers[j - 1] - numbers[j];
            if(diff < diff2)
            {
              index = i++;
            }
            else
            {
              index = j--;
            }
          }
        }

        if(count % 2 == 0) 
          points += numbers[index];
      }

      //Si N es par el turno es de él, sino el turno es mío
      if(N % 2 == 0) 
      {
        if(numbers[i] > numbers[j]) 
          i++;
        else 
          j--;

        if(numbers[i] > numbers[j]) 
        {
          points += numbers[i];
        }
        else 
        {
          points += numbers[j--];
        }
      }
      else
      {
        if(numbers[i] > numbers[j]) 
          points += numbers[i++];
        else 
          points += numbers[j--];


        if(numbers[i] > numbers[j]) 
        {
          points += numbers[j];
        }
        else 
        {
          points += numbers[i++];
        }
      }

      cout << points << endl;

    }
    return 0;
  }


/*
  10 
  1 8 8 9 1 2 7 3 1 13

  5
  96 96 68 22 38

  11
  67 42 4 86 2 37 91 15 27 97 50

  5
  1 6 5 9 4
*/