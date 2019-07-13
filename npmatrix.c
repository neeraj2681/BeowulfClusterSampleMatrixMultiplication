#include<stdio.h>
#include<time.h>
#include "file.h"

void calculate(int arr2[l][l]){
	for(int i = 0; i < l; i++){
		for(int j = 0; j < l; j++){
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

	calculate(arr);
		end = clock();
		cpu_time_used = ((double) (end - start) / 	CLOCKS_PER_SEC);
	
	printf("Non-Parallel processing: %f\n", cpu_time_used);		
	printf("\n");	
	return 0;
}