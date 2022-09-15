#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "batallaNaval.h"

void juegoBatallaNaval(char player1[],char player2[],int *puntaje1,int *puntaje2)
{
    int mapa1[10][10]= {0};//mapa clave para jugador2
    int mapa2[10][10]= {0};//mapa clave para jugador1
    char viewMapa1[10][10]= {0};//mapa char para jugador1 || vinculado con el mapa1
    char viewMapa2[10][10]= {0};//mapa char para jugador1 || vinculado con el mapa2
    char name1[30];
    char name2[30];

    //copio los nombres a otra variable
    strcpy(name1, player1);
    strcpy(name2, player2);

    //los pongo en mayuscula
    strupr(name1);
    strupr(name2);

    //inicializo los mapas char
    inicializacionChar(viewMapa1);
    inicializacionChar(viewMapa2);

    //funciones del juego

    PlaySound(TEXT("pistaBatallaNaval.wav"),NULL,SND_ASYNC);
    mensajeInicio();//mensaje inicio
    cargaDeMapas(mapa1,mapa2, viewMapa1, viewMapa2, name1, name2);//carga mapas claves


    //inicializo los mapas char
    inicializacionChar(viewMapa1);
    inicializacionChar(viewMapa2);

    //INICIA JUEGO
    //TURNO JUGADOR 1
    system("cls");//limpio pantalla
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    rectangulo();
    gotoxy(40,12);
    printf("TURNO DE %s", name1);
    gotoxy(101,29);
    printf(" ");
    system("pause");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
    Beep(600,100);
    *puntaje1=iniciaJuego(mapa2,viewMapa2,name1);//jugador 1

    //MUESTRO PUNTAJE FINAL DEL JUGADOR 1
    system("cls");//limpio pantalla
    rectangulo();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    gotoxy(40,12);
    printf("%s - %d pts", name1, *puntaje1);
    gotoxy(101,29);
    printf(" ");
    system("pause");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
    Beep(600,100);

    //TURNO JUGADOR2
    system("cls");//limpio pantalla
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    rectangulo();
    gotoxy(40,12);
    printf("TURNO DE %s", name2);
    gotoxy(101,29);
    printf(" ");
    system("pause");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
    Beep(600,100);
    *puntaje2=iniciaJuego(mapa1,viewMapa1,name2);//jugador 2

    //PUNTAJE JUGADOR 2
    system("cls");//limpio pantalla
    rectangulo();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    gotoxy(40,12);
    printf("%s - %d pts", name2, *puntaje2);
    gotoxy(101,29);
    printf(" ");
    system("pause");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
    Beep(600,100);

    system("cls");
    rectangulo();
    if(*puntaje1<*puntaje2)
    {
        gotoxy(40,12);
        printf("GANO %s!!!\n", name1);
    }
    else if(*puntaje2<*puntaje1)
    {
        gotoxy(40,12);
        printf("GANO %s!!!\n", name2);
    }
    else
    {
        gotoxy(40,12);
        printf("EMPATE!!! o_o \n");
    }
    gotoxy(101,29);
    printf(" ");

    system("pause");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
    Beep(600,100);
    system("cls");

    bye();
    PlaySound(NULL, 0, 0);
}

