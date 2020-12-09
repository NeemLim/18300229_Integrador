// 18300229 - P 1.2 Programa de ordenación Método de Quick sort : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Luis Manuel Lim Pérez - 183000229 - Estructura de Datos.

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Integrador.h"
using namespace std;

class Sort //Sorting class.
{
private:
	double unsortedArray[150];

public:
	int mArraySize = 0;
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

	void swap(double* prevElement, double* nextElement) //Simple element exchange.
	{
		double tempAux = *prevElement;
		*prevElement = *nextElement;
		*nextElement = tempAux;
	}

	int arrayPartioner(double userArray[], int lower, int greater) //Puts pivot as well as smaller and bigger elements to their correcto position.
	{
		int pivot = userArray[greater];
		int i = (lower - 1);

		for (int j = lower; j <= greater - 1; j++)
		{
			if (userArray[j] < pivot)
			{
				i++;
				swap(&userArray[i], &userArray[j]);
			}
		}
		swap(&userArray[i + 1], &userArray[greater]);
		return (i + 1);
	}

	void sortArray(double userArray[], int start, int end) //Class method to sort array using an optimized quickSort method. Uses recursion and and aux method.
	{
		if (start < end)
		{
			for (int i = 0; i < mArraySize; i++)
			{
				cout << userArray[i] << "	";
			}
			int pi = arrayPartioner(userArray, start, end);

			sortArray(userArray, start, pi - 1);

			sortArray(userArray, pi + 1, end);
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

int quickSort()
{
	double userArray[150];
	char choice;
	Sort quickSort;

	cout << "========Welcome to the quick sort algorithm=========" << endl;
	quickSort.fillArray(userArray);
	quickSort.sortArray(userArray, 0, quickSort.mArraySize - 1);

	do //Loop to choose an operation.
	{
		cout << endl << "Choose type of numerical order:" << endl;
		cout << "[1] Ascending Order" << endl;
		cout << "[2] Descending Order" << endl;
		cout << ">Answer: "; choice = _getch();
		system("cls");
	} while (choice != '1' and choice != '2');

	quickSort.printArray(userArray, choice);

	cout << endl << endl << "\nThank you for using this program.";
	cout << endl;
	return 0;
}