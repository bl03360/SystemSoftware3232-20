#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int len =  60;
int n, part;
int a;

void  *uppercase_to_lowercase(void* arg) {
    
	char *str = (char*) arg;
	
	if (a > n) return 0;
	 
	for(int i = a*part; i < ((part * a) + part);i++) {
	    str[i] = str[i] + 32;
	}
    a++;
}
int main(int argc, char *argv[]) {
	
	
	int tmp;
	n = atoi(argv[1]);
	if ((n < 2) || (n > 6)) {
		printf("Integer value must between 2 and 6, inclusive");
		return 0;
		}
		
	
	part = len / n;
	pthread_t thread[n];
	char str[len];
	
	printf("Using %d threads.\n", n);
	printf("Original upper case string:\n");
	
	for (int i = 0; i < len;i++) {
		str[i] = rand() % ('Z' - 'A' + 1) + 'A'; 
		printf("%c", str[i]);
		}
	
	printf("\nComplementary lower case string:\n");
	
	for (int i = 0; i < n; i++) {
	    tmp = pthread_create(&thread[i], NULL, uppercase_to_lowercase, &str);
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
	
	for (int i = 0; i < len;i++) {
		printf("%c", str[i]);
		}
		
	return 0;
}