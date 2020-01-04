#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tgmath.h>
#include "merge_sort.h"

#define POINTS 1000
#define RADIUS 6371
#define PI 3.14159265

struct datapoint {
    char event[30]; // event information
    char datetime[30]; // date and time information
    double latitude; // latitude information (Breitengrad)
    double longitude; // longtitude information (Laengengrad)
    double x;
    double y;
    double z;
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

void xyz_calc(struct datapoint *dp);
void euclidean_dist(struct datapoint *dp1, struct datapoint *dp2);

/*****************************************************MAIN***********************************************************/
int main() {
    // gets time at start
    clock_t begin = clock();

    int array_size = 12;
    int *ArrayToSort = (int *) malloc(array_size * sizeof(int));
    //int ArrayToSort[12]={3,2,1,8,9,7,0,4,10,6,5,11};
    init_f(ArrayToSort, array_size);
    ausgabe(ArrayToSort, array_size);
    Merge_sort(ArrayToSort, 0, array_size - 1); // es werden die Elemente 0 bis (array_size-1) sortiert
    ausgabe(ArrayToSort, array_size);
    free(ArrayToSort);

    char fileNameString[] = "/home/ivaylo/Desktop/GDI-PROJEKT/DataToRead.tab";
    FILE *fileToRead;
    // open source file

    fileToRead = fopen(fileNameString, "r");
    // if fileToRead doesn't exist print error close it and exit the program
    if (fileToRead == NULL) {
        printf("no such file found");
        return 0;
    }

    // open destination file
    char writeFile[] = "/home/ivaylo/Desktop/GDI-PROJEKT/WriteData.txt";
    FILE *fileToWrite;
    fileToWrite = fopen(writeFile, "w");

    struct datapoint dp[POINTS];

    int fail = 0;
    int success;
    int prev = 0;
    int i = 0;
    // reads the chosen amount of data points and deletes any points with missing values
    for (i = 0; i < POINTS; i++) {
        success = fscanf(fileToRead, "%s\t%s\t%lf\t%lf\t%d\t%d\t%d\t%d\t%lf\t%lf\t%lf\t%d\t%lf\n", dp[i].event,
                         dp[i].datetime, &dp[i].latitude, &dp[i].longitude, &dp[i].altitude, &dp[i].hhh,
                         &dp[i].hgeom1,
                         &dp[i].hgeom2, &dp[i].PPPP, &dp[i].TTT, &dp[i].RH, &dp[i].dd, &dp[i].ff);
        if (success != 13)fail = 1;
        if (success != 13 || fail != 0 || prev != 0) {
            i--;
            prev = fail;
            fail = 0;
        }
    }
    // puts all of the read data in a new file with the number of the point in front of the values
    for (i = 0; i < POINTS; i++) {
        fprintf(fileToWrite, "dp:%d\t%s\t%s\t%.5lf\t%.5lf\t%d\t%d\t%d\t%d\t%.2lf\t%.2lf\t%.1lf\t%d\t%.1lf\n", i,
                dp[i].event,
                dp[i].datetime, dp[i].latitude, dp[i].longitude,
                dp[i].altitude, dp[i].hhh, dp[i].hgeom1, dp[i].hgeom2, dp[i].PPPP, dp[i].TTT, dp[i].RH, dp[i].dd,
                dp[i].ff);
    }
    xyz_calc(&dp[3]);
    printf("x: %lf\ny: %lf\nz: %lf\nLongtitude: %lf\nLatitude: %lf\n",dp[3].x,dp[3].y,dp[3].z,dp[3].longitude,dp[3].latitude);
    euclidean_dist(&dp[0],&dp[999]);
    printf("%.2lf km",dp[0].abstand);
    fclose(fileToRead);
    fclose(fileToWrite);


    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("\nExecution time: %lf sec\n", time_spent);
    /* will only calculate the time the processor spent working i.e. if the programm
     * waits for input 15 seconds but the processor calculates 10 seconds the output
     * for execution time will be 10 seconds not 25
     */
    return 0;
}
/***************************************************END OF MAIN******************************************************/

void xyz_calc(struct datapoint *dp) {
    double degToRad = 0.017453293;
    double betaRad,alfaRad;
    betaRad=(90 - dp->longitude)*degToRad;
    alfaRad=dp->latitude*degToRad;
    dp->x = RADIUS * sin(betaRad) * cos(alfaRad);
    dp->y = RADIUS * sin(betaRad) * sin(alfaRad);
    dp->z = RADIUS * cos(betaRad);
}

/* Function to calculate euclidean distance between two points.
 * Distance will be saved in the abstand value of the first data point(dp1)
 * dp1 - the first of the both data points between which the distance will be calculated
 * dp2 - the second data point */
void euclidean_dist(struct datapoint *dp1, struct datapoint *dp2){
    xyz_calc(dp1);
    xyz_calc(dp2);
    /*printf("(x1 - x2)² = (%lf - %lf)² = %lf\n",dp1->x,dp2->x,pow(dp1->x-dp2->x,2) );
     * printf("(x1 - x2)² = (%lf - %lf)² = %lf\n",dp1->y,dp2->y,pow(dp1->y-dp2->y,2) );
     * printf("(x1 - x2)² = (%lf - %lf)² = %lf\n",dp1->z,dp2->z,pow(dp1->z-dp2->z,2) );
     */
    dp1->abstand=sqrt(pow(dp1->x-dp2->x,2) + pow(dp1->y - dp2->y,2) + pow(dp1->z - dp2->z,2) );
}

void orthodromic_dist(){

}
