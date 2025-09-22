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


// SAMPLE OUTPUT

// Enter the number of iterations : 4
// Thread no. 0 is executing iteration 0
// Thread no. 0 is executing iteration 1
// Thread no. 1 is executing iteration 2
// Thread no. 1 is executing iteration 3