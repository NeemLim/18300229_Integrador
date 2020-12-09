// 18300229 - P1.2 Programa de ordenación por el método de inserción: Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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
	void fillArray(double userArray[], bool sortAfter) //Class method to fill arrays.
	{
		double tempAux;
		int j = 0;
		cout << endl << "*** Press <Control Key> on your last the data input to finish filling. ***" << endl;
		cout << "*** Data input will automatically stop after 100 elements and requires at least 10 elements to stop. ***" << endl << endl;
		cout << "Fill the array: " << endl;
		for (int i = 0; (GetAsyncKeyState(VK_CONTROL)) == false and i < 100 or i < 10; i++)
		{
			j = i - 1;
			mArraySize++;

			if ((GetAsyncKeyState(VK_CONTROL)) == false)
			{
				cout << "Element #" << i << ": ";
				cin >> userArray[i];
				unsortedArray[i] = userArray[i];
				if (sortAfter == false)
				{
					tempAux = userArray[i];
					if (i > 0)
					{
						while (j >= 0 && userArray[j] > tempAux)
						{
							userArray[j + 1] = userArray[j];
							j--;
						}
					}
					userArray[j + 1] = tempAux;
				}
			}
			GetAsyncKeyState;
		}
	}

	void sortArray(double userArray[]) //Class method to sort array using an optimized insertion sort method.
	{
		int outer, inner;
		double key;
		for (outer = 1; outer < mArraySize; outer++)
		{
			key = userArray[outer];

			for (inner = outer - 1; inner >= 0 && userArray[inner] > key; inner--)
				userArray[inner + 1] = userArray[inner];

			userArray[inner + 1] = key;
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

int insertionSort()
{
	double userArray[150];
	char choice;
	Sort selectionSort;

	cout << "========Welcome to the insertion sort algorithm=========" << endl;

	do //Loop to choose an operation.
	{
		cout << endl << "Choose type of numerical order:" << endl;
		cout << "[1] Sort while input." << endl;
		cout << "[2] Sort after input." << endl;
		cout << ">Answer: "; choice = _getch();
		system("cls");
	} while (choice != '1' and choice != '2');

	if (choice == '1')
		selectionSort.fillArray(userArray, false);
	else
	{
		selectionSort.fillArray(userArray, true);
		selectionSort.sortArray(userArray);
	}

	choice = 0;

	do //Loop to choose an operation.
	{
		cout << endl << "Choose type of numerical order:" << endl;
		cout << "[1] Ascending Order" << endl;
		cout << "[2] Descending Order" << endl;
		cout << ">Answer: "; choice = _getch();
		system("cls");
	} while (choice != '1' and choice != '2');

	selectionSort.printArray(userArray, choice);

	cout << endl << endl << "\nThank you for using this program.";
	cout << endl;
	return 0;
}