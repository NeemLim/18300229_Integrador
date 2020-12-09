// 18300229 -P1.2 Programa de Busqueda de datos: Método de busqueda Secuencial: Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Luis Manuel Lim Pérez - 183000229 - Estructura de Datos.

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Integrador.h"
using namespace std;

class Search //Searching class.
{
public:
	int mArraySize = 0;
	void fillArray(double userArray[]) //Class method to fill arrays.
	{
		cout << endl << "*** Press <Control Key> on your last the data input to finish filling. ***" << endl;
		cout << "Fill the array: " << endl;
		for (int i = 0; (GetAsyncKeyState(VK_CONTROL)) == false; i++)
		{
			mArraySize++;

			if ((GetAsyncKeyState(VK_CONTROL)) == false)
			{
				cout << "Element #" << i << ": ";
				cin >> userArray[i];
			}
			GetAsyncKeyState;
		}
	}

	int search(double userArray[], int arraySize, double findValue) //Finds the desired value.
	{
		int i = 0;
		for (i = 0; i < arraySize; i++)
		{
			if (userArray[i] == findValue)
				return i;
		}
		return -1;
	}

	void setPositions() //Method that numerates postions.
	{
		cout << "Position:	";
		for (int i = 0; i < mArraySize; i++)
		{
			cout << "#" << i << "	";
		}
		cout << endl;
	}
	void printArray(double userArray[]) //Prints Array in the desired order.
	{
		cout << endl << "=== Array === " << endl;
		setPositions();
		cout << "Value:		";
		for (int i = 0; i < mArraySize; i++)
		{
			cout << userArray[i] << "	";
		}
	}
};

int linearSearch()
{
	double userArray[150],
		findValue;
	char choice;
	Search binarySearch;

	cout << "========Welcome to the linear search algorithm=========" << endl;
	binarySearch.fillArray(userArray);

	system("cls");

	binarySearch.printArray(userArray);

	cout << endl << endl << ">Ingresa el elemento a buscar: ";
	cin >> findValue;

	cout << endl;
	int result = binarySearch.search(userArray, binarySearch.mArraySize - 1, findValue);
	(result == -1) ? cout << "--Value is not present in this array."
		: cout << "--Value found at position # " << result;

	cout << endl << endl << "\nThank you for using this program.";
	cout << endl;
	return 0;
}