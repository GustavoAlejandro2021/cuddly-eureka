#include <iostream>
#include <cstdlib>
using namespace std;

void pedirDatos();
void mostrarMatriz(int **,int,int);
int **puntero_matriz,nfilas,ncol;



int main()
{
    pedirDatos();	
	mostrarMatriz(puntero_matriz,nfilas,ncol);
	
	for(int i=0;i<nfilas;i++)
	{
		delete[] puntero_matriz[i];
	}
	delete[] puntero_matriz;
	return 0;
}	

void pedirDatos()
{
	cout<<"ingrese el numero de filas : ";
	cin>>nfilas;
	cout<<"ingrese numero de columnas : ";
	cin>>ncol;
	
	puntero_matriz=new int*[nfilas];
	for(int i=0;i<nfilas;i++)
	{
		puntero_matriz[i]=new int[ncol];
	}
	cout<<"\n digitando elementos de la matriz :"<<endl;
	for(int i=0;i<nfilas;i++)
	{
		for(int j=0;j<ncol;j++)
		{
			cout<<"digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz+i)+j);
		}
	}
}
			
void mostrarMatriz(int **puntero_matriz,int nfilas, int ncol)
{
	cout<<"\n\nimprimiendo matriz : \n";
	for(int i=0;i<nfilas;i++)
	{
		for(int j=0;j<ncol;j++)
		{
			cout<<*(*(puntero_matriz+i)+j);
		}
		cout<<"\n";		
	}
}	
	
		
	
	
	
