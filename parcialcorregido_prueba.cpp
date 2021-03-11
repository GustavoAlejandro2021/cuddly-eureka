#include <iostream>
#include <cstring>
using namespace std;
#define TOPESUC  8
#define TOPECOD  4
#define TOPEART 10 
#define TOPEDESC 26
#define TOPERUBRO 10
struct tyregped {
	char 	codart[TOPECOD];
	int    	suc;
	int    	cant;
};
struct tyart {
	char 	codart[TOPECOD];
	char 	descrart[TOPEDESC];
	float  	preart;
	int 	rubro;
};


void MuestraMatrizImporte(float matrizArtSuc[][TOPESUC],tyart vec_art[], int topeart , int topesuc);
bool condicion_fin(tyregped pedidos);
int fbuscarArticulo(tyregped pedidos, tyart vec_art[], int topeart);
void ingresar_ventas(tyregped& pedidos, tyart vec_art[],int topesuc,int topeart,int topecod, int& iart,int& isuc, int matstock[][TOPESUC],bool& rechazado);
void importe_total(float matrizArtSuc[][TOPESUC], tyregped pedidos ,tyart vec_art[], int iart , int isuc);
void sucursalSinPedidos(float matrizArtSuc[][TOPESUC],string vecsuc[],tyart vec_art[], int topeart , int topesuc);	
int main(int argc, char *argv[]) {

	tyart vec_art[TOPEART]={"p01","pendrive 16GB  ",45.5 ,1,"p02","mouse genius   ",65.3,2,"p03","cartucho las   ",200,3,"p04","parlantes sup  ",349.90,4,"p05","monitor led    "
	,2345.5,5,"p06","Disco rig 1Tb  ",1260,1,"p07","Disco 300Gb    ",4235,1,"p08","Impresora 344  ",849.99,6,"p09","pad tridim     ",165.9,2,"p10","teclado erg    ",459,2};
	tyart articulos;
	float matrizArtSuc[TOPEART][TOPESUC]={
									{0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0}};
	tyregped pedidos;
	
	int iart = 0 , isuc=0;
	int vector_rubro[TOPERUBRO];
	bool rechazado = false;
	bool pude = true;
	
	
	int	matstock[TOPEART][TOPESUC]={
							{3,2,0,7,0,0,2,0},
							{1,2,2,3,1,0,0,3},
							{0,3,0,1,1,0,2,1},
							{1,2,1,3,4,5,1,0},
							{3,1,0,2,0,1,0,3},
							{0,1,2,0,1,7,0,2},
							{4,1,1,0,1,0,0,1},
							{3,2,1,2,1,1,1,4},
							{0,1,2,3,0,0,1,2},
							{3,2,5,1,0,1,2,1}}; // Matriz de stock de artículos por sucursal
	
	string vecsuc[TOPESUC]={"Florida","Avellaneda","Wilde","Lanus","Olivos","Martinez","Pilar","Adrogue"}; 
	
	if(pude){
		
		MuestraMatrizImporte(matrizArtSuc,vec_art,TOPEART ,TOPESUC);
		ingresar_ventas(pedidos, vec_art,TOPESUC,TOPEART,TOPECOD,iart,isuc, matstock,rechazado);
		while(condicion_fin(pedidos)){
			
			vector_rubro[iart] ++; 
			if(!rechazado){
				importe_total(matrizArtSuc,pedidos ,vec_art, iart , isuc);
			}	
			cout<<endl<<"muestra matriz actualizada "<<endl;
			MuestraMatrizImporte(matrizArtSuc,vec_art,TOPEART ,TOPESUC);
			ingresar_ventas(pedidos, vec_art,TOPESUC, TOPEART,TOPECOD, iart,isuc, matstock,rechazado);
			
		}	
		
		
		
		ImporteTotal(matrizArtSuc,vec_art, TOPEART ,TOPESUC);
		//sucursalSinPedidos(matrizArtSuc,vecsuc, TOPEART , TOPESUC);
		
		//cout<<"El rubro con mayor cantidad de ventas es el número : "<<rubro_mayor_cantidad(vector_rubro, TOPERUBRO);
	}
	
	else{
		cout << "EL programa no puede seguir porque no se encontro el archivo articulos.dat "<<endl;
	
	}

	sucursalSinPedidos(matrizArtSuc,vecsuc,vec_art,TOPEART , TOPESUC);
	
	return 0;
}


void MuestraMatrizImporte(float matrizArtSuc[][TOPESUC],tyart vec_art[], int topeart , int topesuc){
	for(int i = 0 ; i < topeart ; i++){
		cout<<vec_art[i].descrart<<"      ";
		for(int j = 0 ; j < topesuc ; j++){
			cout<<matrizArtSuc[i][j]<<" ";
		}
		cout<<endl;
	}
}
void ingresar_ventas(tyregped& pedidos, tyart vec_art[],int topesuc,int topeart,int topecod, int& iart,int& isuc, int matstock[][TOPESUC],bool& rechazado){
		
	do{
			
		cout<<"Ingrese código del artículo "<<endl;
		cin.getline(pedidos.codart,topecod);
			
		iart = fbuscarArticulo(pedidos, vec_art , topeart);
			
	}while(iart == -1 and condicion_fin(pedidos));
	if(condicion_fin(pedidos)){
		do{
			cout<<"Ingrese número de sucursal .(Debe estar entre 0 y "<<topesuc<<endl;
			cin >> pedidos.suc;
			isuc = pedidos.suc;
		} while(!(pedidos.suc >= 0 and pedidos.suc < topesuc));
		do{
			cout<<"Ingrese cantidad "<<endl;
			cin >> pedidos.cant;
			if(matstock[iart][isuc] < pedidos.cant){
				cout<<"El pedido fue rechazado"<<endl;
				rechazado = true;
			}
			else{
				matstock[iart][isuc] = matstock[iart][isuc]-pedidos.cant;
			}
		} while(pedidos.cant <= 0);
		cin.ignore();
	}	
}
bool condicion_fin(tyregped pedidos){
	bool fin = true;
	string eti = pedidos.codart; 
	if(eti == "fin"){
		fin = false;
	}
	return fin;
}
int fbuscarArticulo(tyregped pedidos, tyart vec_art[], int topeart){
	int k = 0 ;
	string pedido = pedidos.codart;
	while(k < topeart and vec_art[k].codart != pedido){
		k++ ;
	}
	if(k == topeart){
		k = -1;
	}
	return k;
}		
void importe_total(float matrizArtSuc[][TOPESUC], tyregped pedidos ,tyart vec_art[], int iart , int isuc){
	float importe = vec_art[iart].preart * pedidos.cant;
	//
	matrizArtSuc[iart][isuc] += importe;
}
void sucursalSinPedidos(float matrizArtSuc[][TOPESUC],string vecsuc[],tyart vec_art[], int topeart , int topesuc){
	for(int j = 0 ; j < topesuc ; j++){
		cout<<"la sucursal : "<<vecsuc[j]<<" no vendio "<<endl;
		for(int i = 0 ; i < topeart ; i++){
			if(matrizArtSuc[i][j]==0){
				cout<<vec_art[i].descrart<<endl;
				
			}
		}
		cout<<endl;
		cin.get();
	}
}
	
