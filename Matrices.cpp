#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include"Matrices.hpp"

Matrices::Matrices(int Mifila,int Micolumna){
	this->fila=Mifila;
	this->columna=Micolumna;
	this->Matriz[100][100];
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			Matriz[i][j]=0;
		}
	}
}

float Matrices::ingresarM(){
	
	cout<<"ingrese los valores de la  matriz"<<endl;
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			cout<<i+1<<" x "<<j+1<<" : ";
			cin>>Matriz[i][j];
			
		}
		
	}cout<<endl;
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			cout<<Matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
}



float Matrices::suma(Matrices MatrizA,Matrices MatrizB){
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			Matriz[i][j]=MatrizA.getNumero(i,j)+MatrizB.getNumero(i,j);
		}
	}
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			cout<<Matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
}
float Matrices::getNumero(int i, int j){
	return this->Matriz[i][j];
}
float Matrices::MultiEs(float Escalar){
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			cout<<Matriz[i][j]*Escalar<<" ";
		}
		cout<<endl;
	}
}
float Matrices::Producto(Matrices MatrizA,Matrices MatrizB){
	float c;
	for(int i=0;i<this->fila;i++){
		
		for(int j=0;j<this->columna;j++){
			c=0;
		   for(int z=0;z<this->fila;z++){
		   	
				Matriz[i][j]=MatrizA.getNumero(i,z)*MatrizB.getNumero(z,j)+c;
				c=Matriz[i][j];
			}
		}
	}
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			cout<<Matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}
