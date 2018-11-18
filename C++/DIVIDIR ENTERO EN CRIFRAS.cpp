//Programa que recibe un número de 3 cifras y lo separa en sus digitos individuales
#include<iostream>

using namespace std;

int main()
{
	int numero;
	cout << "Ingresa un número de 3 cifras: ";
	cin >> numero;

	int cifra1, cifra2, cifra3;


	cifra3 = numero % 100 % 10;		//Se saca el primer dígito del número ingresado
	numero = numero / 10;			//Con esta división se recorta el número original a dos cifras

	cifra2 = numero % 10;			//Se saca el segundo dígito del número y se almacena en cifra 3
	numero = numero / 10;			//Se recorta otra vez el número original de tal forma que nos queda el primer término nada más
	/* numero /= 10 representa lo mismo que la línea de arriba*/

	cifra1 = numero;	

	cout << cifra1 << "   " << cifra2 << "   " << cifra3 << endl;		//Se imprime cada número separado por tres espacios

	return 0;
}