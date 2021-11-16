#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<stdlib.h>
float Escalar;
int fila,columna,a,b;
#include"Matrices.hpp"
#include"Solucion.hpp"

int main(){
	cout<<"Hola este es la calculadora de Matrices"<<endl;
	cout<<"ingrese el tamaño de la matriz :"<<endl;
	cin>>fila;
	columna=fila;
	cout<<endl;
	cout<<"1)   si desea multiplicar la matriz por un escalar "<<endl;
	cout<<"2)   si desea sumar dos matrices "<<endl;
	cout<<"3)   si desea multiplicar dos matrices "<<endl;
	cout<<"4)   si desea reducir la matriz por medio de gauss jordan"<<endl;
	Matriz *ptrE1 = new Matriz(fila,columna);
	Matriz *ptrE2 = new Matriz(fila,columna);
	Matriz *ptrE3 = new Matriz(fila,columna);
	Matriz *Resul = new Matriz(fila,columna);
	cout<<endl;
	cin>>a;
	switch(a){
		case 1:
		       cin>>*ptrE1;
		       cout<<"ingrese el escalar que se desea multiplicar "<<endl;
		       cin>>Escalar;
		       cout<<"Este seria el resultado de la multiplicacion"<<endl;
		       *ptrE2=*ptrE1*Escalar; 
		       cout<<ptrE2;
		       return 0;
		    
		case 2:
			cout<<"ingrese 1 si desea sumar y 2 si desea restar "<<endl;
			cin>>b;
			   switch(b){
			        case 1:
			               cout<<"ingrese los elementos de la primera matriz"<<endl;
			               cin>>*ptrE1;
			               cout<<"ingrese los elementos de la segunda matriz"<<endl;
			               cin>>*ptrE2;
			               cout<<"el resultado de esta suma es "<<endl;
			               *ptrE3=*ptrE1+*ptrE2;
			               cout<<*ptrE3;
			               return 0;
			        case 2:
			               cout<<"ingrese los elementos de la primera matriz"<<endl;
			               cin>>*ptrE1;
			               cout<<"ingrese los elementos de la segunda matriz"<<endl;
			               cin>>*ptrE2;
			               cout<<"el resultado de esta resta es "<<endl;
			               *ptrE3=*ptrE1-*ptrE2;
			               cout<<*ptrE3;
			               return 0;
			   
			   }
			   
			   return 0;
		case 3:
			    cout<<"ingrese los elementos de la primera matriz"<<endl;
			    cin>>*ptrE1;
			    cout<<"ingrese los elementos de la segunda matriz"<<endl;
			    cin>>*ptrE2;
			    cout<<"el resultado de la multiplicacion  de las matrices es "<<endl;
	            *ptrE3=*ptrE1**ptrE2;
	            cout<<*ptrE3;
	            
	            return 0;
	            
		case 4:
			    cout<<"ingrese los elementos de la matriz y los resultados"<<endl;
			    columna=fila+1;
		        Solucion *gtrE1 = new Solucion(fila,columna);
		        cin>>*gtrE1;
		        cout<<endl;
			    gtrE1->Gaus();
			    return 0;
	}
	
	return 0;
}