/** JUEGO!!
**/
void mensajeInicio()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    printf("  _______        ________        _________    ________        __            __            ________       \n");
    printf("/_______/\\      /_______/\\      /________/\\  /_______/\\      /_/\\          /_/\\          /_______/\\      \n");
    printf("\\::: _  \\ \\     \\::: _  \\ \\     \\__.::.__\\/  \\::: _  \\ \\     \\:\\ \\         \\:\\ \\         \\::: _  \\ \\     \n");
    printf(" \\::(_)  \\/_     \\::(_)  \\ \\       \\::\\ \\     \\::(_)  \\ \\     \\:\\ \\         \\:\\ \\         \\::(_)  \\ \\    \n");
    printf("  \\::  _  \\ \\     \\:: __  \\ \\       \\::\\ \\     \\:: __  \\ \\     \\:\\ \\____     \\:\\ \\____     \\:: __  \\ \\   \n");
    printf("   \\::(_)  \\ \\     \\:.\\ \\  \\ \\       \\::\\ \\     \\:.\\ \\  \\ \\     \\:\\/___/\\     \\:\\/___/\\     \\:.\\ \\  \\ \\  \n");
    printf("    \\_______\\/      \\__\\/\\__\\/        \\__\\/      \\__\\/\\__\\/      \\_____\\/      \\_____\\/      \\__\\/\\__\\/  \n");
    printf("              ___   __        ________        __   __       ________        __           \n");
    printf("             /__/\\ /__/\\     /_______/\\      /_/\\ /_/\\     /_______/\\      /_/\\          \n");
    printf("             \\::\\_\\\\  \\ \\    \\::: _  \\ \\     \\:\\ \\\\ \\ \\    \\::: _  \\ \\     \\:\\ \\         \n");
    printf("              \\:. `-\\  \\ \\    \\::(_)  \\ \\     \\:\\ \\\\ \\ \\    \\::(_)  \\ \\     \\:\\ \\        \n");
    printf("               \\:. _    \\ \\    \\:: __  \\ \\     \\:\\_/.:\\ \\    \\:: __  \\ \\     \\:\\ \\____   \n");
    printf("                \\. \\`-\\  \\ \\    \\:.\\ \\  \\ \\     \\ ..::/ /     \\:.\\ \\  \\ \\     \\:\\/___/\\  \n");
    printf("                 \\__\\/ \\__\\/     \\__\\/\\__\\/      \\___/_(       \\__\\/\\__\\/      \\_____\\/  \n");
    printf("\n            #\n            #|\n            #|#\n            #|##\n           #|###\n            #|####");
    printf("\n            #|#####\n            #|######\n          #########################\n           _______________________");
    printf("\n            ####/)###############\n             ###(/##############\n              #################\n               ###############\n");
    system("pause");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
    Beep(600,100);
    system("cls");
}

//carga de mapas clave
void cargaDeMapas(int mapaClave1[10][10], int mapaClave2[10][10], char mapaVer1[10][10], char mapaVer2[10][10], char name1[], char name2[])
{
    mensaje(name1,name2);//mensaje para el jugador1
    cargarClave(mapaClave1, name1, name2, mapaVer1);

    //limpio pantalla
    system("cls");

    mensaje(name2,name1);//mensaje para el jugador2
    cargarClave(mapaClave2, name2, name1, mapaVer2);
}

void titulosCarga(int matrix[10][10], char mapaVer[10][10], char jugadorCarga[], char jugadorMapa[], int fichasTotal)
{
    //titulos
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    rectangulo();
    gotoxy(36,2);
    printf(" ------------------------ \n");
    gotoxy(36,3);
    printf("|      TURNO DE %s    |\n", jugadorCarga);
    gotoxy(36,4);
    printf("|CARGANDO MAPA PARA %s|\n", jugadorMapa);
    gotoxy(36,5);
    printf(" ------------------------ \n");

    gotoxy(36,7);
    printf("Fichas disponibles = %d", fichasTotal);

    mapaClaveAVer(mapaVer, matrix);//actualizo mapa a ver
    mostrarTableroChar(mapaVer);//muestro tablero actualizado
}

