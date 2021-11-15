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
Matriz::Matriz(){
	this->fila=0;
	this->columna=0;
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
istream &operator >>(istream &entrada,Matriz &Matriz1){
    for(int i=0;i<Matriz1.fila;i++)
	{
		
		for(int j=0;j<Matriz1.columna;j++)
		{
			cout<<i+1<<"x"<<j+1<<" :";
			Matriz1.setM(i,j);
			}	
		}
		
		
	}
ostream &operator <<(ostream &salida,Matriz &Matriz1)
{
	for(int i=0;i<Matriz1.fila;i++)
	{
		for(int j=0;j<Matriz1.columna;j++)
		{
			salida<<Matriz1.getNumero(i,j)<<"  ";
		}
		
		
		cout<<endl;
	}cout<<endl;
}
Matriz &Matriz::operator+(Matriz &M1){
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			this->matriz[i][j]=this->matriz[i][j]+M1.getNumero(i,j);
		}
	}
	return *this;
}
Matriz &Matriz::operator-(Matriz &M1){
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			this->matriz[i][j]=this->matriz[i][j]-M1.getNumero(i,j);
		}
	}
	return *this;
	
}

Matriz &Matriz::operator*(float Escalar){
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			this->matriz[i][j]=this->matriz[i][j]*Escalar;
		}
	}
	return *this;
}
Matriz &Matriz::operator=(Matriz &Matriz1){
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			this->matriz[i][j]=Matriz1.getNumero(i,j);
		}
	}
	return *this;
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
float Matriz::setN(float r,int i,int j){
	*(*(matriz+i)+j)=r;
}
int Matriz::getF(){
	return this->fila;
}
int Matriz::getC(){
	return this->columna;
}
float Matriz::Ma(int i,int j){
	return *(*(matriz+i)+j);
}
float Matriz::setM(int i,int j)
{
	cin>>*(*(matriz+i)+j);
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
    for(int i=0;i<Solucion1.fila;i++)
	{
		
		for(int j=0;j<Solucion1.columna-1;j++)
		{
			gotoxy(j*6,i+11+Solucion1.fila);
			Solucion1.setCo(i,j);
			if(j==Solucion1.columna-2){
				gotoxy(j*6+14,i+11+Solucion1.fila);
				Solucion1.setRes(i);
			}	
		}
		
		
	}
}
float Solucion::setCo(int i,int j){
	cin>>*(*(inc+i)+j);
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
	for(int i=0;i<solucion1.fila;i++)
	{
		for(int j=0;j<solucion1.columna-1;j++)
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


