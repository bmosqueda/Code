/*Ejercicio 5: 5.	El usuario llena un vector de 20 elementos con números entre el 0 y el 9;
 una vez lleno se debe mostrar la cantidad de números introducidos de cada uno. 
 Ejemplo 0-->1, 1-->4, 2-->0,3-->5…9-->5*/
#include<iostream>
using namespace std;

int main()
{
	int numeros[10] = {0};

	for( int i = 0; i < 20; i++ )
	{
		int ingresado;
		while( true )
		{
			cout << i + 1 << ".-Ingresa un numero entre 0 y 9: "; cin >> ingresado;
			if( ingresado >= 0 && ingresado <= 9 )
				break;
			else
				cout << "Escribe un numero dentro del rango" << endl;
		} 

		numeros[ ingresado ]++ ;
	}

	//Mostrarlo
	for( int i = 0; i < 10; i++ )
		cout << i << " --> " << numeros[i] << endl;
}