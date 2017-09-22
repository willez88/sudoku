#include <iostream>
#include <cstdlib>
using namespace std;

void mostrarsudoku(int *pm, int *pA, int *pV)	//se recibe a la matriz m y el resto de esta funcion se la saben
{
        int a=0, b=0, c=0, d=1, pI=0;
	cout << "\033[1;" << 35 << "m"<< "SUDOKU HECHO POR William Paez" <<"\033[0m" << endl;
	cout << "\033[1;" << 31 << "m"<< " 1   2   3     4   5   6     7   8   9 " <<"\033[0m" << endl;

	cout << "\033[1;" << 38 << "m"<< "-----------------------------------------" <<"\033[0m" << endl;
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			a++;
			if( (pI<36) && ((i*9+j) == *(pV + pI)) )
			{
				cout << "\033[1;" << 36 << "m" << "[" << *(pm+i*9+j) << "] " << "\033[0m";
				pI++;
			}
			else
				cout << "\033[1;" << 38 << "m" << "[" << *(pm+i*9+j) << "] " << "\033[0m";

			if(a==3)
			{
                                c=c+a;
				cout << "\033[1;" << 38 << "m"<< "| " <<"\033[0m";
				//cout<<"| ";
				a=0;
			}
                        if(c==9)
                        {
				cout << " " << "\033[1;" << 31 << "m"<< d++ <<"\033[0m";
                                //cout<<' '<<d++;
                                c=0;
                        }
		}
		cout<<endl;
		b++;
		if(b==3)
		{
			cout << "\033[1;" << 38 << "m"<< "-----------------------------------------" <<"\033[0m" << endl;
			b=0;
		}
	}
}	//se hacen trucos para poder mostrarla como uds saben
