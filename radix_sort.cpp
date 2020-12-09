// 18300229 - P 1.2 Programa de ordenación por el método de radix : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Luis Manuel Lim Pérez - 183000229 - Estructura de Datos.

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Integrador.h"
using namespace std;

class Sort //Sorting class.
{
private:

	int unsortedArray[150];
public:
	int mArraySize = 0;
	void fillArray(int userArray[]) //Class method to fill arrays.
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

	int maximumValue(int userArray[], int n) //Class method to get the maxium array value.
	{
		int maxValue = userArray[0];
		for (int i = 1; i < n; i++)
			if (userArray[i] > maxValue)
				maxValue = userArray[i];
		return maxValue;
	}

	void counterRadix(int userArray[], int n, int exp) //Class method to count array acording to the exponential digit.
	{
		int output[100];
		int iteration, count[10] = { 0 };

		for (iteration = 0; iteration < n; iteration++)
			count[(userArray[iteration] / exp) % 10]++;

		for (iteration = 1; iteration < 10; iteration++)
			count[iteration] += count[iteration - 1];

		for (iteration = n - 1; iteration >= 0; iteration--)
		{
			output[count[(userArray[iteration] / exp) % 10] - 1] = userArray[iteration];
			count[(userArray[iteration] / exp) % 10]--;
		}

		for (iteration = 0; iteration < n; iteration++)
			userArray[iteration] = output[iteration];
	}

	void sortArray(int userArray[], int n) // Class method to sort array using the radix sorting function.
	{
		int numDigits = maximumValue(userArray, n);

		for (int exp = 1; numDigits / exp > 0; exp *= 10)
		{
			counterRadix(userArray, n, exp);
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
	void printArray(int userArray[], char choice) //Prints Array in the desired order.
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

int radixSort()
{
	int userArray[150];
	char choice;
	Sort radixSort;

	cout << "========Welcome to the radix sort algorithm=========" << endl;
	radixSort.fillArray(userArray);
	radixSort.sortArray(userArray, radixSort.mArraySize);

	do //Loop to choose an operation.
	{
		cout << endl << "Choose type of numerical order:" << endl;
		cout << "[1] Ascending Order" << endl;
		cout << "[2] Descending Order" << endl;
		cout << ">Answer: "; choice = _getch();
		system("cls");
	} while (choice != '1' and choice != '2');

	radixSort.printArray(userArray, choice);

	cout << endl << endl << "\nThank you for using this program.";
	cout << endl;
	return 0;
}