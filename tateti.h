#ifndef TATETI_H_INCLUDED
#define TATETI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define LIMITEY 5
#define LIMITEX 5

#define BAR_H 196
#define BAR_V 179

void presentacion();
void instrucciones();

void crearMapa(char mapa[LIMITEY][LIMITEX]);
void mostrarMapa(char mapa[LIMITEY][LIMITEX]);
void colocar(char mapa[LIMITEY][LIMITEX],char pos,char caracter);
void insertarNumero(char mapa[LIMITEY][LIMITEX],char caracter);
void verificacion(char mapa[LIMITEY][LIMITEX],char caracter,int *flag);
void turno(char jugador[],char mapa[LIMITEX][LIMITEY],char caracter,int *gameover);
void juegoTateti(char jugador1[],int *puntajeJug1,char jugador2[],int *puntajeJug2);

#endif // TATETI_H_INCLUDED
