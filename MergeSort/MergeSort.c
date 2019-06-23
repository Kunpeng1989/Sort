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

void merge(int array[], int temp[], int left, unsigned right){
	int i=0, j=0, mid = 0, index = 0;
	mid = (left + right)/2;
	i = left;	
	j = mid+1;	
	index = 0;
	
	while(i<= mid && j <=right){
		if(array[i] <= array[j]){
			temp[index] = array[i];
			index++;
			i++;
		}else{
			temp[index] = array[j];
			index++;
			j++;
		}
	}
	while(i<=mid){
		temp[index]= array[i];		
		index++;
		i++;
	}
	while(j<=right){
		temp[index]= array[j];
		index++;
		j++;
	}

    /*将每次更新的部分排序结果，更新到原数组中, 否则递归中使用array有问题*/
	for(i = 0; i < index; i++){
		array[left+i] = temp[i];

	}
	
}
void MergeSort(int array[], int temp[],int left, unsigned right){
	int mid = (left + right)/2;
	
	if (left >= right) /*要设置退出递归条件*/
	{
		return;
	}

	MergeSort(array, temp, left, mid);
	MergeSort(array, temp, mid+1, right);
	merge(array, temp, left, right);
	
}
int main(){
	int array[MAX] = {0};	
	int i = 0;
	long long start_time, end_time, run_time;
	
	srand((unsigned)time(NULL));/*随机数种子*/	
	for(i = 0; i < MAX; i++){
		array[i] = (rand() % MAX);/*产生随机整数*/
	}

	int *temp = (int *) malloc(sizeof(int)*MAX);
	if(NULL == temp){
		printf("malloc temp Error, line :%d\n", __LINE__);
		return ERROR;
	}
	
	print_array(array, MAX);
	start_time = GetSystemTime();
	MergeSort(array, temp, 0, MAX-1);
	end_time = GetSystemTime();
	run_time = end_time - start_time;
	printf("堆排序对 %d 个随机数进行排序，耗时: %lld ms\n", MAX, run_time);
	print_array(array, MAX);
	return 0;
}

