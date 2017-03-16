#include <stdio.h>
#include <stdlib.h>

/*Buscaminas*/
struct casilla{
	char tipo;
	int estado;
	int numMinas;
	char etiquetas;
	
};
typedef struct casillas tipocasilla;

	
void inicializarJuego(int filas,int columnas,int **matrix){
	int i,j;
	for(i = 0; i < filas; i++){
		matrix[i]=(int *)malloc(columnas*sizeof(int));
		for(j=0; j < columnas; j++){ 
			matrix[i][j] = i+j;
		
		}

	}

}

void dibujarJuego(int filas, int columnas, int **matrix){
	int i,j;
	for (i=0; i < filas; i++){
		for(j=0; j < columnas; j++){
			printf("%d\t",matrix[i][j]);
			
		
		
		
		}
		printf("\n");
	} 

		

}


int main(int argc,char *argv[]){
	int filas = atoi(argv[1]);
	int columnas = atoi(argv[2]);
	int **matrix;
	matrix = (int **)malloc(filas*sizeof(int *));
	inicializarJuego(filas,columnas,matrix);
	dibujarJuego(filas,columnas,matrix);
	/*EmpezarJuego(filas,columnas,matrix);*/
	return 0;
}
