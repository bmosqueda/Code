/*Ejercicio 10: Considerando una matriz de 5x5 llena con números, 
mostrar las coordenadas donde se encuentran los números mayor y menor.*/
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
	int mayor, mayorFila, mayorColum, menor, menorFila, menorColum;
	int matriz[5][5];
	llenarMatriz( matriz );
	cout << "Matriz generada" << endl;
	printMatriz( matriz );
	mayorFila = 0;
	mayorColum = 0;
	menorFila = 0;
	menorColum = 0;
	mayor = matriz[0][0];
	menor = matriz[0][0];

	for( int i = 0; i < 5; i++ )
	{
		for( j = 0; j < 5; j++ )
		{
			if( matriz[i][j] > mayor )
			{
				mayor = matriz[i][j];
				mayorFila = i;
				mayorColum = j;
			}
			if( matriz[i][j] < menor )
			{
				menor = matriz[i][j];
				menorFila = i;
				menorColum = j;
			}
		}
	}

	cout << "El mayor es: " << mayor << "  (" << mayorFila << "," << mayorColum << ")" << endl;
	cout << "El menor es: " << menor << "  (" << menorFila << "," << menorColum << ")" << endl;
}
