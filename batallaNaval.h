#ifndef BATALLANAVAL_H_INCLUDED
#define BATALLANAVAL_H_INCLUDED

//BATALLA NAVAL
//funciones muestra tablero
void mostrarTablero(int matrix[10][10]);
void mostrarTableroChar(char matrix[10][10]);
void inicializacionChar(char arreglo[10][10]);

//funciones de validacion
int validacionColumnaUp(int arreglo[10][10], int ficha, int fila, int columna);
int validacionColumnaDown(int arreglo[10][10], int ficha, int fila, int columna);
int validacionColumnaRight(int arreglo[10][10], int ficha, int fila, int columna);
int validacionColumnaLeft(int arreglo[10][10], int ficha, int fila, int columna);
int verificarFila();
int verificarColumna(int matrix[10][10], int fila);

//actualizacion de mapa char
int actualizaMapa(int arregloDatos[10][10], char arreglo[10][10], int fila, int columna);

//colocar fichas
void titulosCarga(int matrix[10][10], char mapaVer[10][10], char jugadorCarga[], char jugadorMapa[], int fichasTotal);
void cargarClave(int matrix[10][10], char jugadorCarga[], char jugadorMapa[], char mapaVer[10][10]);
void cargarFichas(int matrix[10][10], char mapaVer[10][10], int fichas, int fichasTotal, char jugadorCarga[], char jugadorMapa[]);
void colocarBarcos(int matrix[10][10], int fichas, int filas, int columnas, char dir);
void cargarTocados(int matrix[10][10], int fila, int columna);
void mapaClaveAVer(char mapaVer[10][10], int clave[10][10]);

//JUEGO
void mensajeInicio();
void mensaje(char name1[], char name2[]);
void cargaDeMapas(int mapaClave1[10][10], int mapaClave2[10][10], char mapaVer1[10][10], char mapaVer2[10][10], char name1[], char name2[]);
int iniciaJuego(int matrix[10][10], char matrixChar[10][10], char jugador[]);

void bye();
void rectangulo();
void gotoxy(int x, int y);

void juegoBatallaNaval(char player1[],char player2[],int *puntaje1,int *puntaje2);

#endif // BATALLANAVAL_H_INCLUDED
