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

void BubbleSort(int array[], int length){
	unsigned int i = 0, j =0;
	int flag = 1;
	for(i=0; i< length-1 && flag; i++){
			flag = 0;
			for(j = 0; j < MAX-i-1; j++){
				if(array[j] > array[j+1]){
					swap(&array[j], &array[j+1]);
					flag = 1; /*一轮数据循环后，有交换,说明数据还可能不是有序状态*/
				}
			}
	}

}


void SelectSort(int array[], int length){
	int i =0, j =0;
	int max_index = 0;

	for(i=0; i< length-1; i++){
		max_index = i;
		for(j = 1; j < length-i; j++){  /*每一轮选出一个本轮最大数组元素，并记录这个数组元素的下标max_index*/
			if(array[j] > array[max_index]){
				max_index = j;				
			}
		}
		if(max_index != j-1){
			swap(&array[max_index], &array[j-1]);/*将每一轮最大的数放在最后边*/
		}
	}

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

void ShellSort(int array[], int length){
	int i = 0, j =0, k = 0, temp =0, index =0;
	
	int increment = length;/*步长*/
	while(increment > 1){
		increment = increment/3+1; /*步长迭代经验值*/
		for(i= 0; i< increment; i++){
			
			for(j = i+increment; j < length; j += increment){
				temp = array[j];
				index = j;
				for (int k = j - increment; k >= 0; k -= increment){
					if(temp < array[k]){
					array[k+increment] = array[k];
					index = k; /*更新插入位置*/
					}else{
						break;
					}
				}
				array[index] = temp;/*将元素插入合适位置*/

			}				

		}
		
	}

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

    /*将每次更新的部分排序结果，更新到原数组中*/
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

/*从index结点开始递归调整使得父节点大于两个孩子节点，但调整范围不能超过boundary*/
void AdjustHeap(int array[], int index, int boundary){
	int max_index = index;
	int lchild = index*2+1; /*左孩子*/
	int rchild = index*2+2; /*右孩子*/
	
	if(lchild < boundary ){
		if(array[max_index] < array[lchild]){
			max_index = lchild;
		}
	}
	if(rchild < boundary){
		if(array[max_index] < array[rchild]){
			max_index = rchild;
		}
	}
	if(max_index != index){
		swap(&array[max_index], &array[index]);
		/*交换后要调整交换的那个孩子与孙子的结点，使其也符合大顶堆*/
	    AdjustHeap(array,max_index, boundary);			    
	}
}

void HeapSort(int array[], int length){
	int i = 0;

	/*从最后一个非叶子节点开始调整，调整为大顶堆*/
	for(i= (length/2 -1); i >= 0; i--){ 		
		AdjustHeap(array, i, length);	    
	}

		

   /*交换根节点和未排序的最后一个结点，然后再调整堆*/
	for(i= (length-1); i >= 0; i--){  
		swap(&array[0], &array[i]);		
		AdjustHeap(array, 0, i);
	}
	
}



void Compare(){
	int array[7][MAX] = {0};	
	int i = 0;
	int num = 0;
	long long start_time, end_time, run_time;
	
	srand((unsigned)time(NULL));/*随机数种子*/ 
	for(i = 0; i < MAX; i++){
		num = (rand() % MAX);/*产生随机整数*/
		array[0][i] = num;	
		array[1][i] = num;	
		array[2][i] = num;	
		array[3][i] = num;
		array[4][i] = num;	
		array[5][i] = num;
		array[6][i] = num;				
	}
	
	/*冒泡排序*/
	start_time = GetSystemTime();
	BubbleSort(array[0], MAX);
	end_time = GetSystemTime();
	run_time = end_time - start_time;
	printf("冒泡排序对 %d 个随机数进行排序，耗时: %lld ms\n", MAX, run_time);

	
	/*选择排序*/
	start_time = GetSystemTime();
	SelectSort(array[1], MAX);
	end_time = GetSystemTime();
	run_time = end_time - start_time;
	printf("选择排序对 %d 个随机数进行排序，耗时: %lld ms\n", MAX, run_time);

	
	/*插入排序*/
	start_time = GetSystemTime();
	InsertSort(array[2], MAX);
	end_time = GetSystemTime();
	run_time = end_time - start_time;
	printf("插入排序对 %d 个随机数进行排序，耗时: %lld ms\n", MAX, run_time);

	
	/*希尔排序*/
	start_time = GetSystemTime();
	ShellSort(array[3], MAX);
	end_time = GetSystemTime();
	run_time = end_time - start_time;
	printf("希尔排序对 %d 个随机数进行排序，耗时: %lld ms\n", MAX, run_time);

	
	/*快速排序*/
	start_time = GetSystemTime();
	QuickSort(array[4], 0, MAX-1);
	end_time = GetSystemTime();
	run_time = end_time - start_time;
	printf("快速排序对 %d 个随机数进行排序，耗时: %lld ms\n", MAX, run_time);

	
	/*归并排序*/
	start_time = GetSystemTime();	
	int *temp = (int *) malloc(sizeof(int)*MAX);
	if(NULL == temp){
		printf("malloc temp Error, line :%d\n", __LINE__);
		return;
	}		
	MergeSort(array[5], temp, 0, MAX-1);
	end_time = GetSystemTime();	
	run_time = end_time - start_time;
	printf("归并排序对 %d 个随机数进行排序，耗时: %lld ms\n", MAX, run_time);

	
	/*堆排序*/
	start_time = GetSystemTime();
	HeapSort(array[6], MAX);
	end_time = GetSystemTime();
	run_time = end_time - start_time;
	printf("堆排序对 %d 个随机数进行排序，耗时: %lld ms\n", MAX, run_time);

}

int main(){
	printf("\n第1次测试开始：\n");
	Compare();

	return 0;
}

