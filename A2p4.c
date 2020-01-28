#include <stdio.h>

int main(){
	
	char i;
	
	for(i = 'a';i <= 'z';i++){
		printf("%c Ascii value:", i);
		printf("%d\n", i);
		
	}
	
	for(i = 'A';i <= 'Z';i++){
		printf("%c Ascii value:", i);
		printf("%d\n", i);
	}
	
	for(i = '0';i <= '9';i++){
	    printf("%c Ascii value:", i);
	    printf("%d\n", i);
	}
	
}