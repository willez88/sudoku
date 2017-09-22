//Algoritmo para Ordenar de menor a mayor (usando el metodo de la burbuja) los numeros aleatorios del vector

void Ordenar_Vector(int *pV)
{
	int aux;
	for(int i=0; i<35; i++)
	{
		for(int j=i+1; j<36; j++)
		{
			if( *(pV + i) > *(pV + j) )
			{
				aux=*(pV + j);
				*(pV + j)= *(pV + i);
				*(pV + i)=aux;
			}
		}
	}
}
