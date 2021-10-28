#include<iostream>
using std::cout;
using std::cin;
using std::endl;
float matrizA[100][100],matrizB[100][100],matrizC[100][100];
#include"Matrices.hpp"

int main(){
	
	Matrices Matriz1(3,3,matrizA[100][100]);
	Matrices Matriz2(3,3,matrizB[100][100]);
	Matrices Matriz3(3,3,matrizC[100][100]);
	
	Matriz3.ingresarM();
	Matriz3.Mostrar();
	
	return 0;
}
