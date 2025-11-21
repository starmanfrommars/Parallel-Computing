// Write a OpenMP program to sort an array on n elements using both sequential and parallel 
// mergesort(using Section). Record the difference in execution time.

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 500000

void merge(int *a,int l,int m,int r){
    int n1 = m-l+1, n2 = r-m;
    int i,j,k;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for(i=0;i<n1;i++) L[i] = a[l+i];
    for(i=0;i<n2;i++) R[i] = a[m+1+i];

    i=j=0;
    k=l;

    while(i< n1 && j<n2){
        a[k++] = (L[i] < R[j])? L[i++] : R[j++];
    }
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];

    free(L);
    free(R);
}

void sort(int *a,int l,int r,int d) {
    if(l>=r) return;
    int m = (l+r)/2;
    if(d>0){
        #pragma omp parallel sections 
        {
            #pragma omp section 
            {
                printf("Thread %d working on left [%d..%d]\n", omp_get_thread_num(),l,m);
                sort(a,l,m,d-1);
            }

            #pragma omp section 
            {
                printf("Thread %d working on right [%d..%d]\n", omp_get_thread_num(),m+1,r);
                sort(a,m+1,r,d-1);
            }
        }
    }
    else{
        sort(a,l,m,0);
        sort(a,m+1,r,0);
    }
    merge(a,l,m,r);
}

int main(){
    omp_set_nested(1);

    int *a = malloc(N * sizeof(int));
    int *b = malloc(N * sizeof(int));

    for(int i=0;i<N;i++){
        a[i] = b[i] = rand();
    }

    double t = omp_get_wtime();
    sort(a,0,N-1,0);
    printf("Sequential time : %f seconds\n",omp_get_wtime() - t);

    // int d; // optimal = 2
    // printf("Enter d : ");
    // scanf("%d",&d);

    t = omp_get_wtime();
    sort(b,0,N-1,2);
    printf("Parallel time : %f seconds\n",omp_get_wtime() - t);

    free(a);
    free(b);

    return 0;
}

// Terminal Command
// Compile = gcc Lab_2.c -fopenmp
// Execute = ./a.out


// SAMPLE OUTPUT
// Sequential time : 0.077565 seconds
// Thread 0 working on right [250000..499999]
// Thread 10 working on left [0..249999]
// Thread 0 working on left [0..124999]
// Thread 1 working on right [125000..249999]
// Thread 4 working on left [250000..374999]
// Thread 7 working on right [375000..499999]
// Parallel time : 0.038393 seconds