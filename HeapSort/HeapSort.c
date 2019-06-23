#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/timeb.h>



#define MAX 10000
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
		AdjustHeap(array, 0, i); /*注意第三个参数为i，即树的这次调整范围小于i*/
	}
	
}
int main(){
	int array[MAX] = {0};	
	int i = 0;
	long long start_time, end_time, run_time;
	
	srand((unsigned)time(NULL));/*随机数种子*/	
	for(i = 0; i < MAX; i++){
		array[i] = (rand() % MAX);/*产生随机整数*/
	}
	print_array(array, MAX);
	start_time = GetSystemTime();
	HeapSort(array, MAX);
	end_time = GetSystemTime();
	run_time = end_time - start_time;
	printf("堆排序对 %d 个随机数进行排序，耗时: %lld ms\n", MAX, run_time);
	print_array(array, MAX);	
	return 0;
}

