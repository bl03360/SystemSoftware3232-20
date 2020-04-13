#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int less_than, middle, greater_than;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int n, part, x;

void  *collatzList(void* arg) {
    
	pthread_mutex_lock(&lock);
    
	for(int i = x*part; i < (part * x) + part; i++) {
		int length = 1;
		int a = i + 1;
		while(a != 1){
			if(a%2==0){ 
				a = a/2;
			}
			else{
				a = ((3*a)+1)/2;
			}
			length++;
		}
		if(length <= 8){
			less_than++;
		}
		else if(length >= 16){
			greater_than++;
		}
		else
			middle++;
	}
	
	x++;
	pthread_mutex_unlock(&lock);
	
	return NULL;
}

int main(int argc, char *argv[]) {
	
	int tmp;
	n = atoi(argv[1]);
	if ((n < 2) || (n > 6)) {
		printf("Integer value must between 2 and 6, inclusive");
		return 0;
		}
		
	pthread_t thread[n];
	part = 60 / n;
	
	
	printf("Using %d threads\n", n);
	
	for (int i = 0; i < n; i++) {
	    tmp = pthread_create(&thread[i], NULL, collatzList, NULL);
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
	
	printf("The number of integers from 1~60 whose Collatz list has length <=8 is %d\n", less_than);
	printf("The number of integers from 1~60 whose Collatz list has length between 8 and 16 exclusive is %d\n", middle);
	printf("The number of integers from 1~60 whose Collatz list has length >=16 is %d", greater_than);
}
