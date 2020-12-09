// 18300229 - P1.2 Programa de Ordenación por el método de Shell: Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Luis Manuel Lim Pérez - 183000229 - Estructura de Datos.

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Integrador.h"
using namespace std;

class Sort //Sorting class.
{
private:
	int mArraySize = 0;
	double unsortedArray[150];
public:
	void fillArray(double userArray[]) //Class method to fill arrays.
	{
		cout << endl << "*** Press <Control Key> on your last the data input to finish filling. ***" << endl;
		cout << "*** Data input will automatically stop after 100 elements and requires at least 10 elements to stop. ***" << endl << endl;
		cout << "Fill the array: " << endl;
		for (int i = 0; (GetAsyncKeyState(VK_CONTROL)) == false and i < 100 or i < 10; i++)
		{
			mArraySize++;

			if ((GetAsyncKeyState(VK_CONTROL)) == false)
			{
				cout << "Element #" << i << ": ";
				cin >> userArray[i];
				unsortedArray[i] = userArray[i];
			}
			GetAsyncKeyState;
		}
	}

	void sortArray(double userArray[]) //Class method to sort array using an optimized shell sort method.
	{
		for (int gap = mArraySize / 2; gap > 0; gap /= 2)
		{
			for (int outer = gap; outer < mArraySize; outer += 1)
			{
				double tempAux = userArray[outer];
				int inner;
				for (inner = outer; inner >= gap && userArray[inner - gap] > tempAux; inner -= gap)
					userArray[inner] = userArray[inner - gap];

				userArray[inner] = tempAux;
			}
			for (int i = 0; i < mArraySize; i++)
			{
				cout << userArray[i] << "	";
			}
			break;
		}
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
	void printArray(double userArray[], char choice) //Prints Array in the desired order.
	{
		cout << "=== Unsorted Array === " << endl;
		setPositions();
		cout << "Value:		";
		for (int i = 0; i < mArraySize; i++)
		{
			cout << unsortedArray[i] << "	";
		}

		cout << endl;

		cout << endl << "=== Sorted Array === " << endl;
		setPositions();
		cout << "Value:		";
		switch (choice)
		{
		case '1':
			for (int i = 0; i < mArraySize; i++)
			{
				cout << userArray[i] << "	";
			}
			break;
		case '2':
			for (int i = mArraySize - 1; i >= 0; i--)
			{
				cout << userArray[i] << "	";
			}
			break;
		}
	}
};

int shellSort()
{
	double userArray[150];
	char choice;
	Sort shellSort;

	cout << "========Welcome to the shell sort algorithm=========" << endl;
	shellSort.fillArray(userArray);
	shellSort.sortArray(userArray);

	do //Loop to choose an operation.
	{
		cout << endl << "Choose type of numerical order:" << endl;
		cout << "[1] Ascending Order" << endl;
		cout << "[2] Descending Order" << endl;
		cout << ">Answer: "; choice = _getch();
		system("cls");
	} while (choice != '1' and choice != '2');

	shellSort.printArray(userArray, choice);

	cout << endl << endl << "\nThank you for using this program.";
	cout << endl;
	return 0;
}