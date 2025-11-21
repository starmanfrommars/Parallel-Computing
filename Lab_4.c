// Write a OpenMP program to find the prime numbers from 1 to n employing parallel 
// for directive. Record both serial and parallel execution times.

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int is_prime(int x) {
    if (x < 2) return 0;
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0) return 0;
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <n> <threads>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int threads = atoi(argv[2]);
    omp_set_num_threads(threads);

    int count;
    double t0, t1;

    // Serial
    count = 0;
    t0 = omp_get_wtime();
    printf("Serial primes up to %d:\n", n);

    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i); // print prime
            count++;
        }
    }
    t1 = omp_get_wtime();
    printf("\nSerial: %d primes, %f sec\n", count, t1 - t0);

    // Parallel
    count = 0;
    int *primes = malloc((n + 1) * sizeof(int)); // array to store primes

    #pragma omp parallel for
    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) {
            #pragma omp critical
            {
                primes[count] = i; // store prime
                count++;
            }
        }
    }

    t1 = omp_get_wtime();
    printf("Parallel (%d threads) primes up to %d:\n", threads, n);
    for (int i = 0; i < count; i++) printf("%d ", primes[i]);
    printf("\nParallel: %d primes, %f sec\n", count, t1 - t0);

    free(primes);
    return 0;
}
    

// Terminal Command
// Compile = gcc Lab_4.c -fopenmp
// Execute = ./a.out 30 4


// OUTPUT
// Serial primes up to 30:
// 2 3 5 7 11 13 17 19 23 29 
// Serial: 10 primes, 0.000015 sec
// Parallel (4 threads) primes up to 30:
// 11 2 3 29 5 7 13 17 19 23 
// Parallel: 10 primes, 0.000142 sec