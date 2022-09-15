#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#include "pila.h"
#include "snake.h"
#include "tateti.h"
#include "batallaNaval.h"
#include "ahorcado.h"

///-----------------------------------------ESTRUCTURAS----------------------------------------------------------

typedef struct
{
    int idJugador;
    int puntaje;
    char idPartida[20];

} stPuntaje;

typedef struct
{
    int idUsuario; //se calcula por computadora
    char nombre[20]; //no se puede repetir
    char clave[20];
    int activo;//1 si esta activo - 0 si esta inactivo

} stUsuario;

///---------------------------------------CREDITOS--------------------------------------------------------

// BATALLA NAVAL Y AHORCADO - BROCARDO SOFIA
// SNAKE Y TATETI - VANINA PINTOS

///------------------------------------------MAIN---------------------------------------------------------

int main()
{
    system("COLOR 87");
    //archivo de usuario
    char archiUsuarios[]="usuarios.info";
    int opcion=0; //opcion de menu
    int opcionJuego=0; //opcion de menu de juegos
    int opcionRanking=0; // opcion para ver ranking
    int flag=0; // flag de seguir con el incio de secion - 1 seguir

    //vairiables de info de usuario
    char nombre1[20]= {0};
    char nombre2[20]= {0};
    int puntaje1=0;
    int puntaje2=0;

    //estrcutura que carga los datos de la partida
    stPuntaje puntuacionFinal[2];

    //archivos
    char archiBatallaNaval[]="batallaNaval.info";
    char archiSnake[]="snake.info";
    char archiAhorcado[]="ahorcado.info";
    char archiTateti[]="tateti.info";

    //archivo seleccionado segun juego
    char archivo[50];
    char archivoRanking[50];

    //arreglo para organizar ranking
    stPuntaje arreglo[100];
    int validosArreglo=0;

    do
    {
        //musica general
        PlaySound(TEXT("pistaMenu.wav"),NULL,SND_ASYNC);

        menu();

        fflush(stdin);
        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
        case 0:
            break;

        case 1:
            registrarUsuario(archiUsuarios);
            break;

        case 2:
            printf("------------------------------\n");
            printf("          JUGADOR 1           \n");
            printf("------------------------------\n\n");
            system("pause");
            iniciarSesion(archiUsuarios,nombre1,puntuacionFinal[0].idJugador,&flag);

            if(flag==1)
            {
                flag=0; //se reinicia el valor de la flag

                printf("------------------------------\n");
                printf("          JUGADOR 2           \n");
                printf("------------------------------\n\n");
                system("pause");
                iniciarSesion(archiUsuarios,nombre2,puntuacionFinal[1].idJugador,&flag);

                if(flag==1)
                {

                    //se muestra menu de juegos y se selecciona su respectivo archivo
                    do
                    {
                        menuJuegos();

                        printf("Seleccione un juego: ");
                        fflush(stdin);
                        scanf("%d",&opcionJuego);

                        //anula sonido
                        PlaySound(NULL, 0, 0);

                        system("cls");

                        switch(opcionJuego)
                        {

                        case 0:
                            break;

                        case 1:
                            juegoBatallaNaval(nombre1,&puntaje1,nombre2,&puntaje2);
                            strcpy(archivo,archiBatallaNaval);
                            //batalla naval
                            break;
                        case 2:
                            snakeMultijugador(nombre1,&puntaje1,nombre2,&puntaje2);
                            strcpy(archivo,archiSnake);
                            //snake
                            break;
                        case 3:
                            juegoAhorcado(nombre1,&puntaje1,nombre2,&puntaje2);
                            strcpy(archivo,archiAhorcado);
                            //ahorcado
                            break;
                        case 4:
                            juegoTateti(nombre1,&puntaje1,nombre2,&puntaje2);
                            strcpy(archivo,archiTateti);
                            //tateti
                            break;
                        default:
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
                            printf("\n\t\tOpcion invalida\n\n");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);

                            break;
                        }

                        //guardamos los puntajes en el struct
                        puntuacionFinal[0].puntaje=puntaje1;
                        puntuacionFinal[1].puntaje=puntaje2;

                        //se guardan los datos
                        guardarPartida(archivo,puntuacionFinal);

                        //mostrarArchivo(archivo);

                        system("pause");
                        system("cls");
                    }
                    while(opcionJuego!=0);

                }
            }
            break;


        case 3:
            //RANKING
            printf("1. Ver ranking Batalla Naval\n");
            printf("2. Ver ranking Snake\n");
            printf("3. Ver ranking Ahorcado\n");
            printf("4. Ver ranking Tateti\n");

            printf("\nSeleccione una opcion: ");
            fflush(stdin);
            scanf("%d",&opcionRanking);

            while(opcionRanking!=1 && opcionRanking!=2 && opcionRanking!=3 && opcionRanking!=4)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
                printf("\n\nOpcion no valida.\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
                fflush(stdin);
                scanf("%d",&opcionRanking);
            }

            if(opcionRanking==1)
            {

                strcpy(archivoRanking,archiBatallaNaval);

            }
            else if(opcionRanking==2)
            {

                strcpy(archivoRanking,archiSnake);

            }
            else if(opcionRanking==2)
            {

                strcpy(archivoRanking,archiAhorcado);

            }
            else
            {

                strcpy(archivoRanking,archiTateti);
            }

            //se guarda doble
            mostrarArchivo(archivoRanking);

            printf("\n\n");

            cargarArreglo(archivoRanking,arreglo,&validosArreglo);

            for(int i=0; i<validosArreglo; i++)
            {
                printf("\nID: %d",arreglo[i].idJugador);
                printf("\nPUNTAJE: %d",arreglo[i].puntaje);
                printf("\n\n");
            }

            //!!-------------------------------------------
            //ordenamientoSeleccion(puntajes,validosRanking);
            //mostrarRanking(arreglo,validosArreglo);
            //!!-------------------------------------------

            break;

        default:

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
            printf("\n\n\t\tOpcion no valida.\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
            break;
        }

        system("pause");
        system("cls");

    }
    while(opcion!=0);

    return 0;
}

