// Write a MPI Program to demonstration of MPI_Send and MPI_Recv.

#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank;
    MPI_Init(&argc, &argv); // Initialize MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get process rank

    if (rank == 0) {
        int number = 42;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD); // Send to rank 1
        printf("Rank 0 sent number %d to rank 1\n", number);
    }
    else if (rank == 1) {
        int received;
        MPI_Recv(&received, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // Receive from rank 0
        printf("Rank 1 received number %d from rank 0\n", received);
    }

    MPI_Finalize(); // Finalize MPI
    return 0;
}


// Terminal Command
// Compile = mpicc Lab_5.c
// Execute = mpiexec -np 2 ./a.out


// OUTPUT
// Rank 0 sent number 42 to rank 1
// Rank 1 received number 42 from rank 0