#include <iostream>
#include <cstring>
#define TOPE 23
using namespace std;
void ingreso(char &c1 , char &c2);
bool dosConsecutivos(char cadena[],int tope, char car1, char car2);
int main(int argc, char *argv[]) {
	char cadena[TOPE]="Esto es una de prueba";
	char car1 ;
	char car2;
	ingreso(car1, car2);
	if(dosConsecutivos(cadena,TOPE,car1,car2)){
		cout<< "estan";
	}
	else{
		cout<<"no estan";
	}
	
	return 0;
}

void ingreso(char &c1 , char &c2){
	cout<<"Ingrese un caracter ";
	cin >> c1;
	cout<<"Ingrese otro caracter";
	cin >> c2;
	
}
bool dosConsecutivos(char cadena[],int tope, char car1, char car2){
	int i=0;
	int longitud_cadena = strlen(cadena);
	bool encontre = false;
	while(i < tope  && i < longitud_cadena - 1 && !encontre){
		if(cadena[i]==car1 && cadena[i+1]==car2){
			encontre = true;
		}
		i++;
	}
	return encontre;
}
