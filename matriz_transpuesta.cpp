#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int matriz[3][3];
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			cout << "Ingrese un número ["<<i<<"]["<<j<<"] : ";
			cin >> matriz[i][j];
		}
	}
	cout <<"Matriz original "<<endl;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			cout<<matriz[i][j];
		}
		cout<<endl;
	}
	cout<<"Matriz transpuesta "<<endl;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			cout<<matriz[j][i];
		}
		cout<<endl;
	}
	return 0;
}

