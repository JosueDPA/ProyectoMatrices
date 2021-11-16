#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;


class Solucion{
	friend istream &operator >>(istream &,Solucion &);
	friend ostream &operator <<(ostream &,Solucion &);
	public:
	 Solucion(int ,int );
	 ~Solucion();
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
