#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(){

    srand(time(NULL));

    int i;
    double vt[N];
    double* punt_vt = vt;

    for (i = 0; i < N; i++)
    {
        *punt_vt = 1+rand()%100;
        printf("%.2f ",*punt_vt);
        punt_vt++;
    }
    // Trabajando con aritmetica de punteros

    return 0;

}