#include <iostream>
using namespace std;
//Funcion llenar vector de ceros
void Llenar(int rep[],int r){
	for(int i=0; i < r; i++){
		rep[i]=0;
	}
}
//Funcion ingresar tirada de dados y verificar que sean correctos
void TiradaDado(int d1[],int d2[],int n){
	for(int i=0; i < n; i++){
		cout << "Ingrese numero primer dado" << endl;
		cin >> d1[i];
		cout << "Ingrese numero segundo dado" << endl;
		cin >> d2[i];
		cout << endl;
		do{
			if (d1[i]<=0 || d2[i]<=0 || d1[i]>6 || d2[i]>6) {
				cout << "Tirada de dados ingresada incorrecta" << endl;
				cout << "Ingrese numero" << endl;
				cin >> d1[i];
				cout << "Ingrese numero" << endl;
				cin >> d2[i];
				cout << endl;
			}			
		}while(d1[i]<=0 || d2[i]<=0 || d1[i]>6 || d2[i]>6);
	}
}
//Funcion sacar suma dados y guardar repeticiones
void NumeroRepetido(int d1[],int d2[],int n,int rep[]){
	int suma;
	for(int i=0; i < n; i++){
		suma=d1[i]+d2[i];
		switch(suma){
			case 2:
				rep[0]++;
				break;
			case 3:
				rep[1]++;
				break;
			case 4:
				rep[2]++;
				break;
			case 5:
				rep[3]++;
				break;
			case 6:
				rep[4]++;
				break;
			case 7:
				rep[5]++;
				break;
			case 8:
				rep[6]++;
				break;
			case 9:
				rep[7]++;
				break;
			case 10:
				rep[8]++;
				break;
			case 11:
				rep[9]++;
				break;
			case 12:
				rep[10]++;
				break;
			default:
				cout << "Suma error" << endl;
				break;										
				
		}
	}
}
//Funcion mostrar repetidos
void MostrarRepetidos(int rep[],int r){
	int e=2;
	for (int i=0; i < r; i++){
		if (e<10){
		cout << e << "  Salio " << rep[i] << " veces" << endl;	
		}else{
			cout << e << " Salio " << rep[i] << " veces" << endl;
		}		
		e++;
	}
}
//Funcion main
int main(int argc, char** argv) {
	//Declaracion varaibles
	int n=50,r=11;
	int dado1[n],dado2[n],repetido[r];
	//Llamado a funciones
	Llenar(repetido,r);
	TiradaDado(dado1,dado2,n);
	NumeroRepetido(dado1,dado2,n,repetido);
	MostrarRepetidos(repetido,r);
	return 0;
}
