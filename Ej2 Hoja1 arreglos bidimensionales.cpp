//Ej2 Hoja1 arreglos bidimensionales

#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace System;
using namespace std;


void HacerMatriz(int **Matriz, int n)
{
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << " Ingrese el valor de la matriz en la fila " << i + 1 << " ,columna " << j + 1 << " : ";
			cin >> Matriz[i][j];

		}

	}

	cout << endl;

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < 1; j++)
		{
			cout << "  ";

		}

		for (int j = 0; j < n; j++)
		{
			if (Matriz[i][j] < 10)
			{
				cout << Matriz[i][j] << "  ";
			}
			else
			{
				cout << Matriz[i][j] << " ";
			}

		}

		cout << endl;

	}

	cout << endl;


}

void Simetrica_o_No(int **Matriz, int n)
{
	int NoSimetrica = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Matriz[i][j] != Matriz[j][i])
			{
				NoSimetrica++;
			}
			
		}

	}

	if (NoSimetrica > 0)
	{
		cout << " La matriz no es simétrica \n";
	}
	else
	{
		cout << " La matriz sí es simétrica \n";
	}


}

int main()
{
	setlocale(LC_CTYPE, "spanish");

	int **Matriz;
	int n;

	cout << endl;

	do
	{
		cout << " Ingrese el tamaño de la matriz ( NOTA: Las filas son iguales a las columnas ) :  ";
		cin >> n;

	} while (n < 2);

	
	Matriz = new int *[n];
	for (int i = 0; i < n; i++)
	{
		Matriz[i] = new int[n];
	}

	HacerMatriz(Matriz, n);
	Simetrica_o_No(Matriz, n);

	for(int i = 0; i < n; i++)
	{
		delete[] Matriz[i];
	}

	delete[] Matriz;

	cout << endl;
	cout << " " << system("pause");
}