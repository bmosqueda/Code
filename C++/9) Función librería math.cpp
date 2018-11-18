//Función e la librería cmath
#include<iostream>
#include<cmath>		//Librerpia que nos permite realizar operaciones matemáticas fácilmente con las funciones que cuenta

using namespace std;

int main()
{
	int base, exponente, resultado;

	cout << "Ingresa el número base: ";
	cin >> base;

	cout << "Ingresa el exponente: ";
	cin >> exponente;

	resultado = pow( base, exponente );		//pow( x, y )  es una función de la librería cmath que recibe como parámetro la base y el exponente, simepre dos parámetros

	cout << base << " a la " << exponente << " = " << resultado << endl;

	//También se podría haber puesto:
	//cout << base << " a la " << exponente << " = " << pow( base, exponente ) << endl;	
	//Nos hubiéramos ahorrado la variable resultado
}
