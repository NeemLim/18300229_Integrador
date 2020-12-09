// 18300229 -P 1.2 Programa de ordenación por el metodo de Merge : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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

	void combine(double arr[], int l, int useMerge, int r) //This method prepares both left and right subarrys to be merged.
	{
		double L[150], R[150];
		int num1 = useMerge - l + 1;
		int num2 = r - useMerge;
		int indexSub1, indexSub2, indexSubMerge;

		for (indexSub1 = 0; indexSub1 < num1; indexSub1++)
			L[indexSub1] = arr[l + indexSub1];
		for (indexSub2 = 0; indexSub2 < num2; indexSub2++)
			R[indexSub2] = arr[useMerge + 1 + indexSub2];

		indexSub1 = 0;
		indexSub2 = 0;
		indexSubMerge = l;
		while (indexSub1 < num1 && indexSub2 < num2) {
			if (L[indexSub1] <= R[indexSub2]) {
				arr[indexSubMerge] = L[indexSub1];
				indexSub1++;
			}
			else {
				arr[indexSubMerge] = R[indexSub2];
				indexSub2++;
			}
			indexSubMerge++;
		}

		while (indexSub1 < num1) {
			arr[indexSubMerge] = L[indexSub1];
			indexSub1++;
			indexSubMerge++;
		}

		while (indexSub2 < num2) {
			arr[indexSubMerge] = R[indexSub2];
			indexSub2++;
			indexSubMerge++;
		}
	}

	void sortArray(double userArray[], int left, int right) //Method to sort the array using an optmized mergeSort function.
	{
		if (left < right) {
			int useMerge = left + (right - left) / 2;

			sortArray(userArray, left, useMerge);
			sortArray(userArray, useMerge + 1, right);

			combine(userArray, left, useMerge, right);
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

int mergeSort()
{
	double userArray[150];
	char choice;
	Sort mergeSort;

	cout << "========Welcome to the merge sort algorithm=========" << endl;
	mergeSort.fillArray(userArray);
	mergeSort.sortArray(userArray, 0, mergeSort.mArraySize - 1);

	do //Loop to choose an operation.
	{
		cout << endl << "Choose type of numerical order:" << endl;
		cout << "[1] Ascending Order" << endl;
		cout << "[2] Descending Order" << endl;
		cout << ">Answer: "; choice = _getch();
		system("cls");
	} while (choice != '1' and choice != '2');

	mergeSort.printArray(userArray, choice);

	cout << endl << endl << "\nThank you for using this program.";
	cout << endl;
	return 0;
}