/*Se pretende generar un programa que esconda una mina en una matriz.

• Al inicio, el programa guardará en una variable oculta al usuario las coordenadas (fila/columna) de una bomba. 


• Se generará un tablero formado por casillas en las que el jugador debe buscar esa bomba. -> HECHO
• Con cada intento del usuario se debe comprobar si las coordenadas introducidas coinciden con las de la bomba. 
• En el momento que se encuentre la bomba acaba el programa. 
• En caso de no encontrarla, se marcan con ‘O’ las casillas exploradas y con ‘?’ las casillas no exploradas.
• Se debe generar una matriz cuadrada de caracteres de un tamaño dado por el usuario. El tamaño de la matriz se pasa como parámetro de entrada por argc/argv, y se reservará memoria dinámica en
función de ese valor.

• Se pide implementar una función que cree un array dinámico de dos dimensiones de un
tamaño dado:

	• char** crearMatriz(int numFilasColumnas)
	• Los elementos de la matriz pueden contener el valor:
		 INCOGNITA = ‘?’
		 AGUA = ‘O’

• Se pide implementar una función que rellene un array dinámico doble con un valor por defecto. 
• Al inicio, se rellenará con el valor ‘?’ los elementos de la matriz doble creada anteriormente usando esta función:
	 void rellenaMatriz(char** matriz, int tam, char valor)
• El programa pedirá al usuario coordenadas (fila/columna) dentro de la matriz creada anteriormente.
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
		
• Una vez se tienen las coordenadas del intento, se usa esta función para testear si se ha encontrado la bomba. Se pide implementar una estructura “coordenadas_t” que almacene las coordenadas fila/columna de la bomba.
• Se usarán esas coordenadas en esta función para el test.
• En caso de acierto, se marca el intento como “bomba encontrada” y acaba el programa.
• En caso de fallo, se marca en el intento si ha acertado la fila o la columna, y se marca en la matriz esas coordenadas como casilla explorada (‘O’).
	 void insertaIntentoEnLista(listaIntentos_t* intentos, intento_t nuevoIntento);

• Después de haber testeado el intento y no haber encontrado la bomba, se guardará el intento en una estructura “listaIntentos_t” que almacenará el array dinámico de intentos, y el número de intentos que hay en ese
momento.

• Para interactuar con el programa, se debe crear un menú que pida datos al usuario. Las opciones de menú son las siguientes:
	1 Buscar la bomba:
		 Pedirá por pantalla fila y columna, testeará esas coordenadas y guardará la siguiente
		información en un array dinámico de intentos:
		• fila, columna, si la bomba se encuentra en esa fila o en esa columna.
	
	
	2 Visualizar la matriz:
		 Presentará por pantalla la matriz indicando con el caracter ‘?’ que no se ha buscado
		en esa posición y con ‘O’ que ha sido un intento fallido.
		
		
	3 Toda la información de los distintos intentos se guardará en un array cuya memoria
		se gestionará de forma dinámica.
		Visualizar los intentos:
		 Presentará por pantalla toda la información recogida de cada intento, indicando si
		se acierta la fila o la columna
	
	4 Salir
		Presenta la matriz antes de salir, en este caso indicando una ‘X’ donde se encontraba
		la bomba.
	
	5 Libera toda la memoria dinámica del programa antes de acabar
	
• Pista: Piensa que primero tendrás que pedir memoria para los punteros de cada fila y luego para cada array de caracteres, cuyo tamaño coincide con el de las columnas. Al ser una matriz cuadrada el
  tamaño será el mismo tanto para las filas como para las columnas.

*/
  
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  
  typedef struct {
	int fila;
	int columna;
  } Coordenadas_t;	
  
  int check_option(int opcion, char ** matriz, Coordenadas_t bomba);
  Coordenadas_t randomize_bomb(char ** matriz, int userSize);
  
  


  int check_option(int opcion, char ** matriz, Coordenadas_t bomba){
	
	int filaUsuario;
	int columnaUsuario;
	
	switch(opcion) {
		case 1:
			
			printf("Opcion 1, introduzca coordenadas (x y) : \n");
			scanf("%d %d", &filaUsuario, &columnaUsuario);
			printf("Las opciones que ha metido el usuario son %d %d\n", filaUsuario, columnaUsuario);
			
			if(filaUsuario == bomba.fila && columnaUsuario == bomba.columna){
					printf("ADIVINASTEEEEE");
					return 1;
				}else{
					printf("FALLASTE");
					return 0;
				}
				
			break;
		case 2:
			printf("Ha elegido visualizar el numero de intentos\n");
			break;
		case 3:
			printf("Ha elegido ver la matriz\n");
			break;
		default:
			printf("Opcion no valida\n");
			break;
	}
	
	return 0;
  }
  
  Coordenadas_t randomize_bomb(char ** matriz, int userSize){
	  
	  Coordenadas_t bomba;
	  
	  bomba.fila = rand() % userSize;
	  bomba.columna = rand() % userSize;
	  
	  matriz[bomba.fila][bomba.columna];
	  
	  printf(">>> La bomba esta en: Fila: %d, Columna: %d\n", bomba.fila, bomba.columna);
		
	  return bomba;
  }
 
  
  
  int main(int argc, char * argv[]){
	  
	int userSize;
	int userOption;
	
	
	printf("Bienvenido al juego, por favor, introduzca el area del tablero: ");
	scanf("%d", &userSize);
	
	
	char ** matriz = (char **)malloc(userSize * sizeof(char *));
	for(int i = 0; i < userSize; i++){
		matriz[i] = (char *)malloc(userSize * sizeof(char));
	}
	
	Coordenadas_t bomba = randomize_bomb(matriz, userSize);	 
	
	while(1){
		printf("***************************************************\n");
		printf("Introduzca una opcion, por favor: \n");
		printf("1) Buscar\n");
		printf("2) Visualizar numero de intentos \n");
		printf("3) Ver la matriz\n");
		printf("4) Salir\n");
		printf("***************************************************\n");
		scanf("%d", &userOption); //Valor de memoria de la var userOption
		check_option(userOption, matriz, bomba); //Valor real
	}
	
	printf("La direccion de memoria de la matriz es: %p\n", (void *)matriz);

	free(matriz);
	return 0;
  
 }