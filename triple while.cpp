#include <iostream>

using namespace std;



int main(int argc, char *argv[]) {
	int m ;
	cout << "Ingrese numero entero ";
	cin >> m;
	cout << endl;
	while (m >0)
	{
		int n=1;
		while(n <= m)
		{
			cout << n <<" ";
			
			int z = 1;
			if(n == m)
			{
				while(z < m)
				{
					cout << m - z <<" ";
					z ++;
				}
			}
		    n ++;
		}
		
		cout<<endl;
		m--;
	}
	return 0;
}

