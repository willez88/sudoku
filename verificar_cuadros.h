#include <iostream>
using namespace std;

void verificarcuadro1(int *pm, int f, int c)	//se recibe a la matriz m y la fila y columna del num que se juega en ese instante de tiempo para comparar
{
	int band=0, band1=0, band2=0, *pc, *pc2;
	pc=pc2=pm;
	for(int i=0; i<3; i++)//el for esta acomodado para solo movernos en el cuadrito 1, por eso hay 3 for por funcion xq cada cuadro tiene 3 filas
	{									//se hace lo mismo con las otras funciones
		if(*(pc+0*9+i)==*(pc2+f*9+c)&&(band<=1))
			band++;
	}
	pc=pm;
	for(int j=0; j<3; j++)
	{
		if(*(pc+1*9+j)==*(pc2+f*9+c)&&(band1<=1))
			band1++;
	}
	pc=pm;
	for(int k=0; k<3; k++)
	{
		if(*(pc+2*9+k)==*(pc2+f*9+c)&&(band2<=1))
			band2++;
	}
	band=band+band1+band2;
	if(band>1)	//si la suma de las band es mayor a 1 significa que el num se repite xq las band se incrementan a 1 si se repite el num
		cout<<"El numero ya esta en la matriz 3*3 1"<<endl;
	else
		cout<<"El numero no esta en la matriz 3*3 1"<<endl;   //caso contrario significa que solo esta el num q se introdujo, por tanto no se repite
}									//el mismo procedimiento con los otros cuadros
void verificarcuadro2(int *pm, int f, int c)
{
	int band=0, band1=0, band2=0, *pc, *pc2;
	pc=pc2=pm;
	for(int i=3; i<6; i++)
	{
		if(*(pc+0*9+i)==*(pc2+f*9+c)&&(band<=1))
			band++;
	}
	pc=pm;
	for(int j=3; j<6; j++)
	{
		if(*(pc+1*9+j)==*(pc2+f*9+c)&&(band1<=1))
			band1++;
	}
	pc=pm;
	for(int k=3; k<6; k++)
	{
		if(*(pc+2*9+k)==*(pc2+f*9+c)&&(band2<=1))
			band2++;
	}
	band=band+band1+band2;
	if(band>1)
		cout<<"El numero ya esta en la matriz 3*3 2"<<endl;
	else
		cout<<"El numero no esta en la matriz 3*3 2"<<endl;
}
void verificarcuadro3(int *pm, int f, int c)
{
	int band=0, band1=0, band2=0, *pc, *pc2;
	pc=pc2=pm;
	for(int i=6; i<9; i++)
	{
		if(*(pc+0*9+i)==*(pc2+f*9+c)&&(band<=1))
			band++;
	}
	pc=pm;
	for(int j=6; j<9; j++)
	{
		if(*(pc+1*9+j)==*(pc2+f*9+c)&&(band1<=1))
			band1++;
	}
	pc=pm;
	for(int k=6; k<9; k++)
	{
		if(*(pc+2*9+k)==*(pc2+f*9+c)&&(band2<=1))
			band2++;
	}
	band=band+band1+band2;
	if(band>1)
		cout<<"El numero ya esta en la matriz 3*3 3"<<endl;
	else
		cout<<"El numero no esta en la matriz 3*3 3"<<endl;
}
void verificarcuadro4(int *pm, int f, int c)
{
	int band=0, band1=0, band2=0, *pc, *pc2;
	pc=pc2=pm;
	for(int i=27; i<30; i++)
	{
		if(*(pc+0*9+i)==*(pc2+f*9+c)&&(band<=1))
			band++;
	}
	pc=pm;
	for(int j=27; j<30; j++)
	{
		if(*(pc+1*9+j)==*(pc2+f*9+c)&&(band1<=1))
			band1++;
	}
	pc=pm;
	for(int k=27; k<30; k++)
	{
		if(*(pc+2*9+k)==*(pc2+f*9+c)&&(band2<=1))
			band2++;
	}
	band=band+band1+band2;
	if(band>1)
		cout<<"El numero ya esta en la matriz 3*3 4"<<endl;
	else
		cout<<"El numero no esta en la matriz 3*3 4"<<endl;
}
void verificarcuadro5(int *pm, int f, int c)
{
	int band=0, band1=0, band2=0, *pc, *pc2;
	pc=pc2=pm;
	for(int i=30; i<33; i++)
	{
		if(*(pc+0*9+i)==*(pc2+f*9+c)&&(band<=1))
			band++;
	}
	pc=pm;
	for(int j=30; j<33; j++)
	{
		if(*(pc+1*9+j)==*(pc2+f*9+c)&&(band1<=1))
			band1++;
	}
	pc=pm;
	for(int k=30; k<33; k++)
	{
		if(*(pc+2*9+k)==*(pc2+f*9+c)&&(band2<=1))
			band2++;
	}
	band=band+band1+band2;
	if(band>1)
		cout<<"El numero ya esta en la matriz 3*3 5"<<endl;
	else
		cout<<"El numero no esta en la matriz 3*3 5"<<endl;
}
void verificarcuadro6(int *pm, int f, int c)
{
	int band=0, band1=0, band2=0, *pc, *pc2;
	pc=pc2=pm;
	for(int i=33; i<36; i++)
	{
		if(*(pc+0*9+i)==*(pc2+f*9+c)&&(band<=1))
			band++;
	}
	pc=pm;
	for(int j=33; j<36; j++)
	{
		if(*(pc+1*9+j)==*(pc2+f*9+c)&&(band1<=1))
			band1++;
	}
	pc=pm;
	for(int k=33; k<36; k++)
	{
		if(*(pc+2*9+k)==*(pc2+f*9+c)&&(band2<=1))
			band2++;
	}
	band=band+band1+band2;
	if(band>1)
		cout<<"El numero ya esta en la matriz 3*3 6"<<endl;
	else
		cout<<"El numero no esta en la matriz 3*3 6"<<endl;
}
void verificarcuadro7(int *pm, int f, int c)
{
	int band=0, band1=0, band2=0, *pc, *pc2;
	pc=pc2=pm;
	for(int i=54; i<57; i++)
	{
		if(*(pc+0*9+i)==*(pc2+f*9+c)&&(band<=1))
			band++;
	}
	pc=pm;
	for(int j=54; j<57; j++)
	{
		if(*(pc+1*9+j)==*(pc2+f*9+c)&&(band1<=1))
			band1++;
	}
	pc=pm;
	for(int k=54; k<57; k++)
	{
		if(*(pc+2*9+k)==*(pc2+f*9+c)&&(band2<=1))
			band2++;
	}
	band=band+band1+band2;
	if(band>1)
		cout<<"El numero ya esta en la matriz 3*3 7"<<endl;
	else
		cout<<"El numero no esta en la matriz 3*3 7"<<endl;
}
void verificarcuadro8(int *pm, int f, int c)
{
	int band=0, band1=0, band2=0, *pc, *pc2;
	pc=pc2=pm;
	for(int i=57; i<60; i++)
	{
		if(*(pc+0*9+i)==*(pc2+f*9+c)&&(band<=1))
			band++;
	}
	pc=pm;
	for(int j=57; j<60; j++)
	{
		if(*(pc+1*9+j)==*(pc2+f*9+c)&&(band1<=1))
			band1++;
	}
	pc=pm;
	for(int k=57; k<60; k++)
	{
		if(*(pc+2*9+k)==*(pc2+f*9+c)&&(band2<=1))
			band2++;
	}
	band=band+band1+band2;
	if(band>1)
		cout<<"El numero ya esta en la matriz 3*3 8"<<endl;
	else
		cout<<"El numero no esta en la matriz 3*3 8"<<endl;
}
void verificarcuadro9(int *pm, int f, int c)
{
	int band=0, band1=0, band2=0, *pc, *pc2;
	pc=pc2=pm;
	for(int i=60; i<63; i++)
	{
		if(*(pc+0*9+i)==*(pc2+f*9+c)&&(band<=1))
			band++;
	}
	pc=pm;
	for(int j=60; j<63; j++)
	{
		if(*(pc+1*9+j)==*(pc2+f*9+c)&&(band1<=1))
			band1++;
	}
	pc=pm;
	for(int k=60; k<63; k++)
	{
		if(*(pc+2*9+k)==*(pc2+f*9+c)&&(band2<=1))
			band2++;
	}
	band=band+band1+band2;
	if(band>1)
		cout<<"El numero ya esta en la matriz 3*3 9"<<endl;
	else
		cout<<"El numero no esta en la matriz 3*3 9"<<endl;
}
