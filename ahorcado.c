#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "pila.h"
#include "ahorcado.h"



void gameOverAhorcado()
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
}

void gotoxyAhorcado(int x, int y)//Posicion del cursor en la consola
{
    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);//contrlador de la consola

    COORD posicion;//estructura para las coordenadas
    posicion.X = x;
    posicion.Y = y;

    SetConsoleCursorPosition(consola, posicion);//situa el cursor en un punto de la consola
}

void juegoAhorcado(char nombre1[],char nombre2[], int *puntaje1, int *puntaje2)
{
    PlaySound(TEXT("pistaAhorcado.wav"),NULL,SND_ASYNC);

    tituloA();

    system("cls");
    *puntaje1=juego(nombre1, nombre2);

    *puntaje2=juego(nombre2, nombre1);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    rectanguloAhorcado();
    if(*puntaje1<*puntaje2)
    {
        gotoxyAhorcado(40,12);
        printf("GANO %s!!!\n", nombre1);
    }
    else if(*puntaje2<*puntaje1)
    {
        gotoxyAhorcado(40,12);
        printf("GANO %s!!!\n", nombre2);
    }
    else
    {
        gotoxyAhorcado(40,12);
        printf("EMPATE!!! o_o \n");
    }
    gotoxyAhorcado(101,29);
    printf(" ");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
    system("pause");

    system("cls");
    gameOverAhorcado();
    PlaySound(NULL, 0, 0);
}

