#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaro los colores que voy a usar
#define NEGRO_F        "\x1b[40m"
#define ROJO_F         "\x1b[41m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_F     "\x1b[43m"
#define RESET_COLOR    "\x1b[0m"

//Funcion para ingresar los valores de cada terna(Jugador-Juego-Clasificacion)
int llenarterna(int terna[3], int j, int jg, int n){
    printf("Ingrese el numero del jugador(1-30): ");
    scanf("%d", &j);
    if(j > 30 || j < 1){
        printf("Renicie el programa e ingrese un valor valido(1 a 30)\n");
        return 1;
    }
    printf("Ingrese el numero del juego(1-7): ");
    scanf("%d", &jg);
    if(jg > 7 || jg < 1){
        printf("Renicie el programa e ingrese un valor valido(1 a 7)\n");
        return 1;
    }
    printf("Ingrese la clasificaion de ese jugador en dicho juego(0 a 10, El 0 es solo si el jugador no jugo el juego): ");
    scanf("%d", &n);
    if(n > 10 || jg < 1){
        printf("Renicie el programa e ingrese un valor valido(0 a 10)\n");
        return 1;
    }
    terna[0] = j;
    terna[1] = jg;
    terna[2] = n;
}

//Funcion para imprimir la terna y ver las clasificaciones(aprobadas-desaprobadas)
int clasificaciones(int terna[3], int j, int jg, int n){
    if(terna[2] >= 6 && terna[2] < 8){
        printf("JUGADOR|JUEGO|CLASIFICACION\n");
        for(int i = 0; i < 3; i++){
        printf(VERDE_F" %4d "RESET_COLOR, terna[i]);
        }
    }else if(terna[2] < 6 && terna[2] > 0){
        printf("JUGADOR|JUEGO|CLASIFICACION\n");
        for(int i = 0; i < 3; i++){
        printf(ROJO_F" %4d "RESET_COLOR, terna[i]);
        }
    }else if(terna[2] >= 8){
        printf("JUGADOR|JUEGO|CLASIFICACION\n");
        for(int i = 0; i < 3; i++){
        printf(AMARILLO_F" %4d "RESET_COLOR, terna[i]);
        }
    }else if(terna[2] == 0){
        printf("JUGADOR|JUEGO|CLASIFICACION\n");
        for(int i = 0; i < 3; i++){
        printf(" %4d ", terna[i]);
        }
    }
    printf("\n");
}

int main(){
    int j = 0;
    int jg = 0;
    int n = 0; // Jugador, Juego, Clasificaion/nota
    int terna[3];
    for(int i = 0; i < 4; i++){
    llenarterna(terna, j, jg, n);
    clasificaciones(terna, j, jg, n);
    }
    /*int promedioTotal = (n + promedioTotal) 100;
    printf("El promedio total en todos los juegos y jugadores es de: %");*/
    return 0;
}




/*
Posibles combinaciones en ternas: 30 * 7 * 10 = 2100
Jugadores: 1 a 30
Juegos: 1 a 7
Clasificaciones: 1 a 10
Cada jugador tiene una clasificacion en un juego del 1 al 10
Algunos jugadores no poseen clasificacion en algunos juegos, por ende se clasifican en 0
Hay 7 premios monetarios posibles para los jugadores que posean mas de 8 de Clasificacion
*/



