#include <stdio.h>

int FindMax(int [], int );
void Sort(int array[], int size);

int main() {
	
	int i, max, array[10];
	
	for(i=0; i<10; i++) {
		printf("Give %d number: ", i+1);
		scanf("%d", &array[i]);
	}
	
	Sort(array, 10); 
	max = FindMax(array, 10); 
	printf("One number exists: %d times.\n", max);

	return 0;
}

int FindMax(int array[], int size) {
	
	int i, j;
	int max=1, temp = 1;
	
	for(i=0; i<size; i++) {
		for(j=i+1; j<size;) {
			if(array[i] == array[j]) { 
				temp++; 
				j++; 
			}else { //If values aren't equal, then we have to change some things.
				if(temp>max) { //This check is in case, we have more than 1 duplicate number(for example, number 5 occurs 3 times but number 13 occurs 2 times, so don't want to change max
					max = temp; 
					temp = 1; //reseting temp
				}	
			}
			j += size; //If we find out, that there is no more duplicate number as array[i] value, then we want to stop J loop, so we add a large number to stop it.
		} 
	}
	
	return max;
}	

void Sort(int array[], int size) {
	
	int i, j, temp;
	
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			if(array[i]<array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
