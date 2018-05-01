//Paso de un arreglo como parámetro a una función de ordenamiento de todos sus elementos
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

/*Función que recibe como parámetro un arreglo desordenado y el número de elementos del arreglo*/
void ordenarArreglo( int arreglo[], int numeroElementos )		
{
	for( int i = 0; i < numeroElementos; i++ )		//Algoritmo de ordenamiento llamado "ordenamiento burbuja"
	{
		for( int j = 0; j < numeroElementos - 1-i; j++ )
		{
			if( arreglo[ j ] > arreglo[ j + 1 ] )
			{
				int aux = arreglo[ j ];
				arreglo[ j ] = arreglo[ j + 1 ];
				arreglo[ j + 1 ] = aux;
			}
		}
	}

	cout << "Arreglo ordenado: "; 
	for( int i = 0; i < numeroElementos; i++ )		//se imprime todo el arreglo ordenado
		cout << arreglo[ i ] << ", ";
}

int main()
{
	srand( time(0) );

	int numeroElementos;
	cout << "Ingresa el numero de elementos para el arreglo: ";
	cin >> numeroElementos;

	int vector[ numeroElementos ];
	
	cout << "Arreglo generado y desordenado: ";
	for( int i = 0; i < numeroElementos; i++ )
	{
		vector[ i ] = 50 + rand() % ( 151 - 50 );		//Se le asigna un numero aleatorio entre 50 y 150
		cout << vector[ i ] << ", ";		//Se imprime el valor que le acabamos de asignar 
	}

	cout << endl << endl << "Llamamos a la funcion de ordenamiento" << endl << endl;

	ordenarArreglo( vector, numeroElementos );

	return 0;
}
