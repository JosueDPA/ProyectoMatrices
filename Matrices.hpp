#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
class Matriz{
	
	friend istream &operator >>(istream &,Matriz &);
	friend ostream &operator <<(ostream &,Matriz &);
	
	public:
	   	Matriz(int ,int );
	   	Matriz();
	   	~Matriz();
	   	Matriz &operator+(Matriz &);
	   	Matriz &operator-(Matriz &);
	   	Matriz &operator*(float );
	   	Matriz &operator=(Matriz &);
	   	float setM(int ,int );
	   	float ingresarM(int );
	   	float suma(Matriz ,Matriz );
		const float getNumero(int ,int );
		float MultiEs(float );
		float Producto(Matriz ,Matriz );
		float setN(float ,int ,int );
		int getF();
		int getC();
		float Ma(int i,int j);
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
	 float getCo(int ,int );
	 float getRes(int );
	 float Gaus();
	 	
	private:
	 int fila,columna;
	 float *result;
	 float **inc;	
};
