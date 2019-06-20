//Ej3 Hoja1 arreglos bidimensionales

#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace System;
using namespace std;

void HacerMatriz(int **Matriz, int n, int m)
{
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
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

		for (int j = 0; j < m; j++)
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

void MatrizTranspuesta(int **Matriz, int n, int m)
{
	cout << endl;

	for (int j = 0; j < m; j++)
	{
		
	    for (int i = 0; i < 1; i++)
		{
			cout << "  ";

		}

		for (int i = 0; i < n; i++)
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

int main()
{
	setlocale(LC_CTYPE, "spanish");

	int n, m; // n = filas , m = columnas
	int **Matriz; //matriz

	cout << endl;
	do
	{
		cout << " Ingrese el número de filas de la matriz: ";
		cin >> n;

	} while (n <= 0 || n > 10);
	   
	do
	{
		cout << " Ingrese el número de columnas de la matriz: ";
		cin >> m;

	} while (m <= 0 || m > 10);


	Matriz = new int*[n];
	for (int i = 0; i < n; i++)
	{
		Matriz[i] = new int[m];
	}


	HacerMatriz(Matriz, n, m);
	MatrizTranspuesta(Matriz, n, m);


	for (int i = 0; i < n; i++)
	{
		delete[] Matriz[i];
	}

	delete[] Matriz;


	cout << endl;
	cout << " " << system("pause");

}