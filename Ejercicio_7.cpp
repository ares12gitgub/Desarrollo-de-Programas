#include <iostream>
using namespace std;
#include <string.h>

struct Cursos{
	string codigo;
	int cant_alumnos;
	int legajo;
	int notas[200];
	float aprobado;
	float desaprobado;
};
void Llenar(int c[]){
	for(int i=0; i<11; i++){
		c[i]=0;
	}
}
float PorcentajeA(int cont[],int cant){
	int suma=0;
	float porcentaje;
	for(int i=6; i<11; i++){
		if(cont[i]>=1){
			suma=suma+cont[i];
		}
	}
	porcentaje=suma/(float)cant;
	return porcentaje*100;
}
float PorcentajeD(int cont[],int cant){
	int suma=0;
	float porcentaje;
	for(int i=0; i<6; i++){
		if(cont[i]>=1){
			suma=suma+cont[i];
		}
	}
	porcentaje=suma/(float)cant;
	return porcentaje*100;	
}
void Informar_Cantidad__Nota(int nota[],string c,int cant,float& apr,float& desp){
	int cont[11];
	Llenar(cont);
	for(int i=0; i<cant; i++){
		switch (nota[i]){
			case 0:
				cont[0]++;
				break;
			case 1:
				cont[1]++;
				break;				
			case 2:
				cont[2]++;
				break;				
			case 3:
				cont[3]++;
				break;				
			case 4:
				cont[4]++;
				break;				
			case 5:
				cont[5]++;
				break;				
			case 6:
				cont[6]++;
				break;				
			case 7:
				cont[7]++;
				break;				
			case 8:
				cont[8]++;
				break;
			case 9:
				cont[9]++;
				break;								
			case 10:
				cont[10]++;
				break;
			default:
				cout << "Error" << endl;
				break;						
		}
		apr=PorcentajeA(cont,cant);
		desp=PorcentajeD(cont,cant);			
	}	
	cout << "El curso "<< c << " tuvieron esta cantidad de notas: " << endl;
	for	(int i=0; i<11; i++){
		if(i<10){
			cout << " " <<i << " Sacaron esta cantida " << cont[i] << endl;	
		}else{
			cout << i << " Sacaron esta cantida " << cont[i] << endl;
		}		
	}
}
//Funcion main
int main(int argc, char** argv) {
	int n,cont=0;
	string aux;
	do{
		if(cont !=0){
			cout << "Numero ingresado erroneo" << endl;
		}
		cont++;		
		cout <<"Ingrese cantidad de cursos" << endl;
		cin >> n;
	}while(n <= 0 || n > 20);
	struct Cursos p[n];
	for(int i=0; i<n; i++){
		do{
		cout << "Ingrese codigo de curso" << endl;
		cin >> aux;
			if(aux.length()>4 || aux.length()<4){
			cout << "Codigo ingresado incorrecto" << endl;
			}			
		}while(aux.length()>4 || aux.length()<4 );
		p[i].codigo=aux;
		do{
			cout << "Ingrese cantidad de alumnos" << endl;
			cin >> p[i].cant_alumnos;
			if(p[i].cant_alumnos>200){
				cout << "Capacidad maxima de aula, ingrese menos alumnos" << endl;
			}
		}while(p[i].cant_alumnos>200);	
		for(int j=0; j<p[i].cant_alumnos; j++){			
			cout << "Ingrese legajo" << endl;
			cin >> p[i].legajo;
			do{
				cout << "Ingrese nota" << endl;
				cin >> p[i].notas[j];
				if(p[i].notas[j] < 0 || p[i].notas[j] > 10){
					cout << "Nota ingresado incorrecta" << endl;
				}				
			}while(p[i].notas[j] < 0 || p[i].notas[j] > 10);
		}
		cout << "- - - - - - - - - - - " <<endl;
	}
	for(int i=0; i<n; i++){
		Informar_Cantidad__Nota(p[i].notas,p[i].codigo,p[i].cant_alumnos,p[i].aprobado,p[i].desaprobado);
		cout << "- - - - - - - - - - - " <<endl;
	}
	cout << "- - - - - - - - - - - " <<endl;
	for(int i=0; i<n; i++){
		if(p[i].aprobado+p[i].desaprobado<100){
			cout << "Error en sacar porcentaje" << endl;
		}else{
			cout << "El porcentaje de aprobados es: " << p[i].aprobado << " en el curso " << p[i].codigo << endl;
			cout << "El porcentaje de desaprobados es: " << p[i].desaprobado << " en el curso " << p[i].codigo << endl;			
		}
		cout << "- - - - - - - - - - - " <<endl;
	}
	return 0;
}