///-----------------------------------------FUNCIONES--------------------------------------------------------

void titulo()
{
    //isometric4
    printf("      ___           ___           ___           ___           ___           ___     \n");
    printf("     /  /\\         /  /\\         /  /\\         /  /\\         /  /\\         /  /\\    \n");
    printf("    /  /::\\       /  /::\\       /  /::\\       /  /::\\       /  /::\\       /  /::\\  \n");
    printf("   /  /:/\\:\\     /  /:/\\:\\     /  /:/\\:\\     /  /:/\\:\\     /  /:/\\:\\     /  /:/\\:\\  \n");
    printf("  /  /::\\ \\:\\   /  /::\\ \\:\\   /  /:/  \\:\\   /  /::\\ \\:\\   /  /:/  \\:\\   /  /::\\ \\:\\ \n");
    printf(" /__/:/\\:\\_\\:\\ /__/:/\\:\\_\\:\\ /__/:/ \\  \\:\\ /__/:/\\:\\_\\:\\ /__/:/ \\__\\:| /__/:/\\:\\ \\:\\ \n");
    printf(" \\__\\/  \\:\\/:/ \\__\\/~|::\\/:/ \\  \\:\\  \\__\\/ \\__\\/  \\:\\/:/ \\  \\:\\ /  /:/ \\  \\:\\ \\:\\_\\/\n");
    printf("      \\__\\::/     |  |:|::/   \\  \\:\\            \\__\\::/   \\  \\:\\  /:/   \\  \\:\\ \\:\\ \n");
    printf("      /  /:/      |  |:|\\/     \\  \\:\\           /  /:/     \\  \\:\\/:/     \\  \\:\\_\\/ \n");
    printf("     /__/:/       |__|:|~       \\  \\:\\         /__/:/       \\__\\::/       \\  \\:\\ \n");
    printf("     \\__\\/         \\__\\|         \\__\\/         \\__\\/            ~~         \\__\\/ \n");
}

