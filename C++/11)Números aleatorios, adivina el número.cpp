//Números aleatorios, adivina el número
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{								//Si tuviera siempre la misma semilla siempre obtendríamos los mismos números y dejarían de ser aleatorios
	srand( time( 0 ) );		//Le aignamos la semilla a srand con relación al tiempo de la computadora (siempre será diferente)

	int numero = 1 + rand() % ( ( 1000 + 1 ) - 1 );		// 1 + rand() % 1000;	Se genera el número a adivinar
	int ingresado, intentos = 0;		//la varible ingresado leerá los números del usuario y la otra irá aumentando con cada intento que haga
	do
	{
		cout << "Estoy pensando en un número, adivina cuál es. Ingrésalo: " << endl;
		cin >> ingresado;

		if( numero != ingresado )			//Se pone primero esta condición porque es más probable que ocurra 
		{
			if( numero > ingresado )
			{
				cout << "Intenta con uno mayor" << endl;
			}
			else
			{
				cout << "Intenta con uno menor" << endl;
			}
			
			cout << "No, lo siento, ése no es el número. Intenta de nuevo :,v" << endl;
			intentos++;			//Se incrementa en uno el número de intentos
			system( "pause" );
			system( "cls" );
		}
		else
		{
			cout << "Genial, lo encontraste en " << intentos << " intentos " << endl;		//Cuando 
			break;
		}

	} while( numero != ingresado );
}
