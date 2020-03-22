#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int row = 5;
int col =  12;
int n, part, a;

void  *squareNum(void* arg) {
    
    int (*num)[col] = arg;
	
	if (a > n) return 0;
     
    for (int i = 0; i < row; i++) { 
	    for (int j = a * part; j < ((part * a) + part); j++) {
	        num[i][j] *= num[i][j];
	    }
	}
    a++;
}
int main(int argc, char *argv[]) {
	
	int tmp;
	n = atoi(argv[1]);
	if ((n < 2) || (n > 4)) {
		printf("Integer value must between 2 and 4, inclusive");
		return 0;
		}
	
	int num[row][col];	
	part = col / n;
	pthread_t thread[n];
	
	printf("Using %d threads.\n", n);
	printf("Original array:\n");
	
	for (int i = 0; i < row;i++) {
		for (int j = 0; j < col;j++) {
			num[i][j] = (rand() % (49 - 1) + 1) + 1; 
			printf("%d ",num[i][j]);
		}
		printf("\n");
	}
	
	printf("\nUpdated array\n");
	
	for (int i = 0; i < n; i++) {
	    tmp = pthread_create(&thread[i], NULL, squareNum, &num);
		    if (tmp != 0){
			    printf("Creating thread %d failed\n", i);
			    return 1;
		    }
	}
    
	for (int i = 0; i < n; i++) {
		tmp = pthread_join(thread[i], NULL);
			if (tmp != 0){
				printf("Joing thread %d failed\n", i);
				return 1;
			}
	}
	
	for (int i = 0; i < row;i++) {
		for (int j = 0; j < col;j++) {
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}