void menu()
{
    titulo();

    printf("\t\t\t------------------------------\n");
    printf("\t\t\t          BIENVENIDO          \n");
    printf("\t\t\t------------------------------\n\n");

    printf("1. Registrarse\n");
    printf("2. Iniciar sesion\n");
    printf("3. Ver ranking\n");
    printf("\n0. Salir\n");
}

int posUsuario(char archiUsuarios[],char nombreIngresado[20])
{
    FILE *arch;
    stUsuario usuario;
    int existencia=-1;//-1 si no existe - x posicion de registro
    int contPosiciones=0; //contador de posiciones

    //apertura con permisos de lectura
    arch=fopen(archiUsuarios,"rb");

    if(arch!=NULL)
    {

        //recorre el archivo hasta llegar al final o encontrar el dato
        while(fread(&usuario,sizeof(stUsuario),1,arch)>0 && existencia==-1)
        {
            if(strcmp(usuario.nombre,nombreIngresado)==0)
            {
                //se le asigna la posicion correspondiente al dato
                existencia=contPosiciones;
            }
            //se incrementa el contador de posiciones
            contPosiciones+=1;
        }
    }

    //se cierra el archivo
    fclose(arch);

    return existencia;
}

void cargaDeUsuario(char archiUsuarios[],char nombreIngresado[20])
{
    FILE *arch;

    stUsuario usuario;
    stUsuario aux;

    int idGenerado=0;

    int existenciaId=0; //1 id ya existente - 0 inexistente

    char claveIngresada[20]= {0};
    char caracter;
    int i=0; //contador de borrado de contraseña

    int exito=0; //exito de escritura

    //ingreso de contraseña
    ingresoClave(claveIngresada);
    Beep(600,100);
    strcpy(usuario.clave,claveIngresada);

    //carga de los datos ya ingresados
    strcpy(usuario.nombre,nombreIngresado);

    //!generacion de id
    srand(time(NULL));

    arch=fopen(archiUsuarios,"rb");

    do
    {
        //generacion del numero
        idGenerado=rand() %  100000 + 10000;

        if(arch!=NULL)
        {
            //verificacion de existencia
            while(fread(&aux,sizeof(stUsuario),1,arch)>0)
            {
                if(aux.idUsuario==idGenerado)
                {
                    existenciaId=1;//se informa la existencia de ese id
                }
            }
        }
    }
    while(existenciaId==1);

    usuario.idUsuario=idGenerado;

    fclose(arch);

    //!--------------------------------------------

    //inicializacion de estado
    usuario.activo=1; //activo

    //guardar en el archivo
    arch=fopen(archiUsuarios,"ab");

    if(arch!=NULL)
    {
        exito=fwrite(&usuario,sizeof(stUsuario),1,arch);

        if(exito==1)
        {
            printf("\nUsuario resgistrado con exito!\n");
        }
        else
        {
            printf("\nError al registrarse, por favor intentelo de nuevo.\n");
        }
    }

    //cierre
    fclose(arch);
}

int  ingresoNombreUsuario(char archiUsuarios[],char nombreIngresado[20])
{
    int existenciaUsuario=-1;

    //ingreso de nombre de usuario
    printf("\nNombre de usuario: ");
    fflush(stdin);
    gets(nombreIngresado);

    //verificacion de nombre de usuario
    existenciaUsuario=posUsuario(archiUsuarios,nombreIngresado);

    return existenciaUsuario;
}

