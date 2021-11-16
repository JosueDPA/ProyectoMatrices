#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<stdlib.h>
float Escalar;
int fila,columna,a,b,h,g;
#include"Matrices.hpp"
#include"Solucion.hpp"

int main(){
	cout<<"/·······································/"<<endl;
	cout<<"Hola este es la calculadora de Matrices de MxN"<<endl;
	cout<<"/·······································/"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"/·······································........................................../"<<endl;
	cout<<"1)   si desea multiplicar la matriz por un escalar "<<endl;
	cout<<"2)   si desea sumar dos matrices "<<endl;
	cout<<"3)   si desea multiplicar dos matrices "<<endl;
	cout<<"4)   si desea resolver el sistema de ecuaciones MxM+1 por medio de gauss jordan"<<endl;
	cout<<"/·······································........................................../"<<endl;
	cout<<endl;
	cout<<endl;
	cin>>a;
	if(a==1){
		cout<<"/............................................./"<<endl;
			   cout<<"ingrese el tamaño de la  matriz"<<endl;
			   cout<<"M: ";
			   cin>>fila;
			   cout<<"N: ";
			   cin>>columna;
			   h=fila;
			   g=columna;
	}
	if(a==2){
		cout<<"/............................................./"<<endl;
		cout<<"ingrese el tamaño de la primera  matriz"<<endl;
		cout<<"M: ";
		cin>>fila;
		cout<<"N: ";
		cin>>columna;
		cout<<"/............................................./"<<endl;
		cout<<"ingrese el tamaño de la segunda  matriz"<<endl;
		cout<<"M:";
		cin>>h;
		cout<<"N: ";
		cin>>g;
		cout<<"/............................................./"<<endl;
	}
	if(a==3){
		cout<<"/............................................./"<<endl;
		cout<<"ingrese el tamaño de la primera   matriz"<<endl;
		cout<<"M: ";
		cin>>fila;
		cout<<"N: ";
		cin>>columna;
		cout<<"/............................................./"<<endl;
		cout<<"ingrese el tamaño de la segunda  matriz"<<endl;
		cout<<"M: ";
		cin>>h;
		cout<<"N: ";
		cin>>g;
	}
	if(a==4){
		cout<<"/............................................./"<<endl;
		cout<<"ingrese el tamaño del sistema (tiene que ser cuadrado para usar reduccion por gauss jordan)"<<endl;
		cin>>fila;
		columna=fila+1;
	}
	Matriz *ptrE1 = new Matriz(fila,columna);
    Matriz *ptrE2 = new Matriz(h,g);
    Matriz *ptrE3 = new Matriz(fila,g);
	switch(a){
		case 1:
			   
		       cin>>*ptrE1;
		       cout<<"ingrese el escalar que se desea multiplicar "<<endl;
		       cin>>Escalar;
		       cout<<"Este seria el resultado de la multiplicacion :"<<endl;
		       *ptrE2=*ptrE1*Escalar; 
		       cout<<*ptrE2;
		       cout<<"/............................................./"<<endl;
		       return 0;
		    
		case 2:
			  cout<<"1) si desea sumar las dos matrices "<<endl;
			  cout<<"2) si desea restar las dos matrices"<<endl;
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
			               cout<<"/............................................./"<<endl;
			               return 0;
			        case 2:
			        	   
			               cout<<"ingrese los elementos de la primera matriz"<<endl;
			               cin>>*ptrE1;
			               cout<<"ingrese los elementos de la segunda matriz"<<endl;
			               cin>>*ptrE2;
			               cout<<"el resultado de esta resta es "<<endl;
			               *ptrE3=*ptrE1-*ptrE2;
			               cout<<*ptrE3;
			               cout<<"/............................................./"<<endl;
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
	            cout<<"/............................................./"<<endl;
	            
	            return 0;
	            
		case 4:
			    cout<<"ingrese los elementos de la matriz y los resultados"<<endl;
			    
		        Solucion *gtrE1 = new Solucion(fila,columna);
		        cin>>*gtrE1;
		        cout<<endl;
			    gtrE1->Gaus();
			    return 0;
	}
	
	return 0;
}
