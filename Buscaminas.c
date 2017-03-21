#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Buscaminas*/
struct casilla{
	char tipo;
	int estado;
	int numMinas;
	char etiqueta;
		
};
typedef struct casilla tipocasilla;

	
tipocasilla  **inicializarJuego(int filas,int columnas){
	int i,j;
	tipocasilla **matrix;
	matrix = (tipocasilla**)malloc(filas*sizeof(tipocasilla *));
	for(i = 0; i < filas; i++){
		matrix[i]=(tipocasilla *)malloc(columnas*sizeof(tipocasilla));
		for(j=0; j < columnas; j++){ 
			matrix[i][j].estado = 0;
			matrix[i][j].etiqueta = '#';
			matrix[i][j].tipo = 'C';
			matrix[i][j].numMinas = 0;
		}
	
	}
	return matrix;
}

void AsignarMinas(int filas, int columnas, tipocasilla **tablero,int numeroMinas){
	int m=0;
	srand(time(NULL));
	int posFila,posColum;
	while ( m < numeroMinas){
		posFila = rand() % filas;
		posColum =  rand() % columnas;
		if (tablero[posFila][posColum].tipo != 'M'){
			
			tablero[posFila][posColum].tipo = 'M';
			m++;
		}
			
	}
			
}

	

void AsignarNumeros(int filas, int columnas,tipocasilla **tablero){
	int contador=0;
	int i,j;
	for(i = 0; i < filas; i++){
		for(j=0; j < columnas; j++){
			contador=0;
			if (tablero[i][j].tipo == 'C'){
				if (i==0 && j==0){   //esquina izquierda arriba
					if (tablero[i+1][j].tipo == 'M'){
						contador+=1;
					}	
					if (tablero[i][j+1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i+1][j+1].tipo == 'M'){
						contador+=1;
					}
				}
				else if (i == (filas -1) && j==0){ //esquina izquierda abajo
					if (tablero[i][j+1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i-1][j].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i-1][j+1].tipo == 'M'){
						contador+=1;
					}
				}
				else if (i==0 && j == (columnas-1)){ //esquina derecha arriba
					if (tablero[i+1][j].tipo == 'M'){
						contador+=1;
					}	
					if (tablero[i][j-1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i+1][j-1].tipo == 'M'){
						contador+=1;
					}
				}

				else if (i==(filas-1) && j==(columnas-1)){ //esquina derecha abajo
					if (tablero[i][j-1].tipo == 'M'){
						contador+=1;
					}	
					if (tablero[i-1][j].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i-1][j-1].tipo == 'M'){
						contador+=1;
					}
				}
				else if (j==0 && i!=0 && i!=(filas-1)){ //casillas con j = 0
					if (tablero[i+1][j].tipo == 'M'){
						contador+=1;	
					}
					if (tablero[i-1][j].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i][j+1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i+1][j+1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i-1][j+1].tipo == 'M'){
						contador+=1;
					}
				}
				else if (j==(columnas-1) && i!=0 && i!=(filas-1)){  //cuando j = columnas-1  
					if (tablero[i+1][j].tipo == 'M'){
						contador+=1;	
					}
					if (tablero[i-1][j].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i][j-1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i+1][j-1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i-1][j-1].tipo == 'M'){
						contador+=1;
					}
				}	
				else if (i==0 && j!=0 && j!=(columnas-1)){ //cuando i = 0
					if (tablero[i+1][j].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i][j+1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i][j-1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i+1][j-1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i+1][j+1].tipo == 'M'){
						contador+=1;
					}
				}
				else if (i==(filas-1) && j!=0 && j!=(columnas-1)){ //cuando i = (filas-1)
					if (tablero[i-1][j].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i][j+1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i][j-1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i-1][j-1].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i-1][j+1].tipo == 'M'){
						contador+=1;
					}
				}
				
				else if (i!=0 && j!=0 && i!=(filas-1) && j!=(columnas-1)){ //cuando la casilla no está en ningun borde
					if (tablero[i+1][j].tipo == 'M'){
						contador+=1;
					}
					if (tablero[i][j+1].tipo == 'M'){
						contador+=1;
					}
				
					if (tablero[i][j-1].tipo == 'M'){
						contador+=1;
					}
				
					if (tablero[i-1][j].tipo == 'M'){
						contador+=1;
					}

					if (tablero[i-1][j-1].tipo == 'M'){
						contador+=1;
					}

					if (tablero[i+1][j-1].tipo == 'M'){
						contador+=1;
					}
				
					if (tablero[i-1][j+1].tipo == 'M'){
						contador+=1;
					}
				
					if (tablero[i+1][j+1].tipo == 'M'){
						contador+=1;
					}
					
				}		
				
			}
			else{
				contador=0;
			}	

		tablero[i][j].numMinas = contador;
		
		}
		
	}
	
}

void DeterminarTipo(int filas, int columnas, tipocasilla **tablero){
	int contador=0;
	int i,j;
	for(i = 0; i < filas; i++){
		for(j=0; j < columnas; j++){
			if(tablero[i][j].numMinas != 0){
				tablero[i][j].tipo = 'N';
			}	
		}
	}	


}

void EmpezarJuego(){
	printf("\n\t \t   ============================\n");
	printf("  \t \t           BUSCAMINAS              ");
	printf("\n\t \t   ============================\n");
	
}	
	

void dibujarJuego(int filas, int columnas, tipocasilla **tablero){
	int i,j;
	printf("\n");
	for (i=0; i < filas; i++){
		printf("\t\t\t");
		for(j=0; j < columnas; j++){
			if (tablero[i][j].estado == 0 || tablero[i][j].tipo == 'M'){
				printf("[%c]",tablero[i][j].etiqueta);
			}	
			else{
				printf("[%d]",tablero[i][j].numMinas);
			}	
				
		}
		printf("\n");
		
	} 
	
}



int AbrirCasilla(int filas,int columnas,tipocasilla **tablero){
	int x,y,z=0;
	
	while (z < (filas*columnas+10)){
		printf("\n");
		fflush(stdin);
		printf("Digite la fila que desee abrir: ");
		scanf("%d",&x);
		fflush(stdin);
		printf("Digite la columna que desee abrir: ");
		scanf("%d",&y);
		if (x > (filas-1) || x < 0 || y < 0 || y > (columnas-1) ){
			printf("\nlas coordenas no estan en el tablero...Intentelo de nuevo\n");
			printf("(Las filas y columnas van desde 0 hasta filas-1 \n y desde 0 hasta columnas-1 respectivamente.)\n");
		}
		else{
			tablero[x][y].estado = 1;
			tablero[x][y].etiqueta = tablero[x][y].tipo;
			dibujarJuego(filas,columnas,tablero);	
			if (tablero[x][y].etiqueta == 'M'){
				printf("\n");
				printf("\t \t \t ----- GAME OVER -----\n");
				break;
			}	
		}
		z++;
	}
	return 0;
}	

int main(int argc,char *argv[]){
	int filas = atoi(argv[1]);
	int columnas = atoi(argv[2]);
	int numeroMinas = atoi(argv[3]);
	tipocasilla **tablero;
	tablero = inicializarJuego(filas,columnas);
	AsignarMinas(filas,columnas,tablero,numeroMinas);
	AsignarNumeros(filas,columnas,tablero);
	DeterminarTipo(filas,columnas,tablero);
	EmpezarJuego();
	dibujarJuego(filas,columnas,tablero);
	AbrirCasilla(filas,columnas,tablero);
	return 0;
}
