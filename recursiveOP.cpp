// 18300229 - Tarea 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// Luis Manuel Lim Pérez - 183000229 - Estructura de Datos.

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Integrador.h"

using namespace std;
//Functions prototypes
int mult(int num1, int num2, int aux1, int aux2);
int div(int num1, int num2, int aux1, int aux2);

int recursiveOP()
{
	int num1 = 0,
		num2 = 0,
		aux1 = 0,
		aux2 = 0;
	char choice;

	do //Loop to choose an operation.
	{
		cout << "[1] Multiplication" << endl;
		cout << "[2] Divison" << endl;
		cout << ">Answer: "; choice = _getch();
		system("cls");

		if (choice == '1')
		{
			cout << "-Multiplicant: "; cin >> num1;
			cout << "-Multiplier: "; cin >> num2;
			aux2 = num1; //We define these values the same to use one of them as a no changing value for our constant additions.
			cout << ">Result = " << mult(num1, num2, aux1, aux2);
		}

		else if (choice == '2')
		{
			cout << "-Dividend: "; cin >> num1;
			cout << "-Divisor: "; cin >> num2;
			cout << ">Result = " << div(num1, num2, aux1, aux2);
		}
	} while (choice != '1' and choice != '2');

	cout << endl << endl;
	return 0;
}

//Multiplication function.
int mult(int num1, int num2, int aux1, int aux2)
{
	if (num1 == 0 || num2 == 0)
		return 0;

	//Base case
	aux1++;
	if (aux1 == num2)
		return aux2;

	//General cases
	aux2 += num1;
	mult(num1, num2, aux1, aux2);
}

//Division function.
int div(int num1, int num2, int aux1, int aux2)
{
	if (num1 == 0)
		return 0;
	else if (num2 == 0)
	{
		cout << endl << "***Undefined result, ignore the result below.***" << endl;
		return 0;
	}

	//Base cases
	if (aux2 > num1)
		return aux1 - 1; //minus 1 to compensate the last instance of addition.
	else if (aux2 == num1)
		return aux1;
	aux1++;

	//General cases
	aux2 += num2;
	div(num1, num2, aux1, aux2);
}