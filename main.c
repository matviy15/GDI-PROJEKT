#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <values.h>
#include "merge_sort.h"

int main() {
    clock_t begin = clock();

    int array_size=12;
    int *ArrayToSort=(int*)malloc(array_size * sizeof(int));
    //int ArrayToSort[12]={3,2,1,8,9,7,0,4,10,6,5,11};
    init_f(ArrayToSort, array_size);
    ausgabe(ArrayToSort, array_size);
    Merge_sort(ArrayToSort, 0, array_size - 1); // es werden die Elemente 1 bis 9 und nicht 0 bis 9 sortiert
    ausgabe(ArrayToSort, array_size);
    free(ArrayToSort);

    clock_t end= clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution time: %lf sec\n", time_spent);
    return 0;
}



