#include <iostream>
using namespace std;

void Inicializar(int *pM, int *pA, int *pV)	//resive a la matriz m, a la matriz a y al vector
{
	for(int i=0; i<9; i++)		//estos for, llenan a la matriz m con ceros (0)
	{
		for(int j=0; j<9; j++)
			*(pM+i*9+j)=0;
	}

	for(int i=0; i<36; i++)
	{
		//Mete el numero de la matriz "a" en la matriz "m" con una posicion aleatoria que esta guardada en el vector
		*(pM + *(pV + i))= *(pA + *(pV + i));
	}
}
