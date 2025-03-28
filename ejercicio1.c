
  
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <stdbool.h>
  
  typedef struct {
	int fila;
	int columna;
  } Coordenadas_t;	
  
  typedef struct{
	int nuevoIntento;
	int **numIntentos;
  } Intento_t;
  

  int check_option(int opcion, char **matriz, Coordenadas_t bomba, int userSize);
  Coordenadas_t randomize_bomb(char ** matriz, int userSize);
  char ** create_matriz(int numFilasColumnas);
  void fill_matriz(char** matriz, int tam, Coordenadas_t bomba, int filaUsuario, int columnaUsuario);
  int number_tryials(int intento, Coordenadas_t bomba);
  void give_advise(Coordenadas_t bomba, int id);
  bool endGame = false;
  
 
  
  int main(int argc, char * argv[]){
	  
	  
	int userSize;
	int userOption;
	
	printf("Bienvenido al juego, por favor, introduzca el area del tablero: ");
	
	if (scanf("%d", &userSize) != 1) {
        printf("Error: Debe ingresar un numero entero.\n");
        while (getchar() != '\n'); 
		exit(1);
    }
		
	char ** matriz = create_matriz(userSize);
	Coordenadas_t bomba = randomize_bomb(matriz, userSize);	 
	
	while(!endGame){
		
		printf("***************************************************\n");
		printf("Introduzca una opcion, por favor: \n");
		printf("1) Buscar\n");
		printf("2) Visualizar numero de intentos \n");
		printf("3) Ver la matriz\n");
		printf("4) Salir\n");
		printf("***************************************************\n");
		
		if (scanf("%d", &userOption) != 1) {
            printf("Error: Debe ingresar un numero entero.\n");
            while (getchar() != '\n'); 
            continue; //Continuar preguntando opciones si no es un num
        }

		check_option(userOption, matriz, bomba, userSize);
	
	}
	
	for(int i = 0; i < userSize; i++){
		free(matriz[i]);
	}
	
	free(matriz);
	
	return 0;
 }
 
 	
  char ** create_matriz(int numFilasColumnas){
	 
	char ** matriz = (char **)malloc(numFilasColumnas * sizeof(char *));
	
	if(matriz == NULL){
		printf("Error al asignar memoria");
		return NULL;
	}
	
	for(int i = 0; i < numFilasColumnas; i++){
		matriz[i] = (char *)malloc(numFilasColumnas * sizeof(char));
		for(int j = 0; j < numFilasColumnas; j++){
			matriz[i][j] = '?';
		}
	}
	
	return matriz;
	  
  }


  int check_option(int opcion, char ** matriz, Coordenadas_t bomba, int userSize){
	
	int filaUsuario;
	int columnaUsuario;
	Intento_t intento;
	int numeroIntento = 1;
	intento.nuevoIntento = numeroIntento;
	
	switch(opcion) {
		
		case 1:
			
			printf("Opcion 1, introduzca coordenadas (x y) : \n");
			
			
			if(scanf("%d %d", &filaUsuario, &columnaUsuario) != 2){
				printf("Error: Debe ingresar dos numeros enteros.\n");
				while (getchar() != '\n');  
				return 1;
			}
			
			if(filaUsuario == bomba.fila && columnaUsuario == bomba.columna){
				
				printf("Adivinaste el lugar de la bomba!!! -> (%d,%d) \n", filaUsuario, columnaUsuario);
				printf("Fin del juego, gracias por participar. \n");
				fill_matriz(matriz, userSize, bomba, filaUsuario, columnaUsuario);
				
				for(int i = 0; i < userSize; i++){
					free(matriz[i]);
				}
				free(matriz);
				exit(0);
				
			}else{
				
				if(filaUsuario < 1 || filaUsuario > userSize || columnaUsuario < 1 || columnaUsuario > userSize){
					printf("Indices excedidos, introduzca coordenadas validas. El limite es: %d .\n", userSize);
					return 0;
				}else{
					printf("Fallo, intentelo de nuevo.\n");
					fill_matriz(matriz, userSize, bomba, filaUsuario, columnaUsuario);
					number_tryials(1, bomba);
					return 1;
				}
				
			}
			
			break;
		
		case 2:
			
			printf("Ha elegido visualizar el numero de intentos: \n");
			printf("El numero de intentos es: %d \n", number_tryials(0, bomba)); 
			break;
		
		
		case 3:

			printf("Ha elegido ver la matriz: \n");
			fill_matriz(matriz, userSize, bomba, filaUsuario, columnaUsuario);
			break;
		
		
		case 4:
	
			printf("Saliendo... gracias por participar! \n");
			endGame = true;
			fill_matriz(matriz, userSize, bomba, filaUsuario, columnaUsuario);
			exit(0);
		
		default:
		
			printf("Error, introduzca una opcion valida\n");
			return 0;
			
	}
}
  
  Coordenadas_t randomize_bomb(char ** matriz, int userSize){
	  
	  Coordenadas_t bomba;
	  bomba.fila = rand() % userSize;
	  bomba.columna = rand() % userSize;
	  	  		
	  return bomba;
  }
 
   
 void fill_matriz(char** matriz, int tam, Coordenadas_t bomba, int filaUsuario, int columnaUsuario){
	 
	
	for(int i = 0; i < tam; i++){
		
		for(int x = 0; x <= tam + 1; x++){
			printf("-");
		}
		printf("\n");
		printf("|");
		for(int j = 0; j < tam; j++){
			if(filaUsuario - 1 == i && columnaUsuario - 1 == j){
				if(filaUsuario == bomba.fila && columnaUsuario == bomba.columna){
					matriz[i][j] = 'X';
				}else{
					matriz[i][j] = 'O';
				}
			} 
			if(endGame == true){
				matriz[bomba.fila-1][bomba.columna-1] = 'X';
			}
			printf("%c", matriz[i][j]);
		}
		printf("|\n");
		for(int x = 0; x <= tam + 1; x++){
			printf("-");
		}
		printf("\n");
	}
  }
  
 int number_tryials(int intento, Coordenadas_t bomba){
	
	static int contador = 0;
	contador += intento;
	int bombaFilaId = 1;
	int bombaColumnaId = 2;
	
	if(contador > 6){
		give_advise(bomba, bombaFilaId);
	}
	
	if(contador > 9){
		give_advise(bomba, bombaColumnaId);
	}
	
	return contador;	
  
  }
 
  
 void give_advise(Coordenadas_t bomba, int id) {
	   
    if (id == 1) {
        printf("PISTA: La fila de la bomba es... %d\n", bomba.fila);
    }

    if (id == 2) {
        printf("PISTA: La columna de la bomba es... %d\n", bomba.columna);
    }
}
  
