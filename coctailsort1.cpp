#include <iostream>
using namespace std;
void cocktailSort(int data[], int n);
int main()
{
	int data[]={354,74,98,154,45,92};
	
	int n = sizeof(data)/sizeof(data[0]);
	cout<<"secuencia ordenada ";
	cocktailSort(data,n);
	for(int i=0;i < n;i++)
	{
		cout<<data[i]<<" ";
	}
}		
void cocktailSort(int data[], int n)
{
	bool flag=true;
	int start=0;
	int end = n-1;
	while(flag)
	{
		flag=false;
		for(int i=start; i < end; i++)  
		{
			if(data[i]>data[i+1])
			{
				swap(data[i],data[i+1]);
				flag=true;
			}
		}
		if(!flag)
		{
			break;
		}
		flag=false;
		end --;
		for(int i=end - 1;i>=start;i--)
		{
			if(data[i]>data[i+1])
			{
				swap(data[i],data[i+1]);
				flag=true;
			}
		}
		start++;
	}
}

				
					
