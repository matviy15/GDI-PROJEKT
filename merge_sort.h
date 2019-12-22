//
// Created by ivaylo on 22.12.19.
//

void Merge_sort(int* A, int p, int r){
    int q;
    if(p<r){
        q=(p+r)/2;
        Merge_sort(A, p , q);
        Merge_sort(A, q+1, r);
        Merge(A, p, q, r);
    }
}

void Merge(int* A, int p, int q, int r){
    int n1= q - p + 1;
    int n2= r - q;
    int L[n1+1], R[n2+1];

    for(int i=1; i<=n1+1; i++){
        L[i]=A[p+i-1];
    }
    for(int j=1; j<=n2+1; j++){
        R[j]=A[q+j];
    }
    L[n1+1]=INT_MAX ;
    R[n2+1]=INT_MAX ;
    int i=1;
    int j=1;
    for(int k=p; k<=r; k++){
        if(L[i] <= R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
        }
    }
}

void ausgabe(int *array, int groesse){
    for(int i=1; i<groesse; i++){
        printf("%2d",array[i]);
    }
    printf("\n");
}

void init_f(int *pointer, int groesse){
    for(int i=1;i<groesse;i++){
        pointer[i]=rand()%10;
        // printf("%d. Element:  %d\n",i , pointer[i] );
    }
}