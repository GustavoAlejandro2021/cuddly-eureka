#include <iostream>

using namespace std;



void pypart(int n)
	
{
	
	for (int i=0; i<n; i++)
		
	{
		
		for(int j=0; j<=i; j++ )
			
		{
			
			cout << " *";
			
		}
		
		cout << endl;
		
	}
	
	for (int i=n-1; i>0; i--)
		
	{
		
		for(int j=0; j<i; j++ )
			
		{
			
			cout << " *";
			
		}
		
		cout << endl;
		
	}
	
}



int main()
	
{
	
	cout << "\n";	
	int n = 10;
	pypart(n);
	return 0;
	
}


