#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int llenarterna(int terna[3], int j, int jg, int n){
    printf("Ingrese el numero del jugador: ");
    scanf("%d", &j);
    printf("Ingrese el numero del juego: ");
    scanf("%d", &jg);
    printf("Ingrese la clasificaion de ese jugador en dicho juego: ");
    scanf("%d", &n);
    terna[0] = j;
    terna[1] = jg;
    terna[2] = n;
}


int clasificaciones(int n){
    if
}

int main(){
    int j = 0;
    int jg = 0;
    int n = 0; // Jugador, Juego, Clasificaion/nota
    int terna[3];
    llenarterna(terna, j, jg, n);
    printf("JUGADOR|JUEGO|CLASIFICACION\n");
    for(int i = 0; i < 3; i++){
        printf(" %4d ", terna[i]);
    }
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



