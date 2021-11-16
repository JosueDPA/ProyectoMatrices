#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
#include<windows.h>
#include<stdlib.h>
#include"Solucion.hpp"

//Cosntructor
Solucion::Solucion(int fila,int columna){
	this->fila=fila;
	this->columna=columna;
	inc = new float*[fila];
	for(int i=0;i<fila;i++){
		inc[i] = new float[columna];
	}
	result = new float[fila];
}
//funcion para ventana
COORD coord={0,0};
void gotoxy(int x,int y){
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Funiones friend
//operador cin>>
istream &operator >>(istream &entrada,Solucion &Solucion1){
    for(int i=0;i<Solucion1.fila;i++)
	{
		
		for(int j=0;j<Solucion1.columna-1;j++)
		{
			gotoxy(j*6,i+15+Solucion1.fila);
			Solucion1.setCo(i,j);
			if(j==Solucion1.columna-2){
				gotoxy(j*6+14,i+15+Solucion1.fila);
				Solucion1.setRes(i);
			}	
		}
		
		
	}
}
//operador Cout<<
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
//funciones miembros
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
//destructor
Solucion::~Solucion(){
	delete[] result;
	delete[] inc;
}


