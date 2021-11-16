#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
class Matriz{
	
	friend istream &operator >>(istream &,Matriz &);
	friend ostream &operator <<(ostream &,Matriz &);
	friend Matriz &operator *(Matriz &,Matriz &);
	friend Matriz &operator +(Matriz &,Matriz &);
	friend Matriz &operator -(Matriz &,Matriz &);
	friend Matriz &operator *(Matriz &,float &);
	public:
	   	Matriz(int ,int );
	   	Matriz();
	   	Matriz(Matriz &);
	   	~Matriz();
	   	float setM(int ,int );
		const float getNumero(int ,int );
		float setN(float ,int ,int );
		int getF();
		int getC();
	private:
	  	int fila;
	  	int columna;
	  	float **matriz;
		
};