void registrarUsuario(char archiUsuarios[])
{
    char nombreIngresado[20]= {0};
    char claveIngresada[20]= {0};

    int existenciaUsuario=0;
    int control=1;

    //bucle de nombre de usuario
    while(control==1 && existenciaUsuario!=-1)
    {
        system("cls");

        printf("------------------------------\n");
        printf("         REGISTRARSE          \n");
        printf("------------------------------\n");

        //ingreso de nombre de usuario
        existenciaUsuario=ingresoNombreUsuario(archiUsuarios,nombreIngresado);

        //menu de opciones
        if(existenciaUsuario!=-1)
        {
            Beep(70,200);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
            printf("\nNombre de usuario ya registrado.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);

            printf("1. Ingresar otro nombre de usuario.\n");
            printf("0. Salir al menu principal.\n");

            fflush(stdin);
            scanf("%d",&control);

            while(control!=1 && control!=0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
                printf("Opcion no valida. Vuelva  ingresar.\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
                fflush(stdin);
                scanf("%d",&control);
            }
        }
        else
        {
            Beep(600,100);
            //ingreso de contraseña
            cargaDeUsuario(archiUsuarios,nombreIngresado);
        }
    }
}

int verificacionClave(char archiUsuarios[],int pos,char claveIngresada[20],int idDevuelto)
{
    FILE *arch;
    stUsuario usuario;

    int claveCorrecta=1; //0 correcta

    arch=fopen(archiUsuarios,"rb");

    //busqueda de la clave
    if(arch!=NULL)
    {
        //posicionamiento del cursor
        fseek(arch,sizeof(stUsuario)*pos,SEEK_SET);
        //lectura del fichero
        fread(&usuario,sizeof(stUsuario),1,arch);
        //comparacion
        if(strcmp(usuario.clave,claveIngresada)==0)
        {
            claveCorrecta=0;
            //devolvemos su id
            idDevuelto=usuario.idUsuario;
        }
    }

    //cierre del archivo
    fclose(arch);

    return claveCorrecta;
}

void ingresoClave(char claveIngresada[20])
{
    char caracter;
    int i=0;

    //ingreso de contrasseña
    printf("\nClave: ");
    fflush(stdin);

    while(caracter = getch())
    {
        if(caracter == 13)
        {
            claveIngresada[i]='\0'; //cuando presiona enter
            break;
        }
        else if(caracter == 8)  //cuando presiona retroceso
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            if(i<20)  //dimension del arreglo clave
            {
                printf("*");
                claveIngresada[i]=caracter;
                i++;
            }
        }
    }
}

void iniciarSesion(char archiUsuarios[],char nombreDevuelto[20],int idDevuelto,int *flag)
{
    char nombreIngresado[20]= {0};
    char claveIngresada[20]= {0};

    int existenciaUsuario=-1;
    int claveCorrecta=1;
    int control=1; //opcion elegida por el usuario

    //bucle de nombre de usuario
    while(control==1 && existenciaUsuario==-1)
    {
        system("cls");

        printf("------------------------------\n");
        printf("        INICIAR SESION        \n");
        printf("------------------------------\n");

        //ingreso de nombre de usuario
        existenciaUsuario=ingresoNombreUsuario(archiUsuarios,nombreIngresado);

        //nombre de usuario inexistente
        if(existenciaUsuario==-1)
        {
            Beep(70,200);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
            printf("\nNombre de usuario no registrado.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
            printf("1. Intentar con otro nombre de usuario.\n");
            printf("2. Registrarse.\n");
            printf("0. Salir al menu principal.\n");

            fflush(stdin);
            scanf("%d",&control);

            while(control!=1 && control!=2 && control!=0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
                printf("Opcion no valida. Vuelva  ingresar.\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
                fflush(stdin);
                scanf("%d",&control);
            }

            //opcion de registrarse
            if(control==2)
            {
                registrarUsuario(archiUsuarios);
            }
        }
        else   //nombre de usuario valido
        {
            Beep(600,100);
            while(control==1 && claveCorrecta==1)
            {
                system("cls");

                printf("------------------------------\n");
                printf("        INICIAR SESION        \n");
                printf("------------------------------\n");

                //ingreso de clave
                ingresoClave(claveIngresada);
                //verificaion de contraseña
                claveCorrecta=verificacionClave(archiUsuarios,existenciaUsuario,claveIngresada,idDevuelto);

                //si la clave es incorrecta
                if(claveCorrecta!=0)
                {
                    Beep(70,200);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | BACKGROUND_INTENSITY);
                    printf("\nClave incorrecta.\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | BACKGROUND_INTENSITY);
                    printf("1. Intentar con otra clave.\n");
                    printf("2. Volver a ingresar nombre de usuario.\n");
                    printf("0. Salir al menu principal.\n");

                    fflush(stdin);
                    scanf("%d",&control);
                }

                //si la clave es la correcta
                if(claveCorrecta==0)
                {
                    Beep(600,100);
                    //se copia el nombre para poder devolverlo
                    strcpy(nombreDevuelto,nombreIngresado);

                    printf("\nSesion iniciada con exito.\n");
                    *flag=1; //levantamos la flag de incio de sesion

                    system("pause");
                    system("cls");
                }

                //opcion de inciar sesion
                if(control==2)
                {
                    iniciarSesion(archiUsuarios,nombreDevuelto,idDevuelto,*flag);
                }
            }

        }
    }
}

void menuJuegos()
{
    titulo();
    printf("1. Batalla Naval\n");
    printf("2. Snake\n");
    printf("3. Ahorcado\n");
    printf("4. Tateti\n");

    printf("\n0. Salir\n");
}

void guardarPartida(char archivo[],stPuntaje puntuacionFinal[2])
{
    stPuntaje temp;

    FILE *arch;
    arch=fopen(archivo,"ab");

    if(arch!=NULL)
    {
        for(int i=0; i<2; i++)
        {
            temp=puntuacionFinal[i];
            fwrite(&temp,sizeof(stPuntaje),1,arch);
        }
    }

    fclose(arch);
}

void cargarArreglo(char archivo[],stPuntaje arreglo[100],int *validos)
{
    stPuntaje temp;
    FILE * arch;

    *validos=0;
    long cantidad;
    long b;

    arch=fopen(archivo,"r+b");

    fseek(arch,0,SEEK_END);

    b=ftell(arch);

    //cantidad=b/stPuntaje;

    printf("\nCANT: %ld\n",b);

    cantidad=sizeof(stPuntaje);

    printf("\nCANT: %ld\n",cantidad);

    fseek(arch,0,SEEK_SET);

    if(arch!=NULL)
    {

        while((fread(&temp,sizeof(stPuntaje),1,arch)>0) && (*validos<100))
        {
            arreglo[*validos]=temp;
            *validos+=1;
            printf("\nVALIDOS: %d",*validos);
        }
    }

    fclose(arch);
}

void intercambiarDatos(stPuntaje puntajes[],int posOrigen,int posDestino)
{
    stPuntaje aux;
    aux=puntajes[posOrigen];

    puntajes[posOrigen]=puntajes[posDestino];
    puntajes[posDestino]=aux;
}

void ordenamientoSeleccion(stPuntaje puntajes[100],int validos)
{
    //se repite la cantidad de validos para ordenar el arreglo
    int posMayor;

    for(int i=0; i<validos; i++)
    {
        //encontrar pos mayor
        for(int j=i+1; j<validos; j++)
        {
            if(puntajes[j].puntaje>puntajes[i].puntaje)
            {
                posMayor=j;
            }
        }
        //se intercambian los datos
        intercambiarDatos(puntajes,i,posMayor);
    }
}

void mostrarPuesto(stPuntaje temp)
{
    printf("\nID: %d",temp.idJugador);
    printf("\nPuntaje: %d",temp.puntaje);
    printf("\n---------------------------\n");
}

void mostrarRanking(stPuntaje puntajes[100],int validosRanking)
{
    for(int i=0; i<validosRanking; i++)
    {
        printf("\n----Puesto %d----\n",i+1);
        mostrarPuesto(puntajes[i]);
    }
}
//!
void mostrarArchivo(char archivo[])
{
    stPuntaje temp;

    FILE *arch;
    arch=fopen(archivo,"rb");

    while(fread(&temp,sizeof(stPuntaje),1,arch)>0)
    {
        printf("ID: %d\n",temp.idJugador);
        printf("PUNTAJE: %d\n",temp.puntaje);
        printf("-------------\n");
    }
    fclose(arch);
}
