#include<iostream>
using std::cout;
using std::cin;
using std::endl;
float Escalar;
#include"Matrices.hpp"

int main(){
	
	Matrices Matriz1(3,3);
	Matriz1.ingresarM();
	Matriz1.Mostrar();
	cout<<"ingrese el escalar que desea multiplicar con la matriz "<<endl;
	cin>>Escalar;
	Matriz1.MultiEs(Escalar);
	return 0;
}
