#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 6
#define N 10
#define ARRCOMP 5
// Constante para la cantidad de computadoras a cargar en el arreglo de estructuras.

struct compu {
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
} typedef compu;


void cargarCompus(compu compus[ARRCOMP], char tiposCompus[M][N]);
// Funcion para cargar el arreglo de estructuras.

void mostrarCompus(compu compus[ARRCOMP]);
// Funcion para mostrar el arreglo de estructuras.

void mostrarCompu(compu computadora);
// Funcion para mostrar una computadora especifica.

void mostrarCompuMasVieja(compu compus[ARRCOMP]);
// Funcion para mostrar la computadora mas vieja.

void mostrarCompuMasVeloz(compu compus[ARRCOMP]);

int main(){

    srand(time(NULL));

    char tipos[M][N] = {"Intel","AMD","Celeron","Athlon","Core","Pentium"};
    // Arreglo de tipos de procesador para el punto 4) iii)
    
    compu compus[ARRCOMP];
    // Arreglo de estructuras struct compu para guardar las características de 5 PCs.

    cargarCompus(compus,tipos);
    
    printf("<====== Informacion de las PCs ======> ");
    mostrarCompus(compus);

    printf("\n");

    printf("\n<====== Informacion de las PC mas vieja ======>\n");
    mostrarCompuMasVieja(compus);
    
    printf("\n");

    printf("\n<====== Informacion de las PC mas veloz ======>\n");
    mostrarCompuMasVeloz(compus);


    return 0;

}

void cargarCompus(compu compus[ARRCOMP], char tiposCompus[M][N]){

    for (int i = 0; i < ARRCOMP; i++)
    {
        compus[i].velocidad = (rand()%3) + 1;
        // Cargo en el campo velocidad de cada estructura del arreglo un valor aleatorio entre 1 y 3.

        compus[i].anio = (rand()%8) + 2015;
        // Cargo en el campo año de cada estructura del arreglo un valor aleatorio entre 2015 y 2022.

        compus[i].cantidad = (rand()%8) + 1;
        // Cargo en el campo cantidad de cada estructura del arreglo un valor aleatorio entre 1 y 8.
        
        compus[i].tipo_cpu = &tiposCompus[rand()%6][0];
        // Aleatoriamente se asigna al puntero tipo_cpu la dirección de memoria de cualquiera de las cadenas de caracteres que forman parte del arreglo tipos. 
        // Para eso, se apunta el puntero a la dirección de memoria del primer caracter de la correspondiente cadena de caracteres del arreglo.

    }
    // Cargo el arreglo de estructuras.

}

void mostrarCompus(compu compus[ARRCOMP]){

    char* recorrerCadena;
    // Puntero auxiliar para recorrer las cadenas correspondientes y no usar los punteros de cada estructura.

    for (int i = 0; i < ARRCOMP; i++)
    {

        printf("\n==== Info de la PC %d\n",i+1);
        mostrarCompu(compus[i]);

    }

}

void mostrarCompu(compu computadora){

    char* recorrerCadena;
    // Puntero auxiliar para recorrer la cadenas correspondiente y no usar el puntero de la estructura.

    printf("-> Velocidad de procesamiento : %d GHz\n",computadora.velocidad);
    printf("-> Fecha de fabricacion: %d\n",computadora.anio);
    printf("-> Cantidad de nucleos: %d\n",computadora.cantidad);

    printf("-> Tipo de procesador: ");

    recorrerCadena = computadora.tipo_cpu;

    while(*(recorrerCadena)){
        printf("%c",*(recorrerCadena));
        recorrerCadena++;
    }

}

void mostrarCompuMasVieja(compu compus[ARRCOMP]){

    compu masVieja = compus[0];
    // En masVieja guardare la computadora más vieja. 
    // Si dos PCs tienen la misma antigüedad, se guardara la primera encontrada.

    for (int i = 1; i < ARRCOMP; i++){
        if(compus[i].anio < masVieja.anio){
            masVieja = compus[i];
        }
    }
    // Recorro el resto del arreglo para ver si hay una computadora mas vieja que la primera.

    mostrarCompu(masVieja);

}

void mostrarCompuMasVeloz(compu compus[ARRCOMP]){

    compu masVeloz = compus[0];
    // En masVeloz guardare la computadora mas veloz.
    // Si dos PCs tienen la misma velocidad, se guardará la primera encontrada.

    for (int i = 1; i < ARRCOMP; i++){
        if(compus[i].velocidad > masVeloz.velocidad){
            masVeloz = compus[i];
        }
    }

    mostrarCompu(masVeloz);

}
