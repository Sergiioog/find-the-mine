# Proyecto: find-the-mine

Este proyecto es un juego en C donde el usuario debe encontrar una bomba escondida en una matriz cuadrada. El tamaño de la matriz es definido por el usuario, y el juego utiliza memoria dinámica para gestionar las celdas del tablero.

## Descripción

El programa crea una matriz cuadrada y coloca una bomba en una posición aleatoria. El jugador intenta adivinar las coordenadas (fila/columna) de la bomba. Con cada intento, se indica si el jugador acertó la fila o la columna, y las casillas exploradas se marcan con 'O', mientras que las no exploradas se marcan con '?'. El juego termina cuando el jugador encuentra la bomba.

## Características

1. **Creación de la matriz dinámica**: Se crea y reserva la memoria para la matriz cuadrada.
2. **Generación de la bomba**: Se guarda la posición de la bomba en la matriz.
3. **Entrada del jugador**: El jugador introduce coordenadas para intentar encontrar la bomba.
4. **Seguimiento de intentos**: Se guarda información sobre los intentos previos.
5. **Finalización del juego**: El juego termina cuando se encuentra la bomba.

## Funciones

- `char** crearMatriz(int numFilasColumnas)`: Crea una matriz dinámica.
- `void rellenaMatriz(char** matriz, int tam, char valor)`: Rellena la matriz con un valor.
- `intento_t pedirIntento()`: Solicita al jugador las coordenadas.
- `void testeaIntento(char** matriz, intento_t* nuevoIntento, coordenadas_t coordenadasBomba)`: Verifica si el intento coincide con la bomba.
- `void insertaIntentoEnLista(listaIntentos_t* intentos, intento_t nuevoIntento)`: Guarda los intentos fallidos.

## Menú del Juego

1. **Buscar la bomba**: El jugador introduce coordenadas para intentar encontrar la bomba.
2. **Visualizar la matriz**: Muestra el tablero con 'O' (casillas exploradas) y '?' (casillas no exploradas).
3. **Visualizar los intentos**: Muestra los intentos previos.
4. **Salir**: Muestra la matriz final y libera la memoria.

## Requisitos

Para ejecutar el proyecto, necesitas un compilador C, como GCC en Windows.

### Instalación de GCC en Windows

1. **Instalar MinGW**:
   - Descarga [MinGW-w64](https://sourceforge.net/projects/mingw-w64/).
   - Asegúrate de agregar GCC al PATH durante la instalación.

2. **Verificación**:
   - Abre la terminal y ejecuta `gcc --version` para confirmar que GCC está instalado.

## Clonación del Repositorio

Clona el repositorio con:

```bash
git clone https://github.com/Sergiioog/find-the-mine