void cargarClave(int matrix[10][10], char jugadorCarga[], char jugadorMapa[], char mapaVer[10][10])
{
    //declaro las fichas
    int fichasTotal=10;//contador de fichas totales
    int fichaActual;//fichas seleccionadas

    while(fichasTotal>0)
    {
        system("cls");
        titulosCarga(matrix, mapaVer, jugadorCarga, jugadorMapa, fichasTotal);
        gotoxy(36,23);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
        printf("Seleccionar de 2 a 5 fichas\n");

        gotoxy(36,24);
        printf("Cuantas fichas va a colocar?");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | BACKGROUND_INTENSITY);
        fflush(stdin);//limpio el buffer
        gotoxy(36,25);
        scanf("%d", &fichaActual);
        Beep(600,100);

        if((fichaActual<2)||(fichaActual>5))
        {
            Beep(70,200);//sonido
            gotoxy(36,26);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
            printf("ERROR. \nLas fichas deben ser entre 2 y 5");
            gotoxy(36,27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
            system("pause");
            Beep(600,100);
            system("cls");
        }
        else if((fichasTotal-fichaActual)==1)
        {
            Beep(70,200);//sonido
            gotoxy(36,26);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
            printf("ERROR. \nNo puede quedar solo 1 ficha\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
            gotoxy(36,27);
            system("pause");
            Beep(600,100);
            system("cls");
        }
        else
        {
            //limpiar pantalla
            system("cls");
            //colocar fichas
            titulosCarga(matrix, mapaVer, jugadorCarga, jugadorMapa, fichasTotal);
            cargarFichas(matrix, mapaVer, fichaActual, fichasTotal, jugadorCarga, jugadorMapa);
            fichasTotal-=fichaActual; //decremento las fichas totales
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
    system("cls");
    titulosCarga(matrix, mapaVer, jugadorCarga, jugadorMapa, fichasTotal);
    system("pause");
    Beep(600,100);
}



void cargarFichas(int matrix[10][10], char mapaVer[10][10], int fichas, int fichasTotal, char jugadorCarga[], char jugadorMapa[])
{
    int flag=0;//bandera para el ciclo
    int fila;
    int columna;
    char direccion;
    int up,down,right,left;

    fila=verificarFila();//verifico la fila
    columna=verificarColumna(matrix,fila);//verifico la columna
    system("cls");//limpio pantalla

    //marcar en mapa
    matrix[fila][columna]=-1;//marco el barco en el mapa

    while(flag==0)
    {
        //vuelvo a cargar el mapa para ver la posicion actual
        titulosCarga(matrix, mapaVer, jugadorCarga, jugadorMapa, fichasTotal);
        //muestro las coordenadas
        gotoxy(36,23);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
        printf("Coordenadas: ");
        gotoxy(36,24);
        printf("            fila-%d", fila+1);
        gotoxy(36,25);
        printf("         columna-%d", columna+1);
        //pregunto a que direccion coloco el resto de las fichas
        gotoxy(36,27);
        printf("Donde colocar el resto de las fichas?");
        gotoxy(36,28);
        printf("                ____    ");
        gotoxy(36,29);
        printf("               ||w ||    ");
        gotoxy(36,30);
        printf("               ||__||    ");
        gotoxy(36,31);
        printf("               |/__\\|   ");
        gotoxy(36,32);
        printf("          ____  ____  ____  ");
        gotoxy(36,33);
        printf("         ||a ||||s ||||d ||");
        gotoxy(36,34);
        printf("         ||__||||__||||__||");
        gotoxy(36,35);
        printf("         |/__\\||/__\\||/__\\|");
        gotoxy(36,36);
        fflush(stdin);//limpio el buffer
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | BACKGROUND_INTENSITY);
        scanf("%c", &direccion);
        Beep(600,100);
        gotoxy(36,37);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
        system("pause");
        Beep(600,100);

        //verifico si entran las fichas
        //paso fichas -1 para el tamaño de los lugares que faltan
        up=validacionColumnaUp(matrix,fichas-1,fila,columna);
        down=validacionColumnaDown(matrix,fichas-1,fila,columna);
        right=validacionColumnaRight(matrix,fichas-1,fila,columna);
        left=validacionColumnaLeft(matrix, fichas-1,fila,columna);


        if(((direccion=='w')&&(up))||((direccion=='s')&&(down))||((direccion=='d')&&(right))||((direccion=='a')&&(left)))
        {
            cargarTocados(matrix,fila,columna);
            colocarBarcos(matrix,fichas,fila,columna,direccion);
            flag=1;
        }
        else
        {
            Beep(70,200);//sonido
            gotoxy(36,39);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
            printf("\n\nERROR: Direccion invalida\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
            system("pause");
            Beep(600,100);
        }
    }
}

void colocarBarcos(int matrix[10][10], int fichas, int filas, int columnas, char dir)
{
    int limite;
    if(dir=='w')
    {
        //cargar fichas hacia arriba
        limite=(filas-fichas);
        filas-=1;
        for(int i=filas; i>limite; i--)
        {
            matrix[i][columnas]=-1;//cargo barco
            cargarTocados(matrix,i,columnas);//actualizo tocados
        }
    }
    else if(dir=='s')
    {
        limite=(filas+fichas)-1;

        /////////////////////////////////////////////////////////////////PROBLEMA EN LA 0-0
        //cargar fichas hacia abajo
        for(int i=limite; i>filas; i--)
        {
            matrix[i][columnas] = -1;//cargo barco
            cargarTocados(matrix,i,columnas);//actualizo tocados
        }
    }
    else if(dir=='d')
    {
        limite=(columnas+fichas);
        columnas+=1;

        ////////////////////////////////////////////////////////////////////////////////
        //cargar fichas hacia la derecha
        for(int i=columnas; i<limite; i++)
        {
            matrix[filas][i]=-1;//cargo barco
            cargarTocados(matrix,filas,i);//actualizo tocados
        }
    }
    else
    {
        columnas-=1;
        limite=(columnas-fichas)+1;
        //cargar fichas hacia la izquierda
        for(int i=columnas; i>limite; i--)
        {
            matrix[filas][i]=-1;//cargo barco
            cargarTocados(matrix,filas,i);//actualizo tocados
        }
    }


}

void cargarTocados(int matrix[10][10], int fila, int columna)
{
    //declaro los valores de los alrededores
    //resto o - uno porque el uruario escribio la fila mas 1 y otro por la posicion de tocado
    int filaArriba=fila-1;
    int filaAbajo=fila+1;
    int columnaDerecha=columna+1;
    int columnaIzquierda=columna-1;

    if((filaArriba>=0)&&(matrix[filaArriba][columna] == 0))
    {
        matrix[filaArriba][columna]=1;//arriba
    }
    if((filaAbajo<10)&&(matrix[filaAbajo][columna] == 0))
    {
        matrix[filaAbajo][columna]=1;//abajo
    }
    if((columnaDerecha<10)&&(matrix[fila][columnaDerecha] == 0))
    {
        matrix[fila][columnaDerecha]=1;//derecha
    }
    if((columnaIzquierda>=0)&&(matrix[fila][columnaIzquierda] == 0))
    {
        matrix[fila][columnaIzquierda]=1;//izquierda
    }
}

//validacion de fila y columna
int verificarFila()
{
    int fila;
    int flag = 0;

    while(flag == 0)
    {
        //pido el valor de la fila
        gotoxy(36,23);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
        printf("COORDENADAS");
        gotoxy(36,24);
        printf("-----------");
        gotoxy(36,25);
        printf("Ingrese fila: ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | BACKGROUND_INTENSITY);
        fflush(stdin);
        scanf("%d", &fila);
        Beep(600,100);

        //verifico la fila
        if((fila > 10)||(fila < 0))
        {
            Beep(70,200);//sonido
            gotoxy(36,26);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
            printf("\nERROR: valor fuera de rango");
            gotoxy(36,27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
            system("pause");
            Beep(600,100);
        }
        else
        {
            flag = 1;//verifica y sale del ciclo
        }
    }
    return fila-1;//resto 1 para la posicion
}

int verificarColumna(int matrix[10][10], int fila)
{
    int flag=0;
    int columna;
    while(flag == 0)
    {
        //pregunto por la columna
        gotoxy(36,27);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
        printf("Ingrese columna: ");
        fflush(stdin);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | BACKGROUND_INTENSITY);
        scanf("%d", &columna);
        Beep(600,100);
        gotoxy(36,28);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
        system("pause");
        Beep(600,100);

        //verifico la columna
        if(((columna > 10)||(columna < 0))||(matrix[fila][columna-1] != 0))
        {
            Beep(70,200);//sonido
            gotoxy(36,29);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
            printf("\nERROR: valor fuera de rango\n");//mensaje de error
            gotoxy(36,30);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
            system("pause");
            Beep(600,100);
        }
        else
        {
            flag = 1;//la columna verifico
        }
    }
    return columna-1;//resto 1 para ver la posicion
}

//mensaje jugador
void mensaje(char name1[], char name2[])
{
    char mander;

    rectangulo();
    gotoxy(30,8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    printf("TURNO DE %s    ", name1);
    gotoxy(30,9);
    printf("CARGAR MAPA PARA %s", name2);

    gotoxy(30,13);
    printf("Ver instrucciones?(s/n)");
    fflush(stdin);
    gotoxy(30,14);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | BACKGROUND_INTENSITY);
    scanf("%c", &mander);
    Beep(600,100);
    system("cls");

    if(mander=='s')
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
        rectangulo();
        gotoxy(12,5);
        printf("  _               _                            _                         ");
        gotoxy(12,6);
        printf(" (_)  _ _    ___ | |_   _ _   _  _   __   __  (_)  ___   _ _    ___   ___");
        gotoxy(12,7);
        printf(" | | | ' \\  (_-< |  _| | '_| | || | / _| / _| | | / _ \\ | ' \\  / -_) (_-<");
        gotoxy(12,8);
        printf(" |_| |_||_| /__/  \\__| |_|    \\_,_| \\__| \\__| |_| \\___/ |_||_| \\___| /__/");
        gotoxy(12,10);
        printf("1%c Cargar los mapas con los barcos", 167);
        gotoxy(12,11);
        printf("2%c Jugar con el mapa cargado por el otro jugador", 167);
        gotoxy(12,13);
        printf("Puntaje:");
        gotoxy(18,14);
        printf("0pts - seleccionaste el barco");
        gotoxy(18,15);
        printf("1pts - tocaste el barco");
        gotoxy(18,16);
        printf("2pts - tocaste agua");
        gotoxy(12,18);
        printf("Gana el jugador con menos puntos al final de la partida");
        gotoxy(12,19);
        printf("Suerte!!");
        gotoxy(12,21);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
        system("pause");
        Beep(600,100);
        system("cls");
    }

}

//JUGAR
int iniciaJuego(int matrix[10][10], char matrixChar[10][10], char jugador[])
{
    int puntaje=0;//puntaje
    int num=0;//para verificar los barcos
    int encontrados=0;//sale del ciclo cuando encuentre todos los barcos
    int flag=0;//bandera para validacion de columnas y filas
    int fila;
    int columna;
    char caracter=167;

    while(encontrados<10)
    {
        system("cls");
        //titulo turno jugador
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
        rectangulo();
        gotoxy(36,2);
        printf(" ---------------------- ");
        gotoxy(36,3);
        printf("|    TURNO DE %s    |", jugador);
        gotoxy(36,4);
        printf(" ---------------------- ");

        //muestro puntaje
        gotoxy(36,6);
        printf("Puntaje = %d", puntaje);
        gotoxy(36,8);
        printf("%d barcos encontrados de %d", encontrados, 10);

        //muestro mapa
        mostrarTableroChar(matrixChar);

        while(flag==0)
        {
            gotoxy(36,23);
            printf("COORDENADAS");
            gotoxy(36,24);
            printf("-----------");
            gotoxy(36,25);
            printf("Ingrese fila: ");
            fflush(stdin);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | BACKGROUND_INTENSITY);
            scanf("%d", &fila);
            Beep(600,100);

            if((fila>10)||(fila<0))
            {
                Beep(70,200);//sonido
                gotoxy(36,26);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
                printf("\nERROR. Debe ser un numero del 1 al 10.");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
                system("pause");
                Beep(600,100);
            }
            else
            {
                flag=1;
            }
        }

        //reinicio la bandera
        flag=0;

        while(flag == 0)
        {
            gotoxy(36,26);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
            printf("Ingrese columna: ");
            fflush(stdin);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | BACKGROUND_INTENSITY);
            scanf("%d", &columna);
            Beep(600,100);
            gotoxy(36,27);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
            system("pause");
            Beep(600,100);

            //verifico si la columna es valida
            if((columna > -1)&&(columna < 11)&&(matrixChar[fila-1][columna-1] == caracter))
            {
                flag = 1;
            }
            else if((columna<0)||(columna>10))
            {
                Beep(70,200);//sonido
                gotoxy(36,28);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
                printf("ERROR: valor fuera de rango");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
                gotoxy(36,29);
                system("pause");
                Beep(600,100);
            }
        }
        flag=0;//reinicio nuevamente la bandera

        num = actualizaMapa(matrix,matrixChar,fila-1,columna-1);
        if(num==0)
        {
            encontrados++;//si es igual a 0 encontro un barco
        }
        else
        {
            puntaje+=num;//sino no, y suma al puntaje
        }
    }

    return puntaje;//retorno el puntaje acumulado
}

/* PARAMETROS
arreglo[10][10] => arreglo del tablero
ficha => tamaño
fila => posicion de fila
columna => posicion de columna
*/
//verifico las filas de abajo
int validacionColumnaDown(int arreglo[10][10], int ficha, int fila, int columna)
{
    int flag=1;//inicializo la bandera en 0
    int filaLimite=fila+ficha;//declaro el limite

    if(filaLimite<10)//veo si el limite esta dentro de la cuadricula de 10*10
    {
        while((flag==1)&&(fila<filaLimite))//mientras estoy en agua y la fila es menor al limite
        {
            if((arreglo[fila+1][columna]==0))
            {
                //en esa posicion hay agua asi que busco en la siguiente
                fila++;
            }
            else
            {
                //hay tocado o barco
                //retorna que no se pueden poner tantas fichas hacia arriba
                flag=0;
            }
        }
    }
    else
    {
        flag=0;//el limite se encuentra fuera de la cuadricula de 10*10
    }
    return flag;
}

//verifico en las filas de arriba
int validacionColumnaUp(int arreglo[10][10], int ficha, int fila, int columna)
{
    int flag=1;//inicializo la bandera en 0
    int filaLimite=fila-ficha;//declaro el limite

    if(filaLimite>=0)//veo si el limite esta dentro de la cuadricula de 10*10
    {
        while((flag==1)&&(fila>filaLimite))//mientras estoy en agua y la fila es menor al limite
        {
            if((arreglo[fila-1][columna]==0))
            {
                //en esa posicion hay agua asi que busco en la siguiente
                fila--;
            }
            else
            {
                //hay tocado o barco
                //retorna que no se pueden poner tantas fichas hacia arriba
                flag=0;
            }
        }
    }
    else
    {
        flag=0;//el limite se encuentra fuera de la cuadricula de 10*10
    }
    return flag;
}

//verifico las columnas a la derecha
int validacionColumnaRight(int arreglo[10][10], int ficha, int fila, int columna)
{
    int flag=1;//inicializo la bandera en 0
    int columnaLimite=columna+ficha;//declaro el limite

    if(columnaLimite<10)//veo si el limite esta dentro de la cuadricula de 10*10
    {
        while((flag==1)&&(columna<columnaLimite))//mientras estoy en agua y la fila es menor al limite
        {
            if((arreglo[fila][columna+1]==0))
            {
                //en esa posicion hay agua asi que busco en la siguiente
                columna++;
            }
            else
            {
                //hay tocado o barco
                //retorna que no se pueden poner tantas fichas hacia arriba
                flag=0;
            }
        }
    }
    else
    {
        flag=0;//el limite se encuentra fuera de la cuadricula de 10*10
    }


    return flag;
}


//verifico las columnas a la izquierda
int validacionColumnaLeft(int arreglo[10][10], int ficha, int fila, int columna)
{
    int flag=1;//inicializo la bandera en 0
    int columnaLimite=columna-ficha;//declaro el limite

    if(columnaLimite>=0)//veo si el limite esta dentro de la cuadricula de 10*10
    {
        while((flag==1)&&(columna>columnaLimite))//mientras estoy en agua y la fila es menor al limite
        {
            if((arreglo[fila][columna-1]==0))
            {
                //en esa posicion hay agua asi que busco en la siguiente
                columna--;
            }
            else
            {
                //hay tocado o barco
                //retorna que no se pueden poner tantas fichas hacia arriba
                flag=0;
            }
        }
    }
    else
    {
        flag=0;//el limite se encuentra fuera de la cuadricula de 10*10
    }
    return flag;
}

/**Funcion carga mapa1
  recibe como parametro la matriz
  devuelve el puntaje
**/
int actualizaMapa(int arregloDatos[10][10], char arreglo[10][10], int fila, int columna)
{
    int puntaje;
    if(arregloDatos[fila][columna]==0)//es agua
    {
        arreglo[fila][columna]=177;//▒
        puntaje=2;
    }
    else if(arregloDatos[fila][columna]==1)//es tocado
    {
        arreglo[fila][columna]=42;//*
        puntaje=1;
    }
    else//es barco
    {
        arreglo[fila][columna]=219;//█
        puntaje=0;
    }
    return puntaje;
}

//FUNCIONES MOSTRAR
void mostrarTablero(int matrix[10][10])
{
    //recorro filas
    for(int i=0; i<12; i++)
    {
        //recorro columnas
        for(int j=0; j<11; j++)
        {
            if(j<10)//espacio donde se imprime la matriz
            {
                if(i==0)
                {
                    printf("%d ", j+1);//en la primera fila imprimo en pantalla los numeros de las columnas
                }
                else if(i==1)
                {
                    printf("--");//imprimo en pantalla un espacio entre las columnas y la matriz
                }
                else
                {
                    printf("%d ", matrix[i-2][j]);//muestro la matriz de enteros
                }
            }
            else
            {
                if(i>1)
                {
                    printf("| %d", i-1);//muestro las filas del lado derecho de la matriz
                }
            }

        }
        printf("\n");
    }
}

/**Funcion inicializar matriz view mapa en '-'
recibe como parametro la matriz
**/
void inicializacionChar(char arreglo[10][10])
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            arreglo[i][j]=167; //º
        }
    }
}

