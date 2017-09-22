#include <fstream>
#include <ctime>
#include <cmath>
#include <iostream>
#include <cstdlib>
//incluyo todos los .h en el programa principal que es el sudoku.cpp (en los .h estan definidas todas las funciones)
#include "mostrarsudoku.h"
#include "verificar_filas_columnas.h"
#include "verificar_cuadros.h"
#include "Imprimir.h"
#include "GenVectorAleatorio.h"
#include "Inicializar_sudoku.h"
#include "Ordenar_Vector.h"
using namespace std;

int a[9][9], b[9][9];

bool Verif_cuadros(int grupo)
{
	int posic, i;
	bool acepto;

	acepto= true;
	for (posic=1; posic<10; posic++)
	{
		for (i=1; i<posic; i++)
		{
			if (b[grupo][posic]==b[grupo][i])
			{
				acepto=false;
				goto sali;
			}
		}
	}
sali: return acepto;

}

void Mezclar()
{
	int restoX, restoY;
	int subir=0, t, x, y;
	float X, Y;
	int grupo, posic;
	bool repet, acepta;

	srand((unsigned)time(NULL));
	for (y=1; y<10; y++)
	{
		for (x=1; x<10; x++)
		{
			a[y][x]= (rand()%9) + 1;

			for (t=1; t<x; t++)
			{
				if (a[y][x]==a[y][t]) repet=true;
			}
			if (repet==false)
			{
				for (t=1; t<y; t++)
				{
						if (a[y][x]==a[t][x]) repet=true;
				}
			}

			if (repet==true)
			{
				repet=false;
				if (subir> 20)
				{
					subir= 0;
					x= 0;
				}
				else
				{
					subir++;
					x--;
				}
            		}
			else
			{
				restoY= y % 3;
				restoX= x % 3;
				if (restoX==0) restoX=3;
				if (restoY==0) restoY=3;
				Y= y; X= x;
				posic= 3*(restoY-1) + restoX;
				grupo= static_cast<int> (3*(ceil(Y/3)-1) + ceil(X/3));  //static_cast<char> para convertir float a int
				b[grupo][posic]= a[y][x];
				subir= 0;
			}
		}

		if ((y%3)==0)
		{
			for (grupo=y-2; grupo<=y; grupo++)
			{
				acepta= Verif_cuadros(grupo);
				if (acepta==false)
				{
					y= y-3;
					goto sali;
				}
			}
		}
sali:;
	}
}

int main()
{		//m: matriz llena de ceros, a matriz q contiene la solucion
	int m[9][9], vector[36], f, c, bandera=0, bandera2=0, pa, qa, H=0, p;
	bool continuar=true, juego=true, continuar2=true, seguir=true, seguir2=true;
	char opcion;
	Mezclar();		//Calcula la solucion del sudoku y la guarda en a
	//Procedimiento para variar las posiciones, calcula 36 num aleatorios sin repeticion
	GenVectorAleatorio(vector);
	//Funion Nueva!!!!!! Ordena los datos del vector de menor a mayor
	Ordenar_Vector(vector);
	//funcion nueva!!!!!!!!!!!
	Inicializar(&m[0][0], &a[1][1], vector);	//crea el juego del sudoku en la matriz m
	while(juego)
	{		//inicio del mientras principal
	cout << "\033[1;" << 35 << "m"<< "*************************************" <<"\033[0m" << endl;
	cout << "\033[1;" << 35 << "m"<< "*  1. Empezar el Juego.             *" <<"\033[0m" << endl;
	cout << "\033[1;" << 35 << "m"<< "*  2. Imprimir Solucion del Sudoku. *" <<"\033[0m" << endl;
	cout << "\033[1;" << 35 << "m"<< "*  3. Salir.                        *" <<"\033[0m" << endl;
	cout << "\033[1;" << 35 << "m"<< "*************************************" <<"\033[0m" << endl;
	cin>> p;
	switch(p)		//inicio del switch
	{
	//empieza el juego
	case 1: while(juego)
	{
		mostrarsudoku(&m[0][0], &a[1][1], vector);		//muestra el juego
		while(continuar)
		{
			cout<<"Especifique en que fila y que columna quiere poner el numero: ";
			cin>> f, cin>> c;
			f=f-1;
			c=c-1;		//condicion para que no se borren los numeros constantes del juego
			if((f>=0)&&(f<=8)&&(c>=0)&&(c<=8)&&((f*9+c)!=vector[0])&&((f*9+c)!=vector[1])&&((f*9+c)!=vector[2])&&((f*9+c)!=vector[3])&&((f*9+c)!=vector[4])&&((f*9+c)!=vector[5])&&((f*9+c)!=vector[6])&&((f*9+c)!=vector[7])&&((f*9+c)!=vector[8])&&((f*9+c)!=vector[9])&&((f*9+c)!=vector[10])&&((f*9+c)!=vector[11])&&((f*9+c)!=vector[12])&&((f*9+c)!=vector[13])&&((f*9+c)!=vector[14])&&((f*9+c)!=vector[15])&&((f*9+c)!=vector[16])&&((f*9+c)!=vector[17])&&((f*9+c)!=vector[18])&&((f*9+c)!=vector[19])&&((f*9+c)!=vector[20])&&((f*9+c)!=vector[21])&&((f*9+c)!=vector[22])&&((f*9+c)!=vector[23])&&((f*9+c)!=vector[24])&&((f*9+c)!=vector[25])&&((f*9+c)!=vector[26])&&((f*9+c)!=vector[27])&&((f*9+c)!=vector[28])&&((f*9+c)!=vector[29])&&((f*9+c)!=vector[30])&&((f*9+c)!=vector[31])&&((f*9+c)!=vector[32])&&((f*9+c)!=vector[33])&&((f*9+c)!=vector[35]))
				continuar=false;
		}
		while(seguir2)
		{
			cout<<"Ingrese el numero: ";
			cin>> m[f][c];
			if((m[f][c]>0)&&(m[f][c]<10))		//condicion para ingresar el numero corrente entre [1, 9]
				seguir2=false;
		}
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				if(m[i][j]!=0)
					bandera++;		//calcula la cantidad de num que tiene el sudoku
                                if(m[i][j]==0)
                                        bandera2++;		//calcula los espacios que estan vacios, osea ocupados por ceros (0)
			}
		}
                mostrarsudoku(&m[0][0], &a[1][1], vector);
		cout<<endl<<"Espacios Ocupados: "<<bandera<<endl; //Verifica si el sudoku se lleno correctamente
                cout<<"Espacios Vacios: "<<bandera2<<endl;        //Verifica los espacios no ocupados
		bandera=bandera2=0;				//los pongo en cero para volver a calcular bandera y bandera2
		//condiciones para solo calcular el cuadrito donde este el numero que se inserte en ese instante de tiempo
		if((f>=0)&&(f<=2)&&(c>=0)&&(c<=2))
			verificarcuadro1(&m[0][0], f, c);	//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna
		else
			if((f>=0)&&(f<=2)&&(c>=3)&&(c<=5))
				verificarcuadro2(&m[0][0], f, c);	//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna

		if((f>=0)&&(f<=2)&&(c>=6)&&(c<=8))
			verificarcuadro3(&m[0][0], f, c);	//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna
		else
			if((f>=3)&&(f<=5)&&(c>=0)&&(c<=2))
				verificarcuadro4(&m[0][0], f, c);	//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna

		if((f>=3)&&(f<=5)&&(c>=3)&&(c<=5))
			verificarcuadro5(&m[0][0], f, c);	//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna
		else
			if((f>=3)&&(f<=5)&&(c>=6)&&(c<=8))
				verificarcuadro6(&m[0][0], f, c);	//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna

		if((f>=6)&&(f<=8)&&(c>=0)&&(c<=2))
			verificarcuadro7(&m[0][0], f, c);	//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna
		else
			if((f>=6)&&(f<=8)&&(c>=3)&&(c<=5))
				verificarcuadro8(&m[0][0], f, c);	//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna

		if((f>=6)&&(f<=8)&&(c>=6)&&(c<=8))
			verificarcuadro9(&m[0][0], f, c);	//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna

		verificarfilas(&m[0][0], f, c);		//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna
		verificarcolumnas(&m[0][0], f, c);	//llamado de funcion: parametros por referencia, la matriz m, la fila, la columna

		cout<<endl<<"Desea borrar una celda s/n: ";
		cin>> opcion;
		if((opcion=='s')||(opcion=='S'))
		{
			while(continuar2)
			{
				cout<<"Especifique la fila y la columna: ";
				cin>> f, cin>> c;
				f=f-1;
				c=c-1;		//condicion para que no se borren los numeros constantes del juego
				if((f>=0)&&(f<=8)&&(c>=0)&&(c<=8)&&((f*9+c)!=vector[0])&&((f*9+c)!=vector[1])&&((f*9+c)!=vector[2])&&((f*9+c)!=vector[3])&&((f*9+c)!=vector[4])&&((f*9+c)!=vector[5])&&((f*9+c)!=vector[6])&&((f*9+c)!=vector[7])&&((f*9+c)!=vector[8])&&((f*9+c)!=vector[9])&&((f*9+c)!=vector[10])&&((f*9+c)!=vector[11])&&((f*9+c)!=vector[12])&&((f*9+c)!=vector[13])&&((f*9+c)!=vector[14])&&((f*9+c)!=vector[15])&&((f*9+c)!=vector[16])&&((f*9+c)!=vector[17])&&((f*9+c)!=vector[18])&&((f*9+c)!=vector[19])&&((f*9+c)!=vector[20])&&((f*9+c)!=vector[21])&&((f*9+c)!=vector[22])&&((f*9+c)!=vector[23])&&((f*9+c)!=vector[24])&&((f*9+c)!=vector[25])&&((f*9+c)!=vector[26])&&((f*9+c)!=vector[27])&&((f*9+c)!=vector[28])&&((f*9+c)!=vector[29])&&((f*9+c)!=vector[30])&&((f*9+c)!=vector[31])&&((f*9+c)!=vector[32])&&((f*9+c)!=vector[33])&&((f*9+c)!=vector[35]))
					continuar2=false;
				else
					cout<<"No Puedes Borrar Este Numero. "<<endl;
			}
			while(seguir)
			{
				cout<<"Ingrese 0 (Cero) para Borrar: ";
				cin>> m[f][c];
				if(m[f][c]==0)		//condicion para solo insertar el num 0
					seguir=false;
			}
		}

		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				if(m[i][j]!=0)
					bandera++;
                                if(m[i][j]==0)
                                        bandera2++;
			}
		}
		cout<<endl<<"Espacios Ocupados: "<<bandera<<endl; //Verifica si el sudoku se lleno correctamente
                cout<<"Espacios Vacios: "<<bandera2<<endl;        //Verifica los espacios no ocupados
		if(bandera==81)
		{
			pa=1, qa=1;
			for(int i=0; i<9; i++)
			{
				for(int j=0; j<9; j++)
				{
					if(m[i][j]==a[pa+i][qa+j])
                                                H++;
				}
			}
			if(H==81)	//si H es igual a 81 significa que el sudoku se llenó correctamente, por tanto has ganado
			{
                        	juego=false;
				cout<<endl<<"FELICIDADES HAS GANADO "<<endl;
			}
			else
				cout<<"Lleno el Sudoku Incorrectamente, Intentelo de nuevo."<<endl;
			cout<<endl<<"¿Desea ver la solucion? (s/n): ";
			cin>> opcion;
			if(opcion=='s' || opcion=='S')
				Imprimir(a);
			cout<<"¿Desea Inicializar el Juego? (s/n): ";		//para volver al principio del mismo juego
			cin>> opcion;
			if(opcion=='s' || opcion=='S')
				Inicializar(&m[0][0], &a[1][1], vector);
		}

		seguir2=seguir=continuar2=continuar=true;
		bandera2=bandera=0;		//los reinicio xq los vuelvo a usar
	}
	break;
	case 2: Imprimir(a);
	break;
	case 3: cout<<"Has Salido del Juego."<<endl;
		return 0;
	default: cout<<"Opcion Incorrecta. "<<endl;
	}		//fin del switch
	}		//fin del mientras principal
	return 0;
}			//fin del programa
