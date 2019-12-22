#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merging.h"


void ausgabe(int *array, int groesse);
void init_f(int *pointer, int groesse);

int main() {
    clock_t begin = clock();

    //int array_size=10;
    //int *ArrayToSort=(int*)malloc(array_size * sizeof(int));
    int
    init_f(ArrayToSort, array_size);
    Merge_sort(ArrayToSort, 1, array_size - 1); // es werden die Elemente 1 bis 9 und nicht 0 bis 9 sortiert
    ausgabe(ArrayToSort, array_size);
    free(ArrayToSort);

    clock_t end= clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution time: %lf sec\n", time_spent);
    return 0;

    return 0;
}

void ausgabe(int *array, int groesse){
    for(int i=0; i<groesse; i++){
        printf("%2d",array[i]);
    }
    printf("\n");
}

void init_f(int *pointer, int groesse) {
    for(int i=1;i<groesse;i++){
        pointer[i]=rand()%10;
        // printf("%d. Element:  %d\n",i , pointer[i] );
    }
}

