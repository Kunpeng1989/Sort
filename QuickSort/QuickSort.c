#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/timeb.h>



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

//获取当前系统的时间(距离1970-01-01的时间),单位毫秒
long long GetSystemTime()
{
	struct timeb t;
	ftime(&t);
	return 1000 * t.time + t.millitm;
}

void QuickSort(int array[], int start, int end){
	int i = 0, j =0;
	int basenum = array[start];/*基准数值*/
	
	if (start >= end) /*要设置退出递归条件*/
	{
		return;
	}
	
	i = start;
	j = end;	
	while(i < j){
		for(; j > i ; j--){
				if(array[j] <= basenum){
					array[i] = array[j];
					i++; /*这个位置的数肯定小于了basenum*/
					break;
				}
			}
		
		for(; i< j;i++){
			if(array[i] > basenum){
				array[j] = array[i];
				j--; /*这个位置的数肯定大于了basenum*/
				break;
			}
			
		}	
	}
	array[j] = basenum; /*基准数值填到最后一个空闲地方*/
	QuickSort(array, start, i-1);
	QuickSort(array, i+1, end);
}
int main(){
	int array[MAX] = {0};	
	int i = 0;
	long long start_time, end_time, run_time;
	
	srand((unsigned)time(NULL));/*随机数种子*/	
	for(i = 0; i < MAX; i++){
		array[i] = (rand() % MAX);/*产生随机整数*/
	}

	/*堆排序*/
	start_time = GetSystemTime();
	//print_array(array, MAX);	
	QuickSort(array, 0, MAX-1);
	//print_array(array, MAX)
	end_time = GetSystemTime();
	run_time = end_time - start_time;
	printf("堆排序对 %d 个随机数进行排序，耗时: %lld ms\n", MAX, run_time);
	
	return 0;
}


