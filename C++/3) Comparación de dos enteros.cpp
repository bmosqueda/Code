//Comparación de dos números enteros
#include<iostream>

using namespace std;

int main()
{
	int numero1, numero2;

	cout << "Escriba dos enteros a comparar: ";
	cin >> numero1 >> numero2;			//Leemos los dos enteros del usuario, lee un número hasta que se presiona espacio o ENTER

	//Las llaves en el if no son necesaias cuando se va a ejectar sólo una línea de código después, si son más sí es necesario poner las llaves { }
	if( numero1 == numero2 )
		cout << numero1 << " = " << numero2 << endl;		//Si son iguales

	if( numero1 > numero2 )		//Las llaves en este if indican el cuerpo de la instrucción, todo el código que se encuetre en ellas se ejecutará si resuta verdadera
	{
		cout << numero1 << " > " << numero2 << endl;		//Si el primero es menor
	}

	if( numero1 < numero2 )
		cout << numero1 << " < " << numero2 << endl;		//Si el primero es menor

	if( numero1 != numero2 )
	{
		cout << numero1 << " != " << numero2 << endl;		//Si son diferentes
	}

	if( numero1 >= numero2 )
		cout << numero1 << " >= " << numero2 << endl;		//Si el primero es mayor o igual

	if( numero1 <= numero2 )
		cout << numero1 << " <= " << numero2 << endl;		//Si el primero es menor o igual

	return 0;
}
