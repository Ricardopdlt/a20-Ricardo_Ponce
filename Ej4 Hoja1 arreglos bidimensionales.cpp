// Ej4 Hoja1 arreglos bidimensionales

#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace System;
using namespace std;

void GenerarMatriz(int** matriz, int& filas, int& columnas) {

	for (int fila = 0; fila < filas; fila++) {

		for (int columna = 0; columna < columnas; columna++) {

			matriz[fila][columna] = rand() % 20 + 1;

		}

	}

}



void MostrarMes(int& mes) {

	switch (mes) {

	case 0:

		cout << " Enero";

		break;

	case 1:

		cout << " Febrero";

		break;

	case 2:

		cout << " Marzo";

		break;

	case 3:

		cout << " Abril";

		break;

	case 4:

		cout << " Mayo";

		break;

	case 5:

		cout << " Junio";

		break;

	case 6:

		cout << " Julio";

		break;

	case 7:

		cout << " Agosto";

		break;

	case 8:

		cout << " Setiembre";

		break;

	case 9:

		cout << " Octubre";

		break;

	case 10:

		cout << " Noviembre";

		break;

	case 11:

		cout << " Diciembre";

		break;

	default:

		break;

	}

}



void MostrarMatriz(int** matriz, int& filas, int& columnas) {

	cout << "\t\t\t";

	for (int columna = 0; columna < columnas; columna++) {

		cout << "Agencia " << columna + 1 << "\t\t";

	}

	cout << endl;



	for (int fila = 0; fila < filas; fila++) {

		MostrarMes(fila);

		if (fila == 1 || fila == 8 || fila == 9 || fila == 10 || fila == 11)

		{
			cout << "\t\t";
		}
		else
		{
			cout << "\t\t\t";
		}

		for (int columna = 0; columna < columnas; columna++) {

			cout << matriz[fila][columna] << "\t\t\t";

		}

		cout << endl;

	}

}



int SumaAgencia(int** matriz, int& filas, int agencia) {

	int suma = 0;

	for (int fila = 0; fila < filas; fila++) {

		suma = suma + matriz[fila][agencia - 1];

	}

	return suma;

}



float PromedioMensualAgencias(int **matriz, int& columnas, int mes) {

	float promedio = 0.0;

	for (int columna = 0; columna < columnas; columna++) {

		promedio = promedio + matriz[mes - 1][columna];

	}

	return promedio / columnas;

}



void IniciarArrayCero(int* array, int tamanio) {

	for (int i = 0; i < tamanio; i++)

	{
		array[i] = 0;
	}

}



void VentasAgencia(int** matriz, int& filas, int &columnas, int* ventasAgencias) {

	for (int columna = 0; columna < columnas; columna++) {

		for (int fila = 0; fila < filas; fila++) {

			ventasAgencias[columna] = ventasAgencias[columna] + matriz[fila][columna];

		}

	}

}



int MayorAgenciaVentas(int* ventasAgencias, int& columnas) {

	int agenciaMayor = -1;

	int mayor = -1;

	for (int i = 0; i < columnas; i++) {

		if (ventasAgencias[i] > mayor) {

			mayor = ventasAgencias[i];

			agenciaMayor = i;

		}

	}

	return agenciaMayor;

}



void VentasMensuales(int** matriz, int& filas, int &columnas, int* ventasMensuales) {

	for (int fila = 0; fila < filas; fila++) {

		for (int columna = 0; columna < columnas; columna++) {

			ventasMensuales[fila] = ventasMensuales[fila] + matriz[fila][columna];

		}

	}

}



int MenorMesVentas(int* VentasMensuales, int& filas) {

	int mesMenor = -1;

	int menor = 1000000;

	for (int fila = 0; fila < filas; fila++) {

		if (VentasMensuales[fila] < menor) {

			menor = VentasMensuales[fila];

			mesMenor = fila;

		}

	}

	return mesMenor;

}



int main()

{

	Console::SetWindowSize(140, 36);

	int** matriz;

	int filas = 12;
	int columnas = 5;
	int *ventasAgencias;
	int *ventasMensuales;
	int menorMes = -1;



	matriz = new int*[12];

	for (int fila = 0; fila < filas; fila++)

	{
		matriz[fila] = new int[columnas];
	}


	ventasAgencias = new int[columnas];

	ventasMensuales = new int[filas];


	IniciarArrayCero(ventasAgencias, columnas);

	IniciarArrayCero(ventasMensuales, filas);


	GenerarMatriz(matriz, filas, columnas);

	MostrarMatriz(matriz, filas, columnas);


	VentasAgencia(matriz, filas, columnas, ventasAgencias);

	VentasMensuales(matriz, filas, columnas, ventasMensuales);


	cout << endl;

	cout << " Las ventas anuales de la Agencia 3 es: " << SumaAgencia(matriz, filas, 3) << endl << endl;

	cout << " El promedio de ventas en el mes de Diciembre es: " << PromedioMensualAgencias(matriz, columnas, 12) << endl << endl;

	cout << " La agencia con mayor valor de ventas es: " << MayorAgenciaVentas(ventasAgencias, columnas) + 1 << endl << endl;

	cout << " Mes con menores ventas es: ";

	menorMes = MenorMesVentas(ventasMensuales, filas);

	MostrarMes(menorMes);

	cout << endl;




	cout << endl;
	cout << " " << system("pause");
}