#include <iostream>
#include <cstdlib>
#include <cstdio>
#define TOPEN 3
#define TOPEM 4
#define TOPES 6
using namespace std;
void inicializa_matriz(int matriz[][TOPEM],int topen , int topem);
void carga_matriz(int matriz[][TOPEM],int topen, int topem);
void muestra_matriz(int matriz[][TOPEM],int topen, int topem);
void vector2_elementos(int valor, int vector2[], int& num, bool esta);
void encontrado(int matriz[][TOPEM],int valor , int topen , int topem, bool& esta);
void lee_vector2(int vector2[],int num);
int main(int argc, char *argv[]) {
	int PosVector = 0 , num = 0;
	bool esta ;
	int vector[TOPES]={2,34,23,12,8,45};
	int vector2[TOPES];
	int matriz[TOPEN][TOPEM];
	inicializa_matriz(matriz,TOPEN ,TOPEM);
	carga_matriz(matriz,TOPEN,TOPEM);
	muestra_matriz(matriz,TOPEN,TOPEM);
	//vector2_elementos(matriz, vector, vector2, TOPEN, TOPEM ,TOPES);
	while(PosVector < TOPES ){
		int valor = vector[PosVector];
		
		encontrado(matriz , valor , TOPEN , TOPEM, esta);
		vector2_elementos(valor,vector2, num, esta);
		//cout<<"esta : "<<esta <<" pos : " <<PosVector<<endl;
		PosVector ++;
	}
	lee_vector2(vector2,num);
	return 0;
}
void inicializa_matriz(int matriz[][TOPEM],int topen,int topem){
	for(int i = 0 ; i < topen ; i++){
		for(int j = 0 ; j < topem ; j++){
			matriz[i][j] = 0;
		}
	}
}

void carga_matriz(int matriz[][TOPEM],int topen, int topem){
	cout<<endl;
	cout<<"Ingrese valores de la matriz de ["<<topen<<"]["<<topem<<"]"<<endl;
	for(int i = 0 ; i < topen ; i++){
		for(int j = 0 ; j < topem ; j++){
			cout<<"["<<i<<"]"<<"["<<j<<"]"<<" ";
			cin >> matriz[i][j];
		}
		cout<<endl;
	}
}
void muestra_matriz(int matriz[][TOPEM],int topen, int topem){
	cout<<endl;
	cout<<"Se lee la matriz ["<<topen<<"]["<<topem<<"]"<<endl;
	for(int i = 0 ; i < topen ; i++){
		for(int j = 0 ; j < topem ; j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}
void encontrado(int matriz[][TOPEM],int valor , int topen , int topem, bool& esta){
	int i=0 , j=0 ; 
	esta = false;
	while(i < topen and !esta ){
		while(j < topem and !esta ){
			if(valor == matriz[i][j]){
				esta = true;
			}
			j++;
		}
		j = 0 ;
		i++;	
	}
}
void vector2_elementos(int valor, int vector2[], int& num, bool esta){
	if(!esta){
		vector2[num]=valor;
	    num++;
	}
    
}
void lee_vector2(int vector2[],int num){
	cout<<"vector2 = [ ";
	for(int i = 0 ; i < num ; i++){
		cout<<vector2[i]<<",";
	}
	cout<<" ]";
}
