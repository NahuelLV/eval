#include <stdio.h>
#include <stdlib.h>

// Declaro los colores que voy a usar
#define NEGRO_F        "\x1b[40m"
#define ROJO_F         "\x1b[41m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_F     "\x1b[43m"
#define RESET_COLOR    "\x1b[0m"


// Funcion para llenar la matriz
int llenar(int almacenamiento[6][3]) {
    int cantidad_producida, tipo, operador;
    for (int i = 0; i < 6; i++) {
        printf("\nProduccion %d:\n", i + 1);
        
        // Ingresar datos para cada operador
        printf("Ingrese la cantidad producida por operador: ");
        scanf("%d", &cantidad_producida);
        almacenamiento[i][0] = cantidad_producida;
        
        printf("Ingrese el tipo de alfajor (1 = Chocolate | 2 = Dulce de Leche | 3 = Fruta): ");
        scanf("%d", &tipo);
        if (tipo > 3 || tipo < 1) {
            printf(ROJO_F"Reinicie el programa y lea correctamente"RESET_COLOR);
            return 1;
        }
        almacenamiento[i][1] = tipo;

        printf("Ingrese el numero de operador(1 a 6): ");
        scanf("%d", &operador);
        if (operador > 6 || operador < 1) {
            printf(ROJO_F"Reinicie el programa y lea correctamente"RESET_COLOR);
            return 1;
        }
        almacenamiento[i][2] = operador;
    }
    return 0; 
}

// Funcion para imprimir la matriz
void imprimir(int almacenamiento[6][3]) {
    printf("\nCANTIDAD | TIPO   | OPERADOR\n");
    for (int i = 0; i < 6; i++) {
        printf("%8d | %6d | %8d\n", almacenamiento[i][0], almacenamiento[i][1], almacenamiento[i][2]);
    }
}

int main() {
    int almacenamiento[6][3];
    int cantidadTotal = 0;
    int cantidadCho = 0;
    int cantidadDdL = 0;
    int cantidadFr = 0;

    //Lleno la matriz
    llenar(almacenamiento);

    //Imprimo la matriz
    imprimir(almacenamiento);

    // Calculo el total
    for (int i = 0; i < 6; i++) {
        cantidadTotal = cantidadTotal + almacenamiento[i][0];
    }
    printf("\nTotal de produccion: %d\n", cantidadTotal);

    //Calculo los de chocolate
    for (int i = 0; i < 6; i++) {
        if (almacenamiento[i][1] == 1){
            cantidadCho = cantidadCho + almacenamiento[i][0];
        }
    }
    printf("\nTotal de chocolate: %d\n", cantidadCho);

    //Calculo los de Dulce de Leche
    for (int i = 0; i < 6; i++) {
        if (almacenamiento[i][1] == 2){
            cantidadDdL = cantidadDdL + almacenamiento[i][0];
        }
    }
    printf("\nTotal de dulce de leche: %d\n", cantidadDdL);

    //Calculo los de Fruta
    for (int i = 0; i < 6; i++) {
        if (almacenamiento[i][1] == 3){
            cantidadFr = cantidadFr + almacenamiento[i][0];
        }
    }
    printf("\nTotal de fruta: %d\n", cantidadFr);
    
    //Calculo las cajas de dulce de leche
    int entegrasDdL = cantidadDdL / 6;
    printf("Total de entregas de cajas de dulce de leche: %d", entegrasDdL);
    int ddl = entegrasDdL * 6;
    
    //Calculo las cajas de chocolate
    int entegrasCho = cantidadCho / 6;
    printf("Total de entregas de cajas de dulce de leche: %d", entegrasDdL);
    int cho = entegrasCho * 6;
    
    //Calculo las cajas de fruta
    int entegrasFr = cantidadFr / 6;
    printf("Total de entregas de cajas de dulce de leche: %d", entegrasDdL);
    int fr = entegrasFr * 6;
    
    int cajasindividuales = fr + cho + ddl;
    
    
    //Calculo las cajas mixtas
    float entregas = (cantidadTotal-cajasindividuales) / 6;
    printf("El total de entregas es de: %.2f\n", entregas);
    float error = cantidadTotal % 6;
    printf("El total de entregas con error es de(Alfajores que sobran): %.2f\n", error);
    
    int precio[4] = {500, 350, 200, 400};
    
    printf("CHOCOLATE|DULCEdeLECHE|FRUTA|MIXTA\n");
    for(int n = 0; n < 4; n++){
        printf("%d", precio[n]);
    }
    
    
    int gananciasCho = entegrasCho * precio[0];
    printf("Las ganancias de las cajas de chocolate son de: %d\n", gananciasCho);
    
    int gananciasDdL = entegrasDdL * precio[1];
    printf("Las ganancias de las cajas de dulce de leche son de: %d\n", gananciasDdL);
    
    int gananciasFr = entegrasFr * precio[2];
    printf("Las ganancias de las cajas de chocolate son de: %d\n", gananciasFr);
    
    int gananciasMix = entregas * precio[3];
    printf("Las ganancias de las cajas de mixtas son de: %d\n", gananciasCho);
    
    return 0;
}




/* Interpretacion: 

El ejercicio pide un programa para que un jefe/encargardo vea la produccion de sus empleados y cada tipo de alfajores que hizo.
Yo lo hice pensando en un seguimiento mensual(Ya que aclara que le interesa saber las ganancias y produccion del ultimo mes), debido a esto hice que solo haya 6 producciones(Una por empleado y estos solo pueden desarrolar un tipo).
Igualmente el codigo se puede modificar agregando una variable(Por ejemplo "Producciones totales") para que pueda haber repeticion, es decir, que un empleado pueda hacer varias producciones de difentes tipo de alfajor
*/







