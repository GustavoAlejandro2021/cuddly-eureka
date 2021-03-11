#include <iostream>
using namespace std;

int main()
{
	int vectornum[]={1,2,3,5,4,6,7};
	int i,j; 
	int flag=1;
	int comparaciones =0;
	int intercambios=0;
	for(i=0 ;i < 7-1&&flag==1;i++)                    // n-1 pasadas
	{
		flag=0;
		for(j=0 ; j < 7-1-i ; j++)           // burbujeo de datos
		{
			comparaciones++;
			if(vectornum[j] > vectornum[j+1]) // intercambio
			{
				flag=1;
				swap(vectornum[j],vectornum[j+1]);
				intercambios++;
			}
		}
	
	}
	cout<<"comparaciones : "<<comparaciones<<" intercambios : "<<intercambios<<endl;
    return 0;
}				


