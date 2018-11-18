//Declaración y llenado de un arreglo
#include<iostream>

using namespace std;

int main()
{/*
	int tamanioArreglo = 100;
	
	int arreglo[ tamanioArreglo ];		//Se declara el vector que tiene como tamaño el número que ingresó el usuario

	for( int i = 0; i < tamanioArreglo; i++ )		//Ciclo que va de 0 a tamaño menos (porque se empieza a contar desde el subíndice cero) uno para llenar el vector
	{
		int valor;
		cout << "Ingresa el valor para el arreglo en la posición " << i << ": ";
		cin >> valor;

		arreglo[ i ] = valor;		
	}

	cout << endl << "Los elementos del arreglo son: " << endl;

	for( int i = 0; i < tamanioArreglo; i++ )
		cout << "arreglo[ " << i << " ] = " << arreglo[ i ] << endl;

	
	Importar cstdlib y ctime para el siguiente ejemplo
	srand( time( null ) );
	
	int otroArreglo[ 10 ];

	for( int i = 0; i < 10; i++ )		//for usado para llenar TODOS los elementos del arreglo con números aleatorios
	{
		otroArreglo[ i ] = 1 + rand() % 1000;		//Se le agrega un número aleatorio entre 1 y 1000
	}

	for( int i = 0; i < 10; i++ )		//for que imprime el arreglo nuevo una vez que lo llenamos
	{
		cout << "otroArreglo[ " << i << " ] = " << otroArreglo[ i ] << endl;
	}
	*/

	//Otra forma de asignar valores a un arreglo es con una lista inicializadora
	int vector[ 10 ];		//Creamos un vector de diez elementos y lo inicalizamos con números del 1 al 6
													//los demás elementos del vector se inicializarán con ceros ya que no pusimos los diez números

	for( int i = 0; i < 10; i++ )		//for que imprime el arreglo inicializado con la lista
	{
		cout << "vector[ " << i << " ] = " << vector[ i ] << endl;
	}
	

	return 0;
}
