// 18300229_Integrador.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include "Integrador.h"

using namespace std;

int main()
{
	char choice = 0;
	system("cls");
	cout << "========Simple Linked List=========" << endl;

	do //Loop until correct input
	{
		cout << endl << "Choose an option" << endl;
		cout << "[1] Add data to the collection." << endl;
		cout << "[2] Search value in the collection." << endl;
		cout << "[3] Show value according to element's position." << endl;
		cout << "[4] Show the elements' count." << endl;
		cout << "[5] Show all elements in the list." << endl;
		cout << "[6] Update data value." << endl;
		cout << "[7] Erase an element in the collection." << endl;
		cout << "[8] Delete everything" << endl;
		cout << "[9] Exit." << endl;
		cout << ">Answer: "; choice = _getch();
		system("cls");
	} while (choice < 49 or choice > 57); //ASCII from 1 to 9.

	//Sorting Algorithims
	bubbleSort();
	shellSort();
	quickSort();
	selectionSort();
	insertionSort();
	mergeSort();
	radixSort();

	//searching algorithms
	linearSearch();
	binarySearch();

	//recursive and pointers
	recursiveOP();
	searchStruct();

	//hash map
	hashMap();

	//linked lists
	singlyLinkedList();
	doubleLinkedList();
	circularLinkedList();
	doublyCircularList();
	fifoList();
	lifoList();

	//trees
	binarySearchTree();

	//graphs
	graphs();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file