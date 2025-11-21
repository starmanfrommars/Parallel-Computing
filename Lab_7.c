// Write a MPI Program to demonstration of Broadcast operation.

#include <stdio.h>
#include <mpi.h>

int main() {
    int my_rank, comm_sz;
    int data; // Variable to be broadcasted
    MPI_Init(NULL, NULL); // No command-line arguments
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

    if (my_rank == 0) {
        printf("Enter the number to be broadcasted\n");
        scanf("%d", &data); // Root process initializes the data
        printf("Process 0 broadcasting data = %d\n", data);
    }

    // Broadcast data from process 0 to all others
    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    // All processes print the received data
    printf("Process %d received data = %d\n", my_rank, data);
    
    MPI_Finalize();

    return 0;
}


// Terminal Command
// mpicc Lab_7.c
// mpiexec -np 4 ./a.out


// OUTPUT
// Enter the number to be broadcasted
// 5
// Process 0 broadcasting data = 5
// Process 0 received data = 5
// Process 2 received data = 5
// Process 1 received data = 5
// Process 3 received data = 5