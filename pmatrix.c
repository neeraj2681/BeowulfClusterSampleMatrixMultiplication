#include<stdio.h>
#include<mpi.h> // library to use MPI
#include<time.h> // library to calculate the execution time
#include "file.h" //File to read the matrix array
#include<stdlib.h>


//Method to calculate the matrix multiplication
void calculate(int arr2[l][l], int start){
	for(int i = 0; i < l; i++){
		for(int j = start; j < l; j+=2){
			for(int k = 0; k < l; k++){
				ans[i][j] = ans[i][j] + arr2[k][j] * arr2[i][k];
			}
		}
	}
}


int main(int argc, char **argv){
	clock_t start, end;
	double cpu_time_used;
	start = clock();

	int myrank, nprocs;

//Intialising the MPI Environment
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

//chechking the processor no.
	if(myrank == 0){
		calculate(arr, 0);
	}else
		calculate(arr, 1);

		end = clock();
		cpu_time_used = ((double) (end - start) / 	CLOCKS_PER_SEC);


//sending time;
float number;
if (myrank == 0) {
    number = cpu_time_used;

    printf("Node %d: %f\n", myrank + 1, cpu_time_used);
    
    MPI_Send(&number, 1, MPI_FLOAT, 1, 0, MPI_COMM_WORLD);
} else if(myrank == 1){

	
    MPI_Recv(&number, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);

    
    printf("Node %d: %f\n", myrank + 1, cpu_time_used);
    printf("Parallel Processing:     %f\n", (number + cpu_time_used));
    printf("\n");
}

	MPI_Finalize(); // finalising the MPI
	return 0;
}