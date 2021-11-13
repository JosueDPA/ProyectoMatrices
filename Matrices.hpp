#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
class Matriz{
	
	
	public:
	   	Matriz(int ,int );
	   	Matriz(int );
	   	~Matriz();
	   	float ingresarM(int );
	   	float suma(Matriz ,Matriz );
		const float getNumero(int ,int );
		float MultiEs(float );
		float Gaus();
		float Producto(Matriz ,Matriz );
	private:
	  	int fila;
	  	int columna;
	  	float **matriz;
		
};
class Solucion{
	friend istream &operator >>(istream &,Solucion &);
	friend ostream &operator <<(ostream &,Solucion &);
	public:
	 Solucion(int ,int );
	 float setCo(int ,int );
	 float setRes(int);
	 float getFila();
	 float getColum();
	 float getCo(int ,int );
	 float getRes(int );
	 float Gaus();
	 	
	private:
	 int fila,columna;
	 float *result;
	 float **inc;	
};
