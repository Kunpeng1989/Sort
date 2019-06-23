#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 100000

#define OK 0
#define ERROR -1

void swap(int *a, int *b){	
	int temp =0;
	temp = *a;
	*a = *b;
	*b = temp;	
}

void print_array(int array[], int length){
	int index = 0;
	printf("\n");
	for(index = 0; index < length; index++){
		printf("%d ", array[index]);
	}
	printf("\n");
}

void SelectSort(int array[], int length){
	int i =0, j =0;
	int max_index = 0;

	for(i=0; i< MAX-1; i++){
		max_index = 0;
		for(j = 1; j < MAX-i; j++){  /*每一轮选出一个本轮最大数组元素，并记录这个数组元素的下标max_index*/
			if(array[j] > array[max_index]){
				max_index = j;				
			}
		}
		if(max_index != j-1){
			swap(&array[max_index], &array[j-1]);/*将每一轮最大的数放在最后边*/
		}
	}

}

int main(){
	int array[MAX] = {0};	
	int i = 0;	
	
	srand((unsigned)time(NULL));/*随机数种子*/	
	for(i = 0; i < MAX; i++){
		array[i] = (rand() % MAX);/*产生随机整数*/
	}

	print_array(array, MAX);	
	SelectSort(array, MAX);
	print_array(array, MAX);	
	return 0;
}

