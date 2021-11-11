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
	public:
	 Solucion(int ,int );
	 
	 	
	private:
	 int fila,columna;
	 float *result;
	 float **inc;	
};
