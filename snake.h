#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

//!-------------------------------LIBRERIAS------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

//!-------------------------------CONSTANTES------------------------------------

//MAPA
//limites
#define LIMITEX 56 //tiene que
#define LIMITEY 26 //ser par
//estilo
#define ESQ_SI 201
#define ESQ_SD 187
#define ESQ_II 200
#define ESQ_ID 188
#define BAR_H 205
#define BAR_V 186

//MANZANA
#define APPLE 254

//SERPIENTE
//limite
#define LIMITESNK 150//crece +3
//estilo
#define LENGUA_AR 118
#define LENGUA_AB 94
#define LENGUA_IZQ 62
#define LENGUA_DER 60
#define CUERPO 219

//TECLAS
#define ESC 27
#define ARRIBA 72
#define ABAJO 80
#define IZQ 75
#define DER 77

#define TECLA_W 119
#define TECLA_A 97
#define TECLA_S 115
#define TECLA_D 100

//TIEMPO
#define FRAMERATE 16

//!-------------------------------ESTRUCTURAS------------------------------------
typedef struct
{
    int x;
    int y;
    char estilo;

} stManzana;

typedef struct
{

    int x;
    int movx;
    int y;
    int movy;
    char estilo;

} stSerpiente;

//!-------------------------------GLOBALES------------------------------------

stManzana manzana;
stSerpiente serpiente[LIMITESNK];

//!-------------------------------PTOTOTIPADO------------------------------------

void presentacionSnk();
void explicacionSnk();
void gameOver();
void cartel(char jugador[],int puntaje);
void crearMapaSnk(char mapa[LIMITEY][LIMITEX]);
void mostrarMapaSnk(char mapa[LIMITEY][LIMITEX]);
void generarSerpiente(int tamSnk);
void generarManzana();
void colocarEnMapa(char mapa[LIMITEY][LIMITEX],int tamSnk);
void input();
void moverSerpiente(int tamSnk);
void colision(int *gameover,int tamSnk);
int comerManzana(int *tamSnk);
void actualizarMapa(char mapa[LIMITEY][LIMITEX],int tamSnk);
void snakeIndividual(char jugador[],int *puntaje);
void snakeMultijugador(char jugador1[],int *puntaje1,char jugador2[],int *puntaje2);


#endif // SNAKE_H_INCLUDED
