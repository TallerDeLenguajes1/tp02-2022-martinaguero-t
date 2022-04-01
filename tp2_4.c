#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu {
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
} typedef compu;

int main(){

    srand(time(NULL));

    char tipos[6][10] = {"Intel","AMD","Celeron","Athlon","Core","Pentium"};
    // Arreglo de tipos de procesador para el punto 4) iii)
    
    compu compus[5];
    // Arreglo de estructuras struct compu para guardar las características de 5 PCs.



    return 0;

}