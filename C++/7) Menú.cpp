//Menú de opciones
#include<iostream>
using namespace std;

int main()
{
	int opcion = 0;

	do      //Inicio del ciclo, se ejecutará por lo menos una vez
	{	
		cout << "Presiona:\n1) Para imprimir un saludo\n2) Para imprimir una despedida\n0)Para Salir" << endl;
		cin >> opcion;
		
		if( opcion == 1 )
		{
			cout << "Hola :D" << endl;
		}
		else if( opcion == 2 )
			cout << "Adiós" << endl;
		else if( opcion == 0 )
			cout << "Decidiste Salir" << endl;
		else
			cout << opcion << " no es una opción válida, intenta de nuevo" << endl;


		//system( "pause" );
		system( "cls" );

	} while( opcion != 0 );		//Si no presionó cero significa que no deseó salir y se vuelve a repetir
}
