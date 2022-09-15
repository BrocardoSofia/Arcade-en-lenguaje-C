#include "tateti.h"

void juegoTateti(char jugador1[],int *puntajeJug1,char jugador2[],int *puntajeJug2)
{
    //variables
    char mapa[LIMITEY][LIMITEX];
    char caracter1='O';
    char caracter2='X';
    int gameover=0; //0 sigue - 1 alguien gano
    int cantJugadas=0; // =8 empate
    int quienGano=0; //1er jug -  2do jug

    //inicializacion
    crearMapa(mapa);

    presentacion();
    system("pause");
    system("cls");
    instrucciones();

    //loop
    while(gameover==0 && cantJugadas<9)
    {
        //turno1
        turno(jugador1,mapa,caracter1,&gameover);
        quienGano=1;
        cantJugadas+=1;

        if(gameover==0 && cantJugadas<9)
        {
            //turno2
            turno(jugador2,mapa,caracter2,&gameover);
            quienGano=2;
            cantJugadas+=1;
        }
    }

    //presentacion final
    presentacion();

    //muestra el mapa por ultima vez unos segundos
    mostrarMapa(mapa);

    //determinacion de quien gano

    if(cantJugadas==9)
    {
        printf("\n\t%s %d - %d %s\n",jugador1,*puntajeJug1,*puntajeJug2,jugador2);
        printf("\n\t\t EMPATE\n\n");
    }
    else if(quienGano==1)
    {
        *puntajeJug1=1;
        printf("\n\t%s %d - %d %s\n",jugador1,*puntajeJug1,*puntajeJug2,jugador2);
        printf("\n\t   GANADOR %s\n\n",jugador1);
    }
    else
    {
        *puntajeJug2=1;
        printf("\n\t%s %d - %d %s\n",jugador1,*puntajeJug1,*puntajeJug2,jugador2);
        printf("\n\t   GANADOR %s\n\n",jugador2);
    }

    system("pause");
    system("cls");
}

void turno(char jugador[],char mapa[LIMITEX][LIMITEY],char caracter,int *gameover)
{
    //posicion donde se va a insertar la ficha
    int flag=0;

    printf("\t JUGADOR %s: %c\n",jugador,caracter);
    mostrarMapa(mapa);
    insertarNumero(mapa,caracter); //inlcuye verificacion de pos valida
    system("cls");

    //verificacion que no este ocupado el lugar por otra ficha
    verificacion(mapa,caracter,gameover);
}

void presentacion()
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13 | BACKGROUND_INTENSITY);
    //swampland
    printf(" _________    ________        _________    ______        _________    ________      \n");
    printf("/________/\\  /_______/\\      /________/\\  /_____/\\      /________/\\  /_______/\\     \n");
    printf("\\__.::.__\\/  \\::: _  \\ \\     \\__.::.__\\/  \\::::_\\/_     \\__.::.__\\/  \\__.::._\\/     \n");
    printf("   \\::\\ \\     \\::(_)  \\ \\       \\::\\ \\     \\:\\/___/\\       \\::\\ \\       \\::\\ \\      \n");
    printf("    \\::\\ \\     \\:: __  \\ \\       \\::\\ \\     \\::___\\/_       \\::\\ \\      _\\::\\ \\__   \n");
    printf("     \\::\\ \\     \\:.\\ \\  \\ \\       \\::\\ \\     \\:\\____/\\       \\::\\ \\    /__\\::\\__/\\  \n");
    printf("      \\__\\/      \\__\\/\\__\\/        \\__\\/      \\_____\\/        \\__\\/    \\________\\/  \n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
}

void instrucciones()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13 | BACKGROUND_INTENSITY);
    //small
    printf("  _               _                            _                         \n");
    printf(" (_)  _ _    ___ | |_   _ _   _  _   __   __  (_)  ___   _ _    ___   ___\n");
    printf(" | | | ' \\  (_-< |  _| | '_| | || | / _| / _| | | / _ \\ | ' \\  / -_) (_-<\n");
    printf(" |_| |_||_| /__/  \\__| |_|    \\_,_| \\__| \\__| |_| \\___/ |_||_| \\___| /__/\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);


    printf("\n1. Los jugadores se turnaran para colocar las fichas\n");
    printf("2. El primero en hacer tres fichas consecutivas, gana\n\n");

    system("pause");
    system("cls");
}

