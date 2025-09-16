# PARALLEL-COMPUTING-LAB 
- Course Code : BCS702
- Credits : 4

## Course outcomes:
* Explain the need for parallel programming
* Demonstrate parallelism in MIMD system.
* Apply MPI library to parallelize the code to solve the given problem.
* Apply OpenMP pragma and directives to parallelize the code to solve the given problem
* Design a CUDA program for the given problem.

## Lab Experiments
1. Write an OpenMP program that divides the Iterations into chunks containing 2 iterations, respectively (OMP_SCHEDULE=static,2). Its input should be the number of iterations, and its output should be which iterations of a parallelized for loop are executed by which thread. For example, if there are two threads and four iterations, the output might be the following:
- a. Thread 0 : Iterations 0 −− 1
- b. Thread 1 : Iterations 2 −− 3
2. 1 Write a OpenMP program to sort an array on n elements using both sequential and parallel mergesort(using Section). Record the difference in execution time.
3. Write a OpenMP program to calculate n Fibonacci numbers using tasks.
4. Write a OpenMP program to find the prime numbers from 1 to n employing parallel for directive. Record both serial and parallel execution times.
5. Write a MPI Program to demonstration of MPI_Send and MPI_Recv.
6. Write a MPI program to demonstration of deadlock using point to point communication and avoidance of deadlock by altering the call sequence
7. Write a MPI Program to demonstration of Broadcast operation.
8. Write a MPI Program demonstration of MPI_Scatter and MPI_Gather
9. Write a MPI Program to demonstration of MPI_Reduce and MPI_Allreduce (MPI_MAX,MPI_MIN, MPI_SUM, MPI_PROD)

<b style="color: red;"><marquee>[ Above experiments are in order of lab execution date]</marquee></b>

## Experiment Dates
<table style="border: 2px solid;">
    <tr>
        <th>Experiment No</th>
        <th>Date </th>
    </tr>
    <tr>
        <td>Lab 1</td>
        <td>12-09-2025 </td>
    </tr>
    <tr>
        <td>Lab 2</td>
        <td>16-09-2025 </td>
    </tr>    
</table>

## Command for Execution
<pre><code>
gcc FileName.c -fopenmp 
</code></pre>


