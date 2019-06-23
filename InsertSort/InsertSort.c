#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 1000
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

void InsertSort(int array[], int length){
	int i = 0, j =0, index =0, temp=0;
	
	for(i=1; i< length; i++){
		index = i;
		temp = array[i]; /*待插入元素*/
		for(j = i-1; j >=0; j--){
			if(temp < array[j]){
				array[j+1] = array[j]; /*大元素后移*/
				index = j;/*更新插入位置*/
			}
			else{
				break;
			}
		}
		array[index] = temp;/*将元素插入合适位置*/
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
	InsertSort(array, MAX);
	print_array(array, MAX);	
	return 0;
}

