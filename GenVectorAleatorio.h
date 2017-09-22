#include <iostream>
using namespace std;

void GenVectorAleatorio(int *pV)		//se recibe al vector de las 36 posiciones y se posiciona pV en [0]
{
	int num;
	srand(time(NULL)); //No va a devolver siempre lo mismo, creo la semilla
	for(int i = 0; i<36; i++)	// desde 0 hasta 35 xq son 36 numeros
	{
		num = rand()%80;	//numero aleatorio entre [0, 80] que representan las posiciones del sudoku linealmente
		//Esta dentro del array el numero?

		for(int c = 0; c<i; c++)	//verifica los num que haya en el arreglo con el nuevo q viene
		{
			if(*(pV+c) == num)	//aqui los compara con el nuevo numero aleatorio
			{
				num = rand()%80;	//si entra al if crea otro numero aleatorio entre [0, 80]
				c = -1; //Empieza de nuevo el for que contiene la variable c
			}
		}
		*(pV+i)=num;		//se guarda el numero aleatorio en el arreglo sin q este repetido
	}
}
