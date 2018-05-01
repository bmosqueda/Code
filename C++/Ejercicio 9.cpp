//Ejercicio 9: Considerando una matriz de 5x5 llena, invertir las filas por las columnas
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void llenarMatriz( int matriz[5][5] )
{
	srand( time(0) );

	for( int i = 0; i < 5; i++ )
		for( int j = 0; j < 5; j++ )
			matriz[i][j] = rand()% + 10;
}

void printMatriz( int matriz[5][5] )
{
	for( int i = 0; i < 5; i++ )
	{
		for( int j = 0; j < 5; j++ )
			cout << matriz[i][j] << "  ";

		cout << endl;
	}	
}

int main()
{
	int matriz[5][5];
	llenarMatriz( matriz );

	cout << "Matriz generada aleatoria" << endl;
	printMatriz( matriz );

	cout << endl << endl << "Matriz con las columnas cambiadas por las filas" << endl;
	int newMatriz[5][5];
	for( int i = 0; i < 5; i++ )
	{
		for( int j = 0; j < 5; j++ )
		{
			newMatriz[j][i] = matriz[i][j];
		}
	}

	printMatriz( newMatriz );
}