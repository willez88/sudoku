#include <iostream>
using namespace std;

void verificarfilas(int *pm, int f, int c)	//se recibe a la matriz m y la fila y columna del num que se juega en ese instante de tiempo para comparar
{
	int *pf, *pf2, band=0;
	pf=pf2=pm;
	for(int j=0; j<9; j++)
	{
		if(*(pf+f*9+j)==*(pf2+f*9+c)&&(band<=1))	//compara la fila completa con el num ingresado para saber si se repite
			band++;
	}
	if(band!=1)
		cout<<"El numero ya esta en la fila "<<endl;	//si band es diferente de 1 significa q el num se repite
	else
		cout<<"El numero no esta en la fila "<<endl;	// si band vale 1 significa q solo se encuentra el num que se ingreso, por tanto no se repite
}
void verificarcolumnas(int *pm, int f, int c)	//se recibe a la matriz m y la fila y columna del num que se juega en ese instante de tiempo para comparar
{
	int *pf, *pf2, band=0;
	pf=pf2=pm;
	for(int j=0; j<9; j++)
	{
		if(*(pf+j*9+c)==*(pf2+f*9+c)&&(band<=1))	//compara la columna completa con el num ingresado para saber si se repite
			band++;
	}
	if(band!=1)
		cout<<"El numero ya esta en la columna "<<endl;		//si band es diferente de 1 significa q el num se repite
	else
		cout<<"El numero no esta en la columna "<<endl;	 // si band vale 1 significa q solo se encuentra el num que se ingreso, por tanto no se repite
}
