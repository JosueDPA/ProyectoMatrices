#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<windows.h>
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
COORD coord={0,0};
void gotoxy(int x,int y){
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
float Matrices::ingresarM(int f){
	
	cout<<"ingrese los valores de la  matriz"<<endl;
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			gotoxy(j*5,i+11+f);
			cin>>Matriz[i][j];
			
		}
		
	}cout<<endl;
	
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
			cout<<Matriz[i][j]*Escalar<<"  ";
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
float Matrices::Gaus(){
	for(int i=0;i<this->fila;i++)
	{
	  float pivote=Matriz[i][i];
	  float aux;
	  for(int k=0;k<this->columna;k++)
	  {
	  	Matriz[i][k]=Matriz[i][k]/pivote;
	  }
	  for(int j=0;j<this->fila;j++)
	  {
	  	if(i!=j)
		  {
	  		aux=Matriz[j][i];
	  		for(int g=0;g<this->fila;g++)
			  {
			  	Matriz[j][g]=Matriz[j][g]-aux*Matriz[i][g];
			  }
		  }
	  }
	    for(int i=0;i<this->fila;i++){
		  for(int j=0;j<this->columna;j++){
			cout<<Matriz[i][j]<<"  ";
		   }
		    cout<<endl;
	    }cout<<endl;
	}
}

