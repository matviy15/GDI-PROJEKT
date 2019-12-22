//
// Created by ivaylo on 22.12.19.
//
void Merge(int* unsortedArray, int begin, int middle, int end){
    int lenghtLeft= middle - begin + 1;
    int lenghtRight= end - middle;
    int leftField[lenghtLeft + 1], rightField[lenghtRight + 1];

    for(int i=1; i <= lenghtLeft + 1; i++){
        leftField[i]=unsortedArray[begin + i - 1];
    }
    for(int j=1; j <= lenghtRight + 1; j++){
        rightField[j]=unsortedArray[middle + j];
    }
    leftField[lenghtLeft + 1]=INT_MAX ;
    rightField[lenghtRight + 1]=INT_MAX ;
    int i=1;
    int j=1;
    for(int k=begin; k <= end; k++){
        if(leftField[i] <= rightField[j]){
            unsortedArray[k]=leftField[i];
            i++;
        }else{
            unsortedArray[k] = rightField[j];
            j++;
        }
    }
}
void Merge_sort(int* A, int begin, int end){
    int middle;
    if(begin < end){
        middle=(begin + end) / 2;
        Merge_sort(A, begin , middle);
        Merge_sort(A, middle + 1, end);
        Merge(A, begin, middle, end);
    }
}



void ausgabe(int *array, int groesse){
    for(int i=1; i<groesse; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void init_f(int *pointer, int groesse){
    for(int i=1;i<groesse;i++){
        pointer[i]=rand()%10000;

    }
}