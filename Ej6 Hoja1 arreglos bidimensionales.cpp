//Ej6 Hoja1 arreglos bidimensionales


#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>


using namespace System;
using namespace std;


void GenerarMatriz(int** matriz, int& filas, int& columnas) {

	srand(time(NULL));

	for (int fila = 0; fila < filas; fila++) {

		for (int columna = 0; columna < columnas; columna++) {

			matriz[fila][columna] = rand() % 15 + 1;

		}

	}

}

void MostrarMatriz(int** matriz, int& filas, int& columnas) {



	for (int fila = 0; fila < filas; fila++) {

		for (int i = 0; i < 1; i++)
		{
			cout << "  ";
		}


		for (int columna = 0; columna < columnas; columna++) {

			if (matriz[fila][columna] < 10)

			{

				cout << matriz[fila][columna] << "  ";

			}

			else

			{

				cout << matriz[fila][columna] << " ";

			}

		}

		cout << endl;

	}

}



void IniciarMatrizCero(int** matriz, int& filas, int&columnas) {

	for (int fila = 0; fila < filas; fila++) {

		for (int columna = 0; columna < columnas; columna++) {

			matriz[fila][columna] = 0;

		}

	}

}



void GenerarTrianguloInferior(int** matriz, int& filas, int& columnas, int** trianguloInferior) {

	for (int fila = 1; fila < filas; fila++) {

		for (int columna = 0; columna < fila; columna++) {

			trianguloInferior[fila][columna] = matriz[fila][columna] + matriz[columna][fila];

		}

	}

}



int main()
{

	setlocale(LC_CTYPE, "spanish");

	int** matriz;

	int** TrianguloInferior;

	int n;

	do
	{
		cout << endl;
		cout << " Ingrese el tamaño de la matriz (n x n) : ";

		cin >> n;

	} while (n < 2 || n>50);

	cout << endl;

	int filas = n;

	int columnas = n;

	matriz = new int*[filas];

	for (int fila = 0; fila < filas; fila++)
	{
		matriz[fila] = new int[columnas];
	}



	TrianguloInferior = new int*[filas];

	for (int fila = 0; fila < filas; fila++)
	{
		TrianguloInferior[fila] = new int[columnas];
	}



	GenerarMatriz(matriz, filas, columnas);

	cout << " Matriz inicial: " << endl << endl;

	MostrarMatriz(matriz, filas, columnas);



	IniciarMatrizCero(TrianguloInferior, filas, columnas);



	GenerarTrianguloInferior(matriz, filas, columnas, TrianguloInferior);



	cout << endl;

	cout << " Matriz resultante: " << endl << endl;

	MostrarMatriz(TrianguloInferior, filas, columnas);


	cout << endl;
	cout << " " << system("pause");

	return 0;

}