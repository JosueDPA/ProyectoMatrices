class Matrices{
	
	
	public:
	   	Matrices(int ,int );
	   	float ingresarM(int );
	   	float suma(Matrices ,Matrices );
		float getNumero(int ,int );
		float MultiEs(float );
		float Gaus();
		float Producto(Matrices ,Matrices);
	private:
	  	int fila;
	  	int columna;
	  	float Matriz[100][100];
		
};
