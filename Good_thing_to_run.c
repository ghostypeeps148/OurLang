#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(){
	uint32_t *x = malloc(1);
	if(x == NULL){
		return -1;
	}
	
	for (uint32_t i = 0; i < 0xFFFFFFFF - 1; i++){
		printf("allocating x of size: %x bytes\n", i);
		x = (uint32_t*)realloc(x, i);
		if(x == NULL){
			free(x);
			return -1;
		}
	}
	free(x);
	printf("bye");
	return 0;
}