void rectanguloAhorcado()
{

    for(int i=0;i<28; i++)
    {
        for(int j=0; j<100; j++)
        {
            if((j==0)||(j==99)||(i==0)||(i==27))
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

void tituloA()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    printf(" ________        ___   ___       ______        ______         ______        ________        ______        ______       \n");
    printf("/_______/\\      /__/\\ /__/\\     /_____/\\      /_____/\\       /_____/\\      /_______/\\      /_____/\\      /_____/\\      \n");
    printf("\\::: _  \\ \\     \\::\\ \\\\  \\ \\    \\:::_ \\ \\     \\:::_ \\ \\      \\:::__\\/      \\::: _  \\ \\     \\:::_ \\ \\     \\:::_ \\ \\     \n");
    printf(" \\::(_)  \\ \\     \\::\\/_\\ .\\ \\    \\:\\ \\ \\ \\     \\:(_) ) )_     \\:\\ \\  __     \\::(_)  \\ \\     \\:\\ \\ \\ \\     \\:\\ \\ \\ \\    \n");
    printf("  \\:: __  \\ \\     \\:: ___::\\ \\    \\:\\ \\ \\ \\     \\: __ `\\ \\     \\:\\ \\/_/\\     \\:: __  \\ \\     \\:\\ \\ \\ \\     \\:\\ \\ \\ \\   \n");
    printf("   \\:.\\ \\  \\ \\     \\: \\ \\\\::\\ \\    \\:\\_\\ \\ \\     \\ \\ `\\ \\ \\     \\:\\_\\ \\ \\     \\:.\\ \\  \\ \\     \\:\\/.:| |     \\:\\_\\ \\ \\  \n");
    printf("    \\__\\/\\__\\/      \\__\\/ \\::\\/     \\_____\\/      \\_\\/ \\_\\/      \\_____\\/      \\__\\/\\__\\/      \\____/_/      \\_____\\/  \n\n");
    system("pause");
    Beep(600,100);
}

int juego(char nombre[], char nombre2[])
{
    int puntaje;
    char name[50];
    char palabra[30];//palabra a adivinar

    strcpy(name,nombre);//copio el nombre del jugador
    strupr(name);//lo paso a mayuscula

    rectanguloAhorcado();
    gotoxyAhorcado(31,12);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    printf("%s ingrese una palabra: ", name);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | BACKGROUND_INTENSITY);
    fflush(stdin);//limpio el buffer
    gets(palabra);//guardo la palabra
    Beep(600,100);

    strupr(palabra);

    puntaje=adivina(nombre2, palabra);

    return puntaje;
}

int adivina(char nombre[], char palabra[])
{
    //declaro e inicializo los intentos y puntaje
    int puntaje=1200;
    int intentos=6;
    //declaro e inicializo la pila
    Pila pilita;
    inicpila(&pilita);

    int acierto=0;//si acerto o no (0 o 1)
    char letra;//letra a adivinar
    char letrasArray[27];//letras intentadas en el juego
    int validosLetras=0;//validos letras guardadas
    int flag;//para verificar si existe una letra
    int longitud=strlen(palabra);//la longitud de la palabra
    int win=0;//si gana pasa a 1
    char codigo[30]="";
    char mander;


    inicCodigo(longitud,codigo);

    do
    {
        system("cls");
        rectanguloAhorcado();
        muestraAhorcado(nombre,intentos,puntaje,codigo);

        do
        {
            gotoxyAhorcado(23,22);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
            printf("  Ingrese una letra: ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 | BACKGROUND_INTENSITY);
            fflush(stdin);
            scanf("%c", &mander);
            Beep(600,100);

            letra=toupper(mander);

            if(validosLetras!=0)
            {
                //si hay letras guardadas
                flag=verificaChar(letra, letrasArray, validosLetras);
                //verifico si ya ingreso esa letra
            }

            if(flag==1)
            {
                //si ya existe la letra notifico al usuario
                Beep(70,200);
                gotoxyAhorcado(25,24);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
                printf("ERROR: ya ingreso la letra %c", letra);
                gotoxyAhorcado(25,25);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
                system("pause");
            }
        }while(flag==1);

        acierto=buscarAdivinar(letra,&pilita,palabra,longitud);

        if(acierto==0)
        {
            puntaje-=200;//si no adivino resto 20pts
            intentos-=1;//y resto un intento
        }

        //guardo la letra e incremento los validos
        letrasArray[validosLetras]=letra;
        validosLetras++;

        pasaCodigo(pilita,letra,codigo, longitud);
        win=gana(codigo,longitud);

    }while((intentos!=0)&&(win==0));

    muestrapuntaje(nombre,puntaje);

    return puntaje;
}

void muestrapuntaje(char nombre[],int puntaje)
{
    system("cls");
    rectanguloAhorcado();
    gotoxyAhorcado(40,12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    printf("%s - %dpts\n", nombre, puntaje);
    gotoxyAhorcado(31,29);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
    system("pause");
    system("cls");
}

int gana(char codigo[30],int longitud)
{
    int flag=1;//inicializo en encontrado
    int i=0;

    while((i<longitud)&&(flag==1))
    {
        if(codigo[i]=='-')
        {
            flag=0;//si encuentra aunque sea un '-' sale con 0
        }
        i++;
    }

    return flag;
}

void pasaCodigo(Pila pilita,char letra,char codigo[30], int longitud)
{
    Pila aux;
    inicpila(&aux);

    for(int i=0; i<longitud; i++)
    {
        if(tope(&pilita)==1)
        {
            fflush(stdin);
            //si el tope es 1 paso la letra al array codigo
            codigo[i]=letra;
        }
        //desapilo la pila
        apilar(&aux, desapilar(&pilita));
    }
}

void inicCodigo(int longitud,char codigo[30])
{
    for(int i=0; i<longitud; i++)
    {
        codigo[i]='-';
    }
}

int buscarAdivinar(char letra,Pila *pilita,char palabra[],int longitud)
{
    int acierto=0;
    Pila basura;
    Pila aux;
    inicpila(&basura);
    inicpila(&aux);

    //vacio la pila
    while(!pilavacia(pilita))
    {
        apilar(&basura, desapilar(pilita));
    }

    for(int i=0; i<longitud; i++)
    {
        //reccorro la palabra y guardo los aciertos de esa letra en una pila
        if(letra==palabra[i])
        {
            apilar(&aux,1);//si esta en la palabra apilo un 1
            acierto=1;//y aviso que hay al menos un acierto
        }
        else
        {
            //sino apilo un 0
            apilar(&aux, 0);
        }
    }

    //paso la pila a pilita
    while(!pilavacia(&aux))
    {
        apilar(pilita, desapilar(&aux));
    }

    return acierto;
}

void muestraAhorcado(char nombre[],int intentos,int puntaje,char codigo[30])
{
    char name[50];
    strcpy(name, nombre);
    strupr(name);

    gotoxyAhorcado(38,3);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    printf("   JUGANDO: %s\n\n", name);
    gotoxyAhorcado(23,7);
    printf("   Intentos:%d                        Puntaje:%d\n", intentos, puntaje);
    gotoxyAhorcado(23,10);
    printf("    ---------------\n");
    gotoxyAhorcado(23,11);
    printf("   |               |\n");
    verIntentos(intentos);
    gotoxyAhorcado(23,15);
    printf("   |\n");
    gotoxyAhorcado(23,16);
    printf("   |-------------------         %s", codigo);
}


void verIntentos(int intentos)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | BACKGROUND_INTENSITY);
    switch(intentos)
    {
        case 0:
            gotoxyAhorcado(23,12);
            printf("   |               O \n");
            gotoxyAhorcado(23,13);
            printf("   |              /|\\ \n");
            gotoxyAhorcado(23,14);
            printf("   |              / \\ \n");
            break;
        case 1:
            gotoxyAhorcado(23,12);
            printf("   |               O \n");
            gotoxyAhorcado(23,13);
            printf("   |              /|\\ \n");
            gotoxyAhorcado(23,14);
            printf("   |              /  \n");
            break;
        case 2:
            gotoxyAhorcado(23,12);
            printf("   |               O \n");
            gotoxyAhorcado(23,13);
            printf("   |              /|\\ \n");
            gotoxyAhorcado(23,14);
            printf("   | \n");
            break;
        case 3:
            gotoxyAhorcado(23,12);
            printf("   |               O \n");
            gotoxyAhorcado(23,13);
            printf("   |              /| \n");
            gotoxyAhorcado(23,14);
            printf("   | \n");
            break;
        case 4:
            gotoxyAhorcado(23,12);
            printf("   |               O \n");
            gotoxyAhorcado(23,13);
            printf("   |               | \n");
            gotoxyAhorcado(23,14);
            printf("   | \n");
            break;
        case 5:
            gotoxyAhorcado(23,12);
            printf("   |               O \n");
            gotoxyAhorcado(23,13);
            printf("   | \n");
            gotoxyAhorcado(23,14);
            printf("   | \n");
            break;
        case 6:
            gotoxyAhorcado(23,12);
            printf("   | \n");
            gotoxyAhorcado(23,13);
            printf("   | \n");
            gotoxyAhorcado(23,14);
            printf("   | \n");
            break;
    }
}

int verificaChar(char letra, char letrasArray[], int validosLetras)
{
    int flag=0;
    int i=0;

    while((flag==0)&&(i<validosLetras))
    {
        //recorro la palabra y busco las coincidencias
        if(letra==letrasArray[i])
        {
            flag=1;//levanto la bandera
        }
        i++;//incremento el contador
    }

    return flag;
}
