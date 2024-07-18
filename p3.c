#include<stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	}

int partition(int A[], int low, int high){
int pivot  = A[low];
int j = high;
for(int i = high; i>low;i--){
	if(A[i]>pivot)
		swap(&A[i],&A[j--]);
}
swap(&A[low],&A[j]);
return j;
}

void Quick(int A[], int start, int end){
if(start<end){
int index = partition(A,start,end);
Quick(A,start,index-1);
Quick(A,index+1,end);
}
}

void show(int A[], int size){
for(int i = 0; i< size;i++){
	printf("%d ",A[i]);
		}
printf("\n");
}

int main(){
int A[] = { 8,1,0,12,9,2,4,16,7,21};
int size = sizeof(A)/sizeof(A[0]);
Quick(A,0,size-1);
printf("Sorted Array : \n");
show(A,size);
return 0;
}