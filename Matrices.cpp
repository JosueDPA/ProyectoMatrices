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
Matriz::Matriz(Matriz &M1){
	this->fila=M1.fila;
	this->columna=M1.columna;
	matriz = new float*[this->fila];
	for(int i=0;i<fila;i++){
		matriz[i] = new float[this->columna];
	
	}
	for(int i=0;i<this->fila;i++){
		for(int j=0;j<this->columna;j++){
			*(*(matriz+i)+j)=M1.matriz[i][j];
		}
	}
	
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
Matriz &operator *(Matriz &M1,Matriz &M2){
		int a=M1.fila;
		int b=M2.columna;
		Matriz Resultado(a,b);
		if(M1.columna==M2.fila){
			float c;
	        for(int i=0;i<M1.fila;i++){
		
	 	         for(int j=0;j<M2.columna;j++){
			           c=0;
		              for(int z=0;z<M2.fila;z++){
		   	
				        Resultado.matriz[i][j]=M1.getNumero(i,z)*M2.getNumero(z,j)+c;
				        c=Resultado.matriz[i][j];
				        
			          }
			         
		         }
		         
		         
	        }
	        
	     return *(new Matriz(Resultado));
		}
		else{
			cout<<"no pueden ser multiplicadas por la dmensiones de las matrices"<<endl;
		}

}
Matriz &operator +(Matriz &M1,Matriz &M2){
	int a=M1.getF();
	int b=M1.getC();
	Matriz Result(a,b);
	if(M1.getF()==M2.getF() && M1.getC()==M2.getC()){
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				Result.matriz[i][j]=M1.getNumero(i,j)+M2.getNumero(i,j);
			}
		}
	 return *(new Matriz(Result));;
	}else{
		cout<<"las dimensiones de las matrices que desea sumar son difrerentes"<<endl;
	}
	
}
Matriz &operator -(Matriz &M1,Matriz &M2){
	int a=M1.getF();
	int b=M1.getC();
	Matriz Result(a,b);
	if(M1.getF()==M2.getF() && M1.getC()==M2.getC()){
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				Result.matriz[i][j]=M1.getNumero(i,j)-M2.getNumero(i,j);
			}
		}
		return *(new Matriz(Result));
	}else{
		cout<<"las dimensiones de las matrices que desea sumar son difrerentes"<<endl;
	}
	
}
Matriz &operator *(Matriz &M1,float &Escalar){
	int a=M1.getF();
	int b=M1.getC();
	Matriz Result(a,b);
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			Result.matriz[i][j]=M1.getNumero(i,j)*Escalar;
		}
	}
	cout<<Result;
	return *(new Matriz(Result));
}

//funciones miembros 

float Matriz::setN(float r,int i,int j){
	*(*(matriz+i)+j)=r;
}
int Matriz::getF(){
	return this->fila;
}
int Matriz::getC(){
	return this->columna;
}
float Matriz::setM(int i,int j)
{
	cin>>*(*(matriz+i)+j);
}

const float Matriz::getNumero(int i, int j){
	return *(*(matriz+i)+j);
}




//Destructor
Matriz::~Matriz(){
	
	delete[] matriz;
	
}





