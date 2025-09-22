#include <stdio.h>
#include <omp.h>

int main(){
    int n;
    printf("Enter the number of iterations : ");
    scanf("%d",&n);

    #pragma omp parallel for schedule(static,2)
    for(int i=0;i<n;i++){
        int tid = omp_get_thread_num();
        printf("Thread no. %d is executing iteration %d\n", tid,i);
    }
    return 0;
}

// gcc Program1.c -fopenmp