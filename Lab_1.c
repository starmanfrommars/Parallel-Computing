// Write an OpenMP program that divides the Iterations into chunks containing 2 iterations, 
// respectively (OMP_SCHEDULE=static,2). Its input should be the number of iterations, and 
// its output should be which iterations of a parallelized for loop are executed by which 
// thread. For example, if there are two threads and four iterations, the output might be 
// the following:

// a. Thread 0 : Iterations 0 −− 1
// b. Thread 1 : Iterations 2 −− 3


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

// Terminal Command
// Compile = gcc Lab_1.c -fopenmp
// Execute = ./a.out


// SAMPLE OUTPUT

// Enter the number of iterations : 4
// Thread no. 0 is executing iteration 0
// Thread no. 0 is executing iteration 1
// Thread no. 1 is executing iteration 2
// Thread no. 1 is executing iteration 3