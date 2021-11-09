#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<stdlib.h>
float Escalar;
int fila,columna,a;
#include"Matrices.hpp"

int main(){
	cout<<"Hola este es la calculadora de Matrices MxM"<<endl;
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
	cin>>a;
	switch(a){
		case 1:
		       ptrE1->ingresarM(0);
		       cout<<"ingrese el escalar que se desea multiplicar "<<endl;
		       cin>>Escalar;
		       cout<<"Este seria el resultado de la multiplicacion"<<endl;
		       ptrE1->MultiEs(Escalar);
		       
		       return 0;
		    
		case 2:
			   ptrE1->ingresarM(0);
			   ptrE2->ingresarM(fila+2);
			   cout<<"el resultado de esta suma es "<<endl;
			   ptrE3->suma(*ptrE1,*ptrE2);
			   
			   return 0;
		case 3:
			    ptrE1->ingresarM(0);
			    ptrE2->ingresarM(fila+2);
			    cout<<"el resultado de la multiplicacion  de las matrices es "<<endl;
	            ptrE3->Producto(*ptrE1,*ptrE2);
	            
	            return 0;
		case 4:
		        ptrE1->ingresarM(0);
			    cout<<"se realiza el proceso de reduccion "<<endl;
			    ptrE1->Gaus();
			    
			    return 0;
	}
	
	return 0;
}
