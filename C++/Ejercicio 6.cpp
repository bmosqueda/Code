#include<iostream>
using namespace std;

void printMatriz( char matriz[5][5] )
{
	for( char i = 0; i < 5; i++ )
	{
		for( char j = 0; j < 5; j++ )
			cout << matriz[i][j] << "  ";

		cout << endl;
	}
		
}

int main()
{
	char diagonal[5];
	char matriz[5][5];

	for( char i = 0; i < 5; i++ )
	{
		for( char j = 0; j < 5; j++ )
		{
			int ingresado;
			cout << "Ingresa un numero: "; cin >> ingresado;
			matriz[i][j] = ingresado;
			if( j == i )
				diagonal[ j ] = ingresado;
		}
	}

	system("pause");
	system("cls");
	cout << "Matriz original" << endl << endl;

	printMatriz( matriz );

	//Cambiamos la diagonal
	int aux = matriz[0][0];
	matriz[0][0] = matriz[4][4];
	matriz[4][4] = aux;

	aux = matriz[1][1];
	matriz[1][1] = matriz[3][3];
	matriz[3][3] = aux;

	cout << endl << endl << "Matriz con la diagonal invertida" << endl;

	printMatriz( matriz );

}