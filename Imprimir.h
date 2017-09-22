#include <iostream>
using namespace std;
					//ojo, la matriz del sudoku solucion, osea "a", trabaja en posiciones normales de 1 hasta 9 (filas, columnas)
int Imprimir(int A[][9])			//se recibe la matriz 9x9 que contiene la solucion del sudoku y se posiciona pV en [1][1]
{
        ofstream salida("sudoku_solucion.txt");		//se crea el archivo en modo salida
        if(!salida)				//para comprobar que no hayan errores en el archivo
        {
                cerr<<"no se puede abrir el archivo (sudoku.txt)"<<endl;
                return -1;
        }
	for (int y=1; y<10; y++)		//se hacen 2 for anidados para imprimir la mastriz al archivo sudoku_solucion.txt
	{
		for (int x=1; x<10; x++)
		{
			salida<< A[y][x] << " ";
		}
		salida << endl;
	}
	salida.close();			//se cierra el archivo (siempre se hace cuando se utiliza archivos)
}
