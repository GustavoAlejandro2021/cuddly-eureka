#include <iostream>
using namespace std;
int hallar_max(int *, int);
int main(int argc, char *argv[]) {
	const int elementos = 5;
	int vector[elementos] = {-1,33,-3,-5,-6};
	cout<<"El mayor elemento es : "<<hallar_max(vector,elementos);
	return 0;
}
int hallar_max(int *vec , int elementos){
	int max = *vec;
	for(int i = 0 ; i < elementos ; i++){
		if(*(vec+i) > max){
			max = *(vec + i);
		}
	}
	return max;
}
