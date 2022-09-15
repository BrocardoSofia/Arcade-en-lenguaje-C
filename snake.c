#include "snake.h"

void snakeMultijugador(char jugador1[],int *puntaje1,char jugador2[],int *puntaje2){


    presentacionSnk();
    system("pause");
    system("cls");
    explicacionSnk();
    snakeIndividual(jugador1,puntaje1);
    snakeIndividual(jugador2,puntaje2);

    presentacionSnk();
    printf("\n\t\t%s %d pts  -  %s %d pts\n",jugador1,*puntaje1,jugador2,*puntaje2);

    if(*puntaje1>*puntaje2){

        printf("\n\t\tGANADOR: %s con %d pts\n\n",jugador1,*puntaje1);

    }else if(*puntaje1==*puntaje2){

        printf("\n\t\tEMPATE: %s y %s con %d pts\n\n",jugador1,jugador2,*puntaje1);

    }else{

        printf("\n\t\tGANADOR: %s con %d pts\n\n",jugador2,*puntaje2);
    }

    system("pause");
    system("cls");
}

void snakeIndividual(char jugador[],int *puntaje)
{
    //variables
    char mapa[LIMITEY][LIMITEX];
    int tamSnk=3; //tamaño inicial
    int gameover=0; //0 sigue - 1 pierde

    //creacion y generacion
    crearMapaSnk(mapa);
    generarSerpiente(tamSnk);
    generarManzana();

    //colocacion en mapa
    colocarEnMapa(mapa,tamSnk);

    //cartel con nombre y puntaje
    cartel(jugador,*puntaje);

    //mostramos
    mostrarMapaSnk(mapa);
    system("pause");

    do
    {
        system("cls");

        //cartel con nombre y puntaje
        cartel(jugador,*puntaje);

        //mostramos
        mostrarMapaSnk(mapa);

        //pausa
        Sleep(FRAMERATE);

        //ingreso de movimiento
        input();

        //actualizacion del mapa
        actualizarMapa(mapa,tamSnk);

        //verificacion de colision
        colision(&gameover,tamSnk);

        //verificaion de comer manzana
        *puntaje+=comerManzana(&tamSnk);
    }
    while(gameover==0);

    sleep(1);
    system("cls");
    gameOver();
    cartel(jugador,*puntaje);
    printf("\n");
    system("pause");
    system("cls");

}

void presentacionSnk()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13 | BACKGROUND_INTENSITY);
    //swampland
    printf(" ______        ___   __        ________        ___   ___       ______       \n");
    printf("/_____/\\      /__/\\ /__/\\     /_______/\\      /___/\\/__/\\     /_____/\\      \n");
    printf("\\::::_\\/_     \\::\\_\\\\  \\ \\    \\::: _  \\ \\     \\::.\\ \\\\ \\ \\    \\::::_\\/_     \n");
    printf(" \\:\\/___/\\     \\:. `-\\  \\ \\    \\::(_)  \\ \\     \\:: \\/_) \\ \\    \\:\\/___/\\    \n");
    printf("  \\_::._\\:\\     \\:. _    \\ \\    \\:: __  \\ \\     \\:. __  ( (     \\::___\\/_   \n");
    printf("    /____\\:\\     \\. \\`-\\  \\ \\    \\:.\\ \\  \\ \\     \\: \\ )  \\ \\     \\:\\____/\\  \n");
    printf("    \\_____\\/      \\__\\/ \\__\\/     \\__\\/\\__\\/      \\__\\/\\__\\/      \\_____\\/  \n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
}

void explicacionSnk()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13 | BACKGROUND_INTENSITY);
    //small
    printf("  _               _                            _                         \n");
    printf(" (_)  _ _    ___ | |_   _ _   _  _   __   __  (_)  ___   _ _    ___   ___\n");
    printf(" | | | ' \\  (_-< |  _| | '_| | || | / _| / _| | | / _ \\ | ' \\  / -_) (_-<\n");
    printf(" |_| |_||_| /__/  \\__| |_|    \\_,_| \\__| \\__| |_| \\___/ |_||_| \\___| /__/\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);

    printf("\n1. Cada jugador jugara una partida\n");
    printf("\n2. El jugador que haya conseguido mas puntos, sera el ganador\n\n");

    system("pause");
    system("cls");

    printf("\nTeclas para mover a la serpiente\n");

    //smkeyboard
    printf("       ____                           ____          \n");
    printf("      ||w ||                         ||^ ||         \n");
    printf("      ||__||                         ||__||         \n");
    printf("      |/__\\|                         |/__\\|        \n");

    printf(" ____  ____  ____               ____  ____  ____            \n");
    printf("||a ||||s ||||d ||             ||< ||||v ||||> ||          \n");
    printf("||__||||__||||__||             ||__||||__||||__||          \n");
    printf("|/__\\||/__\\||/__\\|             |/__\\||/__\\||/__\\|     \n\n");

    system("pause");
    system("cls");
}

