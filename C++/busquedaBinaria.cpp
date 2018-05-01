#include <iostream>
#include <cmath>
using namespace std;

int getPosition(int vector[1000], int num)
{
	int min = 0, max = 999;
	while(max > min)
	{
		int promedio = ceil((min + max)/(double)2);
		cout << "promedio: " << promedio << endl;

		if(vector[promedio] == num)
			return promedio;

		num > vector[promedio] ?  (min = promedio + 1) : (max = promedio - 1);
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int length = 1000;
	int vector[length];
	for (int i = 0; i < length; ++i)
		vector[i] = i + 1;

	int num = 500;
	cout << "Buscar un numero: "; cin >> num;
	cout << "POSITION: " << getPosition(vector, num);
	return 0;
}
