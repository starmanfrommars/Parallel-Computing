// Write a MPI Program demonstration of MPI_Scatter and MPI_Gather
#include <mpi.h>
#include <stdio.h>

int main() {
    int rank, size;
    int send_data[4];     // Data to scatter (only significant on root)
    int recv_data;        // Each process receives one int
    int gathered_data[4]; // Data to gather back (only significant on root)

    MPI_Init(NULL, NULL);               // Initialize MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get current process rank
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Get total number of processes

    // --- 1. Initialize data at root (Process 0) ---
    if (rank == 0) {
        // We assume size == 4 for this specific example
        if (size != 4) {
            printf("This program is designed to run with 4 processes (mpirun -np 4).\n");
        }
        
        for (int i = 0; i < 4; i++) {
            send_data[i] = (i + 1) * 10;  // Example: 10, 20, 30, 40
        }
        
        printf("Process 0 scatters the following data: ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", send_data[i]);
        }
        printf("\n");
    }

    // --- 2. Scatter data from Process 0 to all processes ---
    MPI_Scatter(
        send_data,    // Send buffer (on root)
        1,            // One item per process being sent
        MPI_INT,      // Data type of send buffer
        &recv_data,   // Receive buffer (on all processes)
        1,            // One item per process being received
        MPI_INT,      // Data type of receive buffer
        0,            // Root rank (sender)
        MPI_COMM_WORLD
    );

    // Print received data and perform local computation
    printf("Process %d received number %d\n", rank, recv_data);
    fflush(stdout); // Ensure print order for scatter messages

    // Each process doubles its received value (the local computation)
    recv_data *= 2;

    // --- 3. Gather processed data back to Process 0 ---
    MPI_Gather(
        &recv_data,       // Send buffer (on all processes)
        1,                // One item per process being sent
        MPI_INT,          // Data type of send buffer
        gathered_data,    // Receive buffer (on root)
        1,                // One item per process being received
        MPI_INT,          // Data type of receive buffer
        0,                // Root rank (receiver)
        MPI_COMM_WORLD
    );

    // Sync all processes before printing the final result
    MPI_Barrier(MPI_COMM_WORLD); 

    // --- 4. Print gathered data at Process 0 ---
    if (rank == 0) {
        printf("\n\nFinal gathered data (doubled values): ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", gathered_data[i]); // Expected: 20, 40, 60, 80
        }
        printf("\n");
    }

    MPI_Finalize(); // Finalize MPI
    return 0;
}


// Terminal Command
// mpicc Lab_8.c
// mpiexec -np 4 ./a.out

// OUTPUT
// Process 0 scatters the following data: 10 20 30 40 
// Process 0 received number 10
// Process 1 received number 20
// Process 2 received number 30
// Process 3 received number 40


// Final gathered data (doubled values): 20 40 60 80