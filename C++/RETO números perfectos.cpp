//RETO, encontrar los números perfectos entre 1 y 1000
#include<iostream>

using namespace std;

bool perfecto( int numero )		//Función que nos dice si un número es perfecto o no
{
	int sumaDivisores = 0;		//aquí guardaremos la suma de los números que identificamos como divisores del número que queremos saber si es perfecto

	for( int i = numero / 2; i > 0; i-- )		//El ciclo va desde la mitad de número hasta que sea 1, no es creciente pues se va restando al contador
	{
		if( numero % i == 0 )
		{
			sumaDivisores += i;			/*Si resulta que sí es divisor del número lo tenemos que agregar a la suma para hacer la comparación final y ver 
					
					0					si la suma de TODOS sus divisores es igual al número*/
		}		
	}

	if( numero == sumaDivisores )
		return true;
	else
		return false;

	//La línea anterior también podríamos haberla puesto como:
	//return numero == sumaDivisores;
}

int main()
{
	cout << "Los números perfectos que hay entre 1 y 1000 son: ";

	for( int i = 1; i <= 1000; i++ )		//Aquí se deja de ejecutar secuencialmente las instrucciones y va al código de la función cada vez que se le manda llamar
	{
		if( perfecto( i ) )		//La función se evalúa para todos los números entre 1 y 1000
		{
			cout << i << ", ";
		}
	}

	return 0;
}
