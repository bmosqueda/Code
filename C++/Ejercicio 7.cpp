/*7.	Generar 2 matrices de 3x3; el usuario llena las matrices con números, 
una vez llenas se muestra la matriz resultante de la suma de las mismas.*/
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void llenarMatriz( int matriz[3][3] )
{
	srand( time(0) );

	for( int i = 0; i < 3; i++ )
		for( int j = 0; j < 3; j++ )
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
	int matriz[3][3] = llenarMatriz( matriz );

	cout << "Matriz aleatoria" << endl;
	printMatriz( matriz );

	for( int i = 0; i < 3; i++ )
	{
		for( int j = 0; j < 3; j++ )
		{
			int ingresado;
			cout << "Ingresa un numero: "; cin >> ingresado;
			matriz[i][j] += ingresado;
		}	
	}

	cout << endl << endl << "Matriz sumada" << endl;

	printMatriz( matriz );
}
