#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 30
#define OK 0
#define ERROR -1

void swap(int *a, int *b){	
	int temp =0;
	temp = *a;
	*a = *b;
	*b = temp;	
}

void print_array(int array[], int length){
	unsigned int index = 0;
	printf("\n");
	for(index = 0; index < length; index++){
		printf("%d ", array[index]);
	}
	printf("\n");
}

void BubbleSort(int array[], int length){
	unsigned int i = 0, j =0;
	int flag = 1;
	for(i=0; i< length-1 && flag; i++){
			flag = 0;
			for(j = 0; j < MAX-i-1; j++){
				if(array[j] > array[j+1]){
					swap(&array[j], &array[j+1]);
					flag = 1; /*一轮数据循环后，有交换说明数据还可能不是有序状态*/
				}
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
	BubbleSort(array, MAX);
	print_array(array, MAX);	
	return 0;
}
