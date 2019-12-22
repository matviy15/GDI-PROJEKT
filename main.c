#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge_sort.h"

struct datapoint{
    char event[30]; // event information
    char datetime[30]; // date and time information
    double latitude; // latitude information (Breitengrad)
    double longitude; // longtitude information (Laengengrad)
    int altitude; // Geopotential height above sea level integrated from pressure, temperature and humidity
    int hhh; // Geopotential height above sea level derived from GPS receiver mounted on radiosonde
    int hgeom1; //
    int hgeom2; //
    double PPPP; // air pressure (measured in hPa, hectoPascal)
    double TTT; // air temperatute measured in Celsius
    double RH; // relative Humidity
    int dd; // wind direction in degrees
    double ff; // wind speed
    double abstand;
};

int main() {
    // gets time at start
    clock_t begin = clock();

    int array_size=12;
    int *ArrayToSort=(int*)malloc(array_size * sizeof(int));
    //int ArrayToSort[12]={3,2,1,8,9,7,0,4,10,6,5,11};
    init_f(ArrayToSort, array_size);
    ausgabe(ArrayToSort, array_size);
    Merge_sort(ArrayToSort, 0, array_size - 1); // es werden die Elemente 1 bis 9 und nicht 0 bis 9 sortiert
    ausgabe(ArrayToSort, array_size);


    char fileNameString[]="ReadData.txt";
    FILE *fileToRead;
    // open source file

    fileToRead=fopen(fileNameString,"r");
    // if fileToRead doesn't exist print error close it and exit the program
    if(fileToRead==NULL){
        printf("no such file found");
        return 0;
    }

    // open destination file
    char writeFile[]="WriteData.txt";
    FILE *fileToWrite;
    fileToWrite=fopen(writeFile, "w");

    struct datapoint dp[10];
    int i=0;


    for(i=0;i<10; i++){
        fscanf (fileToRead, "%lf\t%lf\t%d\t%d\t%d\t%d\t%lf\t%lf\t%lf\t%d\t%lf\n", &dp[i].latitude, &dp[i].longitude, &dp[i].altitude, &dp[i].hhh, &dp[i].hgeom1, &dp[i].hgeom2, &dp[i].PPPP, &dp[i].TTT, &dp[i].RH, &dp[i].dd, &dp[i].ff);
    }

    printf ("\nThe read values are: \n");
    for(i=0;i<10;i++){
        printf ("dp:%d\t%f\t%f\t%d\t%d\t%d\t%d\t%f\t%f\t%f\t%d\t%f\n", i, dp[i].latitude, dp[i].longitude, dp[i].altitude, dp[i].hhh, dp[i].hgeom1, dp[i].hgeom2, dp[i].PPPP, dp[i].TTT, dp[i].RH, dp[i].dd, dp[i].ff);
        fprintf (fileToWrite,"dp:%d\t%f\t%f\t%d\t%d\t%d\t%d\t%f\t%f\t%f\t%d\t%f\n", i, dp[i].latitude, dp[i].longitude, dp[i].altitude, dp[i].hhh, dp[i].hgeom1, dp[i].hgeom2, dp[i].PPPP, dp[i].TTT, dp[i].RH, dp[i].dd, dp[i].ff);
    }

    fclose(fileToRead);
    fclose(fileToWrite);
    free(ArrayToSort);
    // gets time at end
    clock_t end= clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nExecution time: %lf sec\n", time_spent);
    /* will only calculate the time the processor spent working i.e. if the programm
     * waits for input 15 seconds but the processor calculates 10 seconds the output
     * for execution time will be 10 seconds not 25
     */
    return 0;
}



