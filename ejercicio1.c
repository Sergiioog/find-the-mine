/*Se pretende generar un programa que esconda una mina en una matriz.

• Al inicio, el programa guardará en una variable oculta al usuario las coordenadas (fila/columna) de una bomba. 


• Se generará un tablero formado por casillas en las que el jugador debe buscar esa bomba. -> HECHO
• Con cada intento del usuario se debe comprobar si las coordenadas introducidas coinciden con las de la bomba. -> HECHO
• En el momento que se encuentre la bomba acaba el programa. -> HECHO
• En caso de no encontrarla, se marcan con ‘O’ las casillas exploradas y con ‘?’ las casillas no exploradas.
• Se debe generar una matriz cuadrada de caracteres de un tamaño dado por el usuario. El tamaño de la matriz se pasa como parámetro de entrada por argc/argv, y se reservará memoria dinámica en
función de ese valor. -> HECHO

• Se pide implementar una función que cree un array dinámico de dos dimensiones de un
tamaño dado: -> HECHO

	• char** crearMatriz(int numFilasColumnas)
	• Los elementos de la matriz pueden contener el valor:
		 INCOGNITA = ‘?’
		 AGUA = ‘O’

• Se pide implementar una función que rellene un array dinámico doble con un valor por defecto. -> HECHO
• Al inicio, se rellenará con el valor ‘?’ los elementos de la matriz doble creada anteriormente usando esta función:
	 void rellenaMatriz(char** matriz, int tam, char valor) -> HECHO
	
• El programa pedirá al usuario coordenadas (fila/columna) dentro de la matriz creada anteriormente. -> HECHO

• El objetivo es encontrar la bomba escondida, se debe almacenar cada intento del usuario y el resultado del mismo. En caso de no haberse encontrado la bomba, este intento 
	guardará información de ayuda:

		 La bomba está en esa fila
		 La bomba está en esa columna
		 Bomba encontrada
		 Se debe crear una estructura adecuada para almacenar esos intentos, y un array dinámico
		que crecerá con cada nuevo intento.
		 intento_t pedirIntento();
		• Esta función pide una fila/columna al usuario, lo almacena en una estructura
		“intento_t” y devuelve al usuario.
		 void testeaIntento(char** matriz, intento_t* nuevoIntento, coordenadas_t coordenadasBomba)
		
• Una vez se tienen las coordenadas del intento, se usa esta función para testear si se ha encontrado la bomba. Se pide implementar una estructura “coordenadas_t” que almacene las coordenadas fila/columna de la bomba. -> HECHO
• Se usarán esas coordenadas en esta función para el test. -> HECHO
• En caso de acierto, se marca el intento como “bomba encontrada” y acaba el programa. -> HECHO

• En caso de fallo, se marca en el intento si ha acertado la fila o la columna, y se marca en la matriz esas coordenadas como casilla explorada (‘O’).
	 void insertaIntentoEnLista(listaIntentos_t* intentos, intento_t nuevoIntento);

• Después de haber testeado el intento y no haber encontrado la bomba, se guardará el intento en una estructura “listaIntentos_t” que almacenará el array dinámico de intentos, y el número de intentos que hay en ese
momento.

• Para interactuar con el programa, se debe crear un menú que pida datos al usuario. Las opciones de menú son las siguientes:
	1 Buscar la bomba:
		 Pedirá por pantalla fila y columna, testeará esas coordenadas y guardará la siguiente -> FALTA INTENTOS
		información en un array dinámico de intentos:
		• fila, columna, si la bomba se encuentra en esa fila o en esa columna.
	
	
	2 Visualizar la matriz:
		 Presentará por pantalla la matriz indicando con el caracter ‘?’ que no se ha buscado -> HECHO
		en esa posición y con ‘O’ que ha sido un intento fallido.
		
		
	3 Toda la información de los distintos intentos se guardará en un array cuya memoria
		se gestionará de forma dinámica.
		Visualizar los intentos:
		 Presentará por pantalla toda la información recogida de cada intento, indicando si
		se acierta la fila o la columna
	
	4 Salir
		Presenta la matriz antes de salir, en este caso indicando una ‘X’ donde se encontraba -> HECHO
		la bomba.
	
	5 Libera toda la memoria dinámica del programa antes de acabar -> HECHO
	
• Pista: Piensa que primero tendrás que pedir memoria para los punteros de cada fila y luego para cada array de caracteres, cuyo tamaño coincide con el de las columnas. Al ser una matriz cuadrada el
  tamaño será el mismo tanto para las filas como para las columnas.




• El objetivo es encontrar la bomba escondida, se debe almacenar cada intento del usuario y el resultado del mismo. En caso de no haberse encontrado la bomba, este intento 
	guardará información de ayuda:

*/
  
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
  
   void give_advise(Coordenadas_t bomba, int id) {
	   
    if (id == 1) {
        printf("PISTA: La fila de la bomba es... %d\n", bomba.fila);
    }

    if (id == 2) {
        printf("PISTA: La columna de la bomba es... %d\n", bomba.columna);
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
            printf("Error: Debe ingresar un número entero.\n");
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