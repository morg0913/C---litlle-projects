#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void initial_array_values(int *arr, int size){
	int i;
	for(i = 1; i < size; i++){
		*arr =  i;

		arr++;
	}
	arr[size-1] = 0;
}
int main(){
	
	int num_of_soldier = 20;
	int *soldiers;
	int i = 0;
	soldiers=(int*)malloc(100*sizeof(int));
	initial_array_values(soldiers, num_of_soldier);

	while(soldiers[i] != soldiers[soldiers[i]] ){
		soldiers[i] = soldiers[soldiers[i]];
		i = soldiers[i];
	}
	printf("%d\n",i+1);
	free(soldiers);
		
	
	
	
	return 0;
	
}
