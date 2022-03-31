#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main(){

    srand(time(NULL));

    int i,j;
    int mt[N][M];
    int* punt_matriz;
    punt_matriz = &mt[0][0];
    // Inicializo el puntero en la dirección de memoria del elemento de la fila 1 columna 1 del arreglo.

    for(i = 0;i<N; i++) {

        for(j = 0;j<M; j++) {

            *(punt_matriz+(i*M+j))=1+rand()%100;
            printf("%2d ", *(punt_matriz+(i*M+j)));

        }

        printf("\n");
    }

    return 0;

}