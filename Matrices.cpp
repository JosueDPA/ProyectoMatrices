#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include"Matrices.hpp"

Matrices::Matrices(int Mifila,int Micolumna,float Mimatriz){
	this->fila=Mifila;
	this->columna=Micolumna;
	this->Matriz[100][100]=Mimatriz;
}
