// 18300229 - P1.2 Programa Método de Burbuja : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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
		for (int i = 0; (GetAsyncKeyState(VK_CONTROL)) == false and i < 100; i++)
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

	void swap(double* prevElement, double* nextElement) //Simple element exchange.
	{
		double tempAux = *prevElement;
		*prevElement = *nextElement;
		*nextElement = tempAux;
	}

	void sortArray(double userArray[]) //Class method to sort array using an optimized bubble sort method.
	{
		int outer = 0,
			inner = 0;
		bool swapped;
		for (outer = 0; outer < mArraySize - 1; outer++)
		{
			swapped = false;

			for (inner = 0; inner < mArraySize - outer - 1; inner++)
			{
				if (userArray[inner] > userArray[inner + 1])
				{
					swap(&userArray[inner], &userArray[inner + 1]);
					swapped = true;
				}
			}
			for (int i = 0; i < mArraySize; i++)
			{
				cout << userArray[i] << "	";
			}
			cout << endl;

			// IF no two elements were swapped by inner loop, then break
			if (swapped == false)
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

int bubbleSort()
{
	double userArray[150];
	char choice;
	Sort bubbleSort;

	cout << "========Welcome to the bubble sort algorithm=========" << endl;
	bubbleSort.fillArray(userArray);
	bubbleSort.sortArray(userArray);

	do //Loop to choose an operation.
	{
		cout << endl << "Choose type of numerical order:" << endl;
		cout << "[1] Ascending Order" << endl;
		cout << "[2] Descending Order" << endl;
		cout << ">Answer: "; choice = _getch();
		system("cls");
	} while (choice != '1' and choice != '2');

	bubbleSort.printArray(userArray, choice);

	cout << endl << endl << "\nThank you for using this program.";
	cout << endl;
	return 0;
}