void mostrarTableroChar(char matrix[10][10])
{
    //recorro filas
    for(int i=0; i<12; i++)
    {
        gotoxy(36,i+10);
        //recorro columnas
        for(int j=0; j<11; j++)
        {
            if(j<10)
            {
                if(i==0)
                {
                    printf("%d ", j+1);//en la primera fila imprimo en pantalla los numeros de las columnas
                }
                else if(i==1)
                {
                    printf("--");//imprimo en pantalla un espacio entre las columnas y la matriz
                }
                else
                {
                    printf("%c ", matrix[i-2][j]);//muestro la matriz de caracteres
                }
            }
            else
            {
                if(i>1)
                {
                    printf("| %d", i-1);//muestro las filas del lado derecho de la matriz
                }
            }

        }
        printf("\n");//paso a la siguiente fila
    }
}

void bye()
{
    char f=176, d=220, u=223, l=219, w=177;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    printf(" ______     ______     __    __     ______      \n");
    printf("/\\  ___\\   /\\  __ \\   /\\ '-./  \\   /\\  ___\\     \n");
    printf("\\ \\ \\__ \\  \\ \\  __ \\  \\ \\ \\-./\\ \\  \\ \\  __\\    \n");
    printf(" \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \n");
    printf("  \\/_____/   \\/_/\\/_/   \\/_/  \\/_/   \\/_____/  \n");

    printf("    ______     __   __   ______     ______  \n");
    printf("   /\\  __ \\   /\\ \\ / /  /\\  ___\\   /\\  == \\  \n");
    printf("   \\ \\ \\/\\ \\  \\ \\ \\'/   \\ \\  __\\   \\ \\  __<   \n");
    printf("    \\ \\_____\\  \\ \\__|    \\ \\_____\\  \\ \\_\\ \\_\\ \n");
    printf("     \\/_____/   \\/_/      \\/_____/   \\/_/ /_/ \n\n");
    printf("                             %c%c%c%c%c\n",d,u,f,f,l);
    printf("                           %c%c%c%c%c%c%c\n",d,u,l,f,f,f,l);
    printf("                        %c%c%c%c%c%c%c%c%c%c\n",d,u,u,f,l,w,f,f,f,l);
    printf("             %c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,u,u,d,d,d,u,u,f,f,f,f,l,f,f,w,w,l);
    printf("            %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",l,f,w,w,w,u,d,u,f,f,f,f,f,f,f,f,f,f,f,f,f,l);
    printf("            %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",l,f,w,w,w,w,f,u,d,f,f,f,f,f,f,f,f,f,f,f,f,f,u,d);
    printf("            %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",l,f,w,w,w,w,w,f,f,f,f,f,f,f,f,f,l,f,l,f,f,f,f,f,u,d);
    printf("            %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",l,u,d,w,w,f,f,f,f,f,f,f,f,l,f,f,f,l,f,l,f,d,d,f,f,l);
    printf("            %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",l,l,f,f,u,f,f,f,f,f,f,f,f,f,f,l,f,f,f,f,f,l,d,l,l,f,f,l);
    printf("         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,u,f,l,f,f,f,f,f,f,f,f,f,f,f,d,u,l,l,f,f,f,f,f,u,u,f,f,l,w,w,w,d);
    printf("        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",u,f,f,f,f,l,f,f,f,f,f,f,f,d,f,l,l,l,l,l,d,f,f,f,f,f,f,f,d,u,u,u,u);
    printf("        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",f,f,f,f,f,l,f,f,f,f,f,d,u,f,f,f,u,u,u,f,f,f,f,d,l,u,w,w,f,l,u,u,d,d);
    printf("        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",f,f,f,f,f,f,l,f,d,d,u,f,f,f,f,f,f,f,f,f,f,f,w,w,l,f,u,d,u,d,w,w,w,w,u);
    printf("        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",f,f,f,f,f,f,f,l,f,f,f,f,f,f,f,f,f,d,f,f,f,f,d,u,f,f,f,l,w,w,u,d);
    printf("        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",f,f,f,f,f,f,f,f,u,d,f,f,f,f,f,f,f,f,u,u,u,u,f,f,f,d,u);

    system("pause");
    Beep(600,100);
}

void gotoxy(int x, int y)//Posicion del cursor en la consola
{
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);//contrlador de la consola

    COORD posicion;//estructura para las coordenadas
    posicion.X = x;
    posicion.Y = y;

    SetConsoleCursorPosition(consola, posicion);//situa el cursor en un punto de la consola
}


void rectangulo()
{

    for(int i=0;i<40; i++)
    {
        for(int j=0; j<100; j++)
        {
            if((j==0)||(j==99)||(i==0)||(i==39))
            {
                printf("%c",254);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }


}


void mapaClaveAVer(char mapaVer[10][10], int clave[10][10])
{
    //actualizo el mapa que ve a un mapa en char
    for(int i=0; i<10; i++)
    {
        //recorro filas
        for(int j=0; j<10; j++)
        {
            //recorro columnas
            if(clave[i][j]==0)//es agua
            {
                mapaVer[i][j]=167; //º
            }
            else if(clave[i][j]==1)//es tocado
            {
                mapaVer[i][j]=42;//*
            }
            else//es barco
            {
                mapaVer[i][j]=219;//█
            }
        }
    }
}
