#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include"Matrices.hpp"

Matrices::Matrices(int Mifila,int Micolumna,float Mimatriz){
	this->fila=Mifila;
	this->columna=Micolumna;
	this->Matriz[100][100]=Mimatriz;
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
		
	}
	cout<<endl;
}
float Matrices::Mostrar(){
	
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			cout<<Matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

}
float Matrices::suma(Matrices MatrizA,Matrices MatrizB){
	
}
float Matrices::getNumero(int i, int j){
	return this->Matriz[i][j];
}
