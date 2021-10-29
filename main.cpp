#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include"Matrices.hpp"

int main(){
	
	Matrices Matriz1(3,3);
	Matrices Matriz2(3,3);
	Matrices Matriz3(3,3);
	
	Matriz1.ingresarM();
	Matriz1.Mostrar();
	Matriz2.ingresarM();
	Matriz2.Mostrar();
	Matriz3.suma(Matriz1,Matriz2);
	Matriz3.Mostrar();
	return 0;
}
