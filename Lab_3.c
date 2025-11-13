#include <stdio.h>
#include <omp.h>

// Recursive Fibonacci with OpenMP tasks and labeled thread diagnostics
int fib(int n, const char *label) {
    int tid = omp_get_thread_num();
    printf("Thread %d handling %s call: fib(%d)\n", tid, label, n);

    if (n < 2) return n;

    int x, y;

    #pragma omp task shared(x)
    {
        x = fib(n - 1, "left");
    }

    #pragma omp task shared(y)
    {
        y = fib(n - 2, "right");
    }

    #pragma omp taskwait
    return x + y;
}

int main() {
    int n;
    printf("Enter number of Fibonacci terms: ");
    scanf("%d", &n);

    omp_set_nested(1);         // Enable nested parallelism
    omp_set_num_threads(4);    // Set thread count

    double start = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 0; i < n; i++) {
                printf("\n\nFib(%d) = ???\n", i);
                int result = fib(i, "root");
                printf("Fib(%d) = %d\n", i, result);
            }
        }
    }

    double end = omp_get_wtime();
    printf("Execution Time: %f seconds\n", end - start);

    return 0;
}