void crearMapa(char mapa[LIMITEY][LIMITEX])
{
    int cont=49;

    for(int i=0; i<LIMITEY; i++)
    {

        for(int j=0; j<LIMITEX; j++)
        {

            if(j==1 || j==3)
            {
                mapa[i][j]=BAR_V;
            }
            else if(i==1 || i==3)
            {
                mapa[i][j]=BAR_H;
            }
            else
            {
                mapa[i][j]=cont;
                cont+=1;
            }
        }
    }
}
void mostrarMapa(char mapa[LIMITEY][LIMITEX])
{
    printf("\n");
    for(int i=0; i<LIMITEY; i++)
    {
        printf("\t");
        for(int j=0; j<LIMITEX; j++)
        {
            printf("  %c  ",mapa[i][j]);
        }
        printf("\n\n");
    }
}

void colocar(char mapa[LIMITEY][LIMITEX],char pos,char caracter)
{
    int i=0;
    int j=0;
    int flag=1; //0 posicion desocupada - 1 posicion ocupada

    for(int i=0; i<LIMITEY; i++)
    {
        for(int j=0; j<LIMITEX; j++)
        {
            if(mapa[i][j]==pos)
            {
                mapa[i][j]=caracter;
                flag=0;
            }
        }
    }
}
//!
void insertarNumero(char mapa[LIMITEY][LIMITEX],char caracter)
{
    int numIngresado;
    int pos=0;
    int flagIngreso=0; //0 valido - 1 no valido ingreso de pos
    int flagDisponibilidad=1; // 0 pos desocupada - 1 pos ocupada

    do
    {
        printf("Ingrese la posicion: ");
        fflush(stdin);
        scanf("%d",&numIngresado);

        switch(numIngresado)
        {
        case 1:
            pos=49;

            break;
        case 2:
            pos=50;

            break;
        case 3:
            pos=51;

            break;
        case 4:
            pos=52;

            break;
        case 5:
            pos=53;

            break;
        case 6:
            pos=54;

            break;
        case 7:
            pos=55;

            break;
        case 8:
            pos=56;

            break;
        case 9:
            pos=57;

            break;
        default:
            flagIngreso=1;
            break;
        }

        //si la pos es valida 1-9
        if(flagIngreso==0)
        {
            for(int i=0; i<LIMITEY; i++)
            {
                for(int j=0; j<LIMITEX; j++)
                {
                    if(mapa[i][j]==pos)
                    {
                        Beep(600,100);
                        mapa[i][j]=caracter;
                        flagDisponibilidad=0;
                    }
                }
            }
        }

        if(flagIngreso==1 || flagDisponibilidad==1){
            Beep(70,200);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
            printf("Posicion no valida\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
        }

    }while(flagIngreso==1 || flagDisponibilidad==1);
}

void verificacion(char mapa[LIMITEY][LIMITEX],char caracter,int *flag)
{
    for(int i=0; i<LIMITEX; i+=2)
    {
        //columnas
        if(mapa[0][i]==caracter && mapa[2][i]==caracter && mapa[4][i]==caracter)
        {
            *flag=1;
        }

        //filas
        if(mapa[i][0]==caracter && mapa[i][2]==caracter && mapa[i][4]==caracter)
        {
            *flag=1;
        }
    }

    //diagonal (\)
    if(mapa[0][0]==caracter && mapa[2][2]==caracter && mapa[4][4]==caracter)
    {
        *flag=1;
    }

    //diagonal (/)
    if(mapa[0][4]==caracter && mapa[2][2]==caracter && mapa[4][0]==caracter)
    {
        *flag=1;
    }
}
