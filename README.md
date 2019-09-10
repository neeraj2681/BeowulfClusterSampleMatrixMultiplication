# BeowulfClusterSampleMatrixMultiplication
Multiplying a sample matrix by itself in a clustered environment with the slave and master node configuration, by using each node's processing power.
The user will provide the matrix size, and on the basis of that the program will output the time taken to calculate the square of matrix in both parallel and non-parallel computing.

Files Description:
ag.c : A C program to generate a "file.h" file to store the sample matrix.

machinefile : A file to store the info about cores in slave and master nodes.

matrixRunner.sh : A script to run all the commands one after another in serial manner.

npmatrix.c : A simple C program to calculate the square of a matrix by itself.

pmatrix.c : A C program using MPI to calculate square of a matrix.