void gameOver(){

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
    //sub_cero
    printf(" ______     ______     __    __     ______      \n");
    printf("/\\  ___\\   /\\  __ \\   /\\ '-./  \\   /\\  ___\\     \n");
    printf("\\ \\ \\__ \\  \\ \\  __ \\  \\ \\ \\-./\\ \\  \\ \\  __\\    \n");
    printf(" \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \n");
    printf("  \\/_____/   \\/_/\\/_/   \\/_/  \\/_/   \\/_____/  \n");

    printf("    ______     __   __   ______     ______  \n");
    printf("   /\\  __ \\   /\\ \\ / /  /\\  ___\\   /\\  == \\  \n");
    printf("   \\ \\ \\/\\ \\  \\ \\ \\'/   \\ \\  __\\   \\ \\  __<   \n");
    printf("    \\ \\_____\\  \\ \\__|    \\ \\_____\\  \\ \\_\\ \\_\\ \n");
    printf("     \\/_____/   \\/_/      \\/_____/   \\/_/ /_/ \n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
}

void cartel(char jugador[],int puntaje)
{
    printf("\n\t%s : %d pts\n",jugador,puntaje);
}

void crearMapaSnk(char mapa[LIMITEY][LIMITEX])
{

    //dibujo del mapa segun las coordenadas (Y,X)
    for(int i=0; i<LIMITEY; i++) //contador del eje y
    {
        for(int j=0; j<LIMITEX; j++) //contador del eje x
        {
            if(i==0)
            {
                if(j==0)
                {
                    mapa[i][j]=ESQ_SI;
                }
                else if(j==LIMITEX-1)
                {
                    mapa[i][j]=ESQ_SD;
                }
                else
                {
                    mapa[i][j]=BAR_H;
                }
            }
            else if(i==LIMITEY-1)
            {
                if(j==0)
                {
                    mapa[i][j]=ESQ_II;
                }
                else if(j==LIMITEX-1)
                {
                    mapa[i][j]=ESQ_ID;
                }
                else
                {
                    mapa[i][j]=BAR_H;
                }
            }
            else
            {
                if(j==0 || j==LIMITEX-1)
                {
                    mapa[i][j]=BAR_V;
                }
                else
                {
                    mapa[i][j]=' ';
                }
            }
        }
    }
}

void mostrarMapaSnk(char mapa[LIMITEY][LIMITEX])
{

    //se recorre la matriz
    for(int i=0; i<LIMITEY; i++)
    {
        printf("\t");
        for(int j=0; j<LIMITEX; j++)
        {
            printf("%c",mapa[i][j]);
        }
        printf("\n");
    }

}

void generarSerpiente(int tamSnk)
{
    //se recorre el arreglo
    for(int i=0; i<LIMITESNK; i++)
    {
        if(i==0)  //la cabeza
        {
            //se le da una posicion inicial
            serpiente[i].x=LIMITEX/2;
            serpiente[i].y=LIMITEY/2;
            serpiente[i].estilo=LENGUA_DER;

            //valores iniciales de movimiento - hacia la derecha
            serpiente[i].movx=1;
            serpiente[i].movy=0;
        }
        else   //el resto del cuerpo
        {
            //se coloca el cuerpo de la serpiente hacia la izq
            serpiente[i].x=serpiente[i-1].x-1;
            serpiente[i].y=serpiente[i-1].y;
            serpiente[i].estilo=CUERPO;
        }
    }
}

void generarManzana()
{

    //generacion de la posicion x de la manzana
    manzana.x=rand() % (LIMITEX -  1);
    while(manzana.x==0)
    {
        manzana.x=rand() % (LIMITEX -  1);
    }

    //generacion de la posicion y de la manzana
    manzana.y=rand() % (LIMITEY - 1);
    while(manzana.y==0)
    {
        manzana.y=rand() % (LIMITEY - 1);
    }

    //estilo de la manzana
    manzana.estilo=APPLE;
}

void colocarEnMapa(char mapa[LIMITEY][LIMITEX],int tamSnk)
{
    //copiamos la serpiente en la matriz
    for(int i=0; i<tamSnk; i++)
    {
        mapa[serpiente[i].y][serpiente[i].x]=serpiente[i].estilo;
    }

    //copiamos la manzana en la matriz
    mapa[manzana.y][manzana.x]=manzana.estilo;

}

void input()
{
    char tecla;

    if(kbhit())
    {
        tecla=getch();
        if(tecla == -32)
        {
            tecla=getch();
            switch(tecla)
            {
            case ARRIBA:
                if(serpiente[0].movy!=1)
                {
                    serpiente[0].movx=0;
                    serpiente[0].movy=-1;
                    serpiente[0].estilo=LENGUA_AR;
                }
                break;

            case ABAJO:
                if(serpiente[0].movy!=-1)
                {
                    serpiente[0].movx=0;
                    serpiente[0].movy=1;
                    serpiente[0].estilo=LENGUA_AB;
                }
                break;

            case DER:
                if(serpiente[0].movx!=-1)
                {
                    serpiente[0].movx=1;
                    serpiente[0].movy=0;
                    serpiente[0].estilo=LENGUA_DER;
                }
                break;

            case IZQ:
                if(serpiente[0].movx!=1)
                {
                    serpiente[0].movx=-1;
                    serpiente[0].movy=0;
                    serpiente[0].estilo=LENGUA_IZQ;
                }
                break;
            }
        }
        else if(tecla>=97 && tecla<=122)
        {
            switch(tecla)
            {

            case TECLA_W:
                if(serpiente[0].movy!=1)
                {
                    serpiente[0].movx=0;
                    serpiente[0].movy=-1;
                    serpiente[0].estilo=LENGUA_AR;
                }
                break;

            case TECLA_S:
                if(serpiente[0].movy!=-1)
                {
                    serpiente[0].movx=0;
                    serpiente[0].movy=1;
                    serpiente[0].estilo=LENGUA_AB;
                }
                break;

            case TECLA_D:
                if(serpiente[0].movx!=-1)
                {
                    serpiente[0].movx=1;
                    serpiente[0].movy=0;
                    serpiente[0].estilo=LENGUA_DER;
                }
                break;

            case TECLA_A:
                if(serpiente[0].movx!=1)
                {
                    serpiente[0].movx=-1;
                    serpiente[0].movy=0;
                    serpiente[0].estilo=LENGUA_IZQ;
                }
                break;
            }
        }
    }
}

void moverSerpiente(int tamSnk)
{
    //cuerpo
    //traslada el ultimo eslabon a la posicion del siguiente sucesivamente
    for(int i=tamSnk-1; i>0; i--)
    {
        serpiente[i].x=serpiente[i-1].x;
        serpiente[i].y=serpiente[i-1].y;
    }

    //cabeza
    //la traslada a la pos segun la cual se indica por teclado
    serpiente[0].x += serpiente[0].movx;
    serpiente[0].y += serpiente[0].movy;
}

void colision(int *gameover,int tamSnk)
{
    //contra las paredes
    //verifica que las coordenadas de la cabeza no coincidas con las de los limites del mapa
    if(serpiente[0].x==0 || serpiente[0].x==LIMITEX-1 || serpiente[0].y==0 || serpiente[0].y==LIMITEY-1)
    {
        Beep(70,200);
        *gameover=1;
    }

    //contra si mismo
    //verifica que las coordenadas de la cabeza no coincidas con las de su cuerpo
    int i=1;
    while(i<tamSnk && *gameover==0)
    {

        if(serpiente[0].x==serpiente[i].x && serpiente[0].y==serpiente[i].y)
        {
            Beep(70,200);
            *gameover=1;
        }
        i+=1;
    }
}

int comerManzana(int *tamSnk)
{
    int puntaje=0;

    //verifica si las coordenadas de la cabeza coinciden con las de la manzana
    if(serpiente[0].x==manzana.x && serpiente[0].y==manzana.y)
    {

        Beep(600,80);
        *tamSnk+=3;
        puntaje=5;

        //se genera una nueva manzana
        generarManzana();
    }

    return puntaje;
}

void actualizarMapa(char mapa[LIMITEY][LIMITEX],int tamSnk)
{
    //reseteamos el mapa
    crearMapaSnk(mapa);

    //actualizamos la posicion de la serpiente
    moverSerpiente(tamSnk);

    //insertamos la serpiente con nueva posicion
    colocarEnMapa(mapa,tamSnk);
}
