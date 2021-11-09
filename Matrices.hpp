class Matriz{
	
	
	public:
	   	Matriz(int ,int );
	   	Matriz(int );
	   	~Matriz();
	   	float ingresarM(int );
	   	float suma(Matriz ,Matriz );
		float getNumero(int ,int );
		float MultiEs(float );
		float Gaus();
		float Producto(Matriz ,Matriz);
	private:
	  	int fila;
	  	int columna;
	  	float **matriz;
		
};
