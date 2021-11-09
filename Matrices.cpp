#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<windows.h>
#include<stdlib.h>
#include"Matrices.hpp"

Matriz::Matriz(int fila,int columna){
	this->fila=fila;
	this->columna=columna;
	matriz = new float*[fila];
	for(int i=0;i<fila;i++){
		matriz[i] = new float[columna];
	}
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			*(*(matriz+i)+j)=0;
		}
	}
}
Matriz::~Matriz(){
	
	delete[] matriz;
	
}
COORD coord={0,0};
void gotoxy(int x,int y){
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
float Matriz::ingresarM(int f){
	
	cout<<"ingrese los valores de la  matriz"<<endl;
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			gotoxy(j*5,i+11+f);
			cin>>*(*(matriz+i)+j);
			
		}
		
	}cout<<endl;
	
}



float Matriz::suma(Matriz MatrizA,Matriz MatrizB){
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			*(*(matriz+i)+j)=MatrizA.getNumero(i,j)+MatrizB.getNumero(i,j);
		}
	}
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			cout<<*(*(matriz+i)+j)<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
}
float Matriz::getNumero(int i, int j){
	return *(*(matriz+i)+j);
}
float Matriz::MultiEs(float Escalar){
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			cout<<*(*(matriz+i)+j)*Escalar<<"  ";
		}
		cout<<endl;
	}
}
float Matriz::Producto(Matriz MatrizA,Matriz MatrizB){
	float c;
	for(int i=0;i<this->fila;i++){
		
		for(int j=0;j<this->columna;j++){
			c=0;
		   for(int z=0;z<this->fila;z++){
		   	
				*(*(matriz+i)+j)=MatrizA.getNumero(i,z)*MatrizB.getNumero(z,j)+c;
				c=*(*(matriz+i)+j);
			}
		}
	}
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			cout<<*(*(matriz+i)+j)<<" ";
		}
		cout<<endl;
	}
}
float Matriz::Gaus(){
	for(int i=0;i<this->fila;i++)
	{
	  float pivote=*(*(matriz+i)+i);
	  float aux;
	  for(int k=0;k<this->columna;k++)
	  {
	  	*(*(matriz+i)+k)=*(*(matriz+i)+k)/pivote;
	  }
	  for(int j=0;j<this->fila;j++)
	  {
	  	if(i!=j)
		  {
	  		aux=*(*(matriz+j)+i);
	  		for(int g=0;g<this->fila;g++)
			  {
			  	*(*(matriz+j)+g)=*(*(matriz+j)+g)-aux*(*(*(matriz+i)+g));
			  }
		  }
	  }
	    for(int i=0;i<this->fila;i++){
		  for(int j=0;j<this->columna;j++){
			cout<<*(*(matriz+i)+j)<<"  ";
		   }
		    cout<<endl;
	    }cout<<endl;
	}
}

