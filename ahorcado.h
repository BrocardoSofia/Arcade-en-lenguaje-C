#ifndef AHORCADO_H_INCLUDED
#define AHORCADO_H_INCLUDED

void tituloA();
void rectanguloAhorcado();
void gotoxyAhorcado(int x, int y);
void juegoAhorcado(char nombre1[],char nombre2[], int *puntaje1, int *puntaje2);
int juego(char nombre[], char nombre2[]);
int adivina(char nombre[], char palabra[]);
void muestraAhorcado(char nombre[],int intentos,int puntaje,char codigo[30]);
void verIntentos(int intentos);
int verificaChar(char letra, char letrasArray[], int validosLetras);
void pasaCodigo(Pila pilita,char letra,char codigo[30], int longitud);
void inicCodigo(int longitud,char codigo[30]);
int buscarAdivinar(char letra,Pila *pilita,char palabra[],int longitud);
int gana(char codigo[30],int longitud);
void gameOverAhorcado();

#endif // AHORCADO_H_INCLUDED
