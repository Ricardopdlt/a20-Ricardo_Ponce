//Ej5 Hoja 1 arreglos bidimensionales

#include<iostream>
#include <conio.h>
#include <stdio.h>
#include<time.h>
#include<cstdlib>

using namespace std;

void GenerarMatriz(int **matriz) {

	for (int i = 0; i < 4; i++)

	{

		for (int j = 0; j < 5; j++)

		{

			matriz[i][j] = rand() % 101;

		}

	}

}



void MostrarMesa(int mesa) {

	switch (mesa) {

	case 0:

		cout << " Mesa 1";

		break;

	case 1: 

		cout << " Mesa 2";

		break;

	case 2:

		cout << " Mesa 3";

		break;

	case 3:

		cout << " Mesa 4";

		break;

	default:

		break;

	}

}

void MostrarMatriz(int **matriz) {

	cout << "\t\t\t\t\t\t\tCANDIDATOS\n\n";

	cout << "\t\t";

	for (int j = 0; j < 5; j++)

	{

		cout << "Candidato " << j + 1 << "\t\t";

	}

	cout << endl;

	for (int i = 0; i < 4; i++)

	{

		MostrarMesa(i);

		cout << "\t\t";

		for (int j = 0; j < 5; j++)

		{

			cout<<matriz[i][j]<<"\t\t\t";

		}

		cout << endl;

	}

}

int SumaTotalVotosCandidato(int** matriz, int candidato) {

	int suma = 0;

	for (int i = 0; i < 4; i++) {

		suma = suma + matriz[i][candidato];

	}

	return suma;

}

int SumaVotosGeneral(int**matriz) {

	int suma1 =0;

	for (int i = 0; i < 4; i++)

	{

		for (int j = 0; j < 5; j++)

		{

			suma1 =suma1+ matriz[i][j];

		}

	}

	return suma1;

}

int main() {

	srand(time(NULL));

	setlocale(LC_CTYPE, "spanish");

	system("MODE 130,35");

	int **matriz;

	matriz = new int*[4];

	for (int i = 0; i < 4; i++)

	{

		matriz[i] = new int[5];

	}

	GenerarMatriz(matriz);

	MostrarMatriz(matriz);

	cout << endl;

	float Max = 0;
	int posi;
	int MasVotado;
	int aux;
	int Ganador = 0;

	float *SumVotosGeneral = new float[5];

	float *SumVotosCandidato = new float[5];

	float *PromedioVotosCadidato = new float[5];

	int posmayor1, posmayor2;

	int mayor1 = PromedioVotosCadidato[0], mayor2 = PromedioVotosCadidato[1];


	for (int i = 0; i < 5; i++)

	{

		SumVotosGeneral[i] = SumaVotosGeneral(matriz);

		SumVotosCandidato[i] = SumaTotalVotosCandidato(matriz, i);

		PromedioVotosCadidato[i] = SumVotosCandidato[i] / SumVotosGeneral[i] * 100;

		cout << " El candidato " << i + 1 << " obtuvo: " << SumVotosCandidato[i]<<" votos y obtuvo un "<< PromedioVotosCadidato[i]<<"%"<<endl;

		

		if (PromedioVotosCadidato[i]>Max)

		{

			Max = PromedioVotosCadidato[i];

			posi = i;

		}

	}

	for (int i = 0; i < 5; i++)

	{

		if (PromedioVotosCadidato[i] >= 50)

		{

			aux = 0;

			MasVotado = i;

		}

		else if (PromedioVotosCadidato[i] < 50)

		{

			aux = 1;

		}

		Ganador += aux;

	}

	for (int i = 0; i < 5; i++)

	{

		if (mayor1 < PromedioVotosCadidato[i])

		{

			mayor1 = PromedioVotosCadidato[i];

			posmayor1 = i;

		}

	}

	for (int i = 0; i < 5; i++)

	{

		if (mayor2 < PromedioVotosCadidato[i]&&posmayor1!=i)

		{

			mayor2 = PromedioVotosCadidato[i];

			posmayor2 = i;

		}

	}

	cout << endl<<" El candidato más votado es el " << posi + 1 << " con: " << Max << "%" << endl << endl;

	if (Ganador<5)

	{

		cout << " El candidato ganador es el: " << MasVotado +1 << endl << endl;

	}

	if (Ganador==5)

	{

		cout << " El candidato " << posmayor1+1 << " y el candidato " << posmayor2+1 << " irán a segunda vuelta" << endl << endl;

	}

	cout << " " << system("pause");

}