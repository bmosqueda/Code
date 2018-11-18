/*Ejercicio 8: Generar una matriz de 5x5, 
el usuario la llena con números, una vez llena ordenarla de menor a mayor por filas.*/
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

void formaFacil()
{
	srand( time( 0 ) );
	int matriz[ 25 ];
	for( int i = 0; i < 25; i++ )
		matriz[ i ] = rand()% + 10;

	cout << "Matriz generada" << endl;
	for( int i = 1; i <= 25; i++ )
	{
		cout << matriz[i-1] << " ";
		if( i % 5 == 0 )
			cout << endl;
	}

	cout << endl << endl << endl <<"Matriz ordenada" << endl;
	//Se ordena
	for( int i = 0; i < 25; i++ )
	{
		for( int j = 0; j < 25 - 1; j++ )
		{
			if( matriz[j] > matriz[j+1] )
			{
				int aux = matriz[j];
				matriz[j] = matriz[ j + 1 ];
				matriz[ j + 1 ] = aux;
			}
		}
	}

	//Se imprime
	for( int i = 1; i <= 25; i++ )
	{
		cout << matriz[i] << " ";
		if( i % 5 == 0 )
			cout << endl;
	}
}

int main()
{
	int matriz[5][5];
	llenarMatriz( matriz );
	cout << "Matriz generada" << endl;
	printMatriz( matriz );
	//Ordenarla
	int fila = 0, colum = 0;
	for( int i = 0; i < 25; i++ )
	{
		for( int j = 0; j < 25; j++ )
		{
			if( colum < 4 )
			{
				if( matriz[fila][colum] > matriz[fila][colum + 1] )
				{
					int aux2 = matriz[fila][colum];
					matriz[fila][colum] = matriz[fila][colum+1];
					matriz[fila][colum + 1 ] = aux2;
				}
				colum++;
			}
			else
			{//colum == 4
				if( fila != 4)
				{
					if( matriz[fila][4] > matriz[fila + 1][ 0 ] )
					{
						int aux2 = matriz[fila][4];
						matriz[fila][4] = matriz[fila + 1][0];
						matriz[fila + 1][0] = aux2;
					}
					fila++;
					colum = 0;

				}
			}
		}
		colum = 0;
		fila = 0;
	}
	
	cout << endl << endl << "Matriz ordenada" << endl;
	printMatriz( matriz );
}
