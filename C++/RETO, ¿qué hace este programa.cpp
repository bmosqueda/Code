//RETO: ¿qué hace el siguiente programa
#include<iostream>

using namespace std;

int main()
{
	int x, y;

	cout << "Ingresa dos números: "; 
	cin >> x; 
	cin >> y;
	
	cout << endl << '\n';

	for( int i = 1; i <= x; i++ )
	{
		for( int j = 1; j <= y; j++ )
		{
			cout << '*';
		}
		cout << endl;
		
		system("pause");
		cout << endl;
	}

	return 0;
}
