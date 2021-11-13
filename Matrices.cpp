#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
#include<windows.h>
#include<stdlib.h>
#include"Matrices.hpp"
//Constructores
//primer constructor
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
//segundo constructor
Matriz::Matriz(int fila){
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

COORD coord={0,0};
void gotoxy(int x,int y){
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//funciones miembros 
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
const float Matriz::getNumero(int i, int j){
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
//Destructor
Matriz::~Matriz(){
	
	delete[] matriz;
	
}
//clase solucion
//constructor
Solucion::Solucion(int fila,int columna){
	this->fila=fila;
	this->columna=columna;
	inc = new float*[fila];
	for(int i=0;i<fila;i++){
		inc[i] = new float[columna];
	}
	result = new float[fila];
}


istream &operator >>(istream &entrada,Solucion &Solucion1){
    for(int i=0;i<Solucion1.getFila();i++)
	{
		
		for(int j=0;j<Solucion1.getColum()-1;j++)
		{
			gotoxy(j*6,i+11+Solucion1.getFila());
			Solucion1.setCo(i,j);
			if(j==Solucion1.getColum()-2){
				gotoxy(j*6+14,i+11+Solucion1.getFila());
				Solucion1.setRes(i);
			}	
		}
		
		
	}
}
float Solucion::setCo(int i,int j){
	cin>>*(*(inc+i)+j);
}
float Solucion::getFila(){
	return this->fila;
}
float Solucion::getColum(){
	return this->columna;
}
float Solucion::setRes(int i){
	cin>>this->result[i];
}
float Solucion::getCo(int i,int j){
	return *(*(inc+i)+j);
}
float Solucion::getRes(int i){
    return this->result[i];	
}
ostream &operator <<(ostream &salida,Solucion &solucion1)
{
	for(int i=0;i<solucion1.getFila();i++)
	{
		for(int j=0;j<solucion1.getColum()-1;j++)
		{
			salida<<solucion1.getCo(i,j)<<"  ";
		}
		cout<<"=";
		salida<<solucion1.getRes(i);
		cout<<endl;
	}
}

float Solucion::Gaus(){
	for(int i=0;i<this->fila;i++)
	{
	  float pivote=*(*(inc+i)+i);
	  float aux;
	  for(int k=0;k<this->columna-1;k++)
	  {
	  	*(*(inc+i)+k)=*(*(inc+i)+k)/pivote;
	  }
	  result[i]=result[i]/pivote;
	  for(int j=0;j<this->fila;j++)
	  {
	  	if(i!=j)
		  {
	  		aux=*(*(inc+j)+i);
	  		for(int g=0;g<this->fila;g++)
			  {
			  	*(*(inc+j)+g)=*(*(inc+j)+g)-aux*(*(*(inc+i)+g));
			  }
			  result[j]=result[j]-aux*result[i];
		  }
	  }
	    for(int i=0;i<this->fila;i++){
		  for(int j=0;j<this->columna-1;j++){
			cout<<*(*(inc+i)+j)<<"  ";
		   }
		   cout<<"="<<result[i]<<endl;
		    
	    }cout<<endl;
	}
}


