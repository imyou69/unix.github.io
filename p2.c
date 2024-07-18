#include<stdio.h>
#include<time.h>

void print(int A[], int n){
for(int i = 0; i< n; i++){
	printf("%d \t",A[i]);
	}
	printf("\n");
}

void inssort(int A[], int n){
for(int i = 1; i< n; i++){
    int key = A[i];
    int j = i - 1;
    while (key < A[j] && j >= 0) {
      A[j + 1] = A[j];
      --j;
    }
    A[j + 1] = key;
  }
}

int main(){
clock_t end, start;
int A[] = { 3,15,14,2,7,9,21};
int size = sizeof(A)/sizeof(A[0]);
start = clock();
inssort(A,size);
printf("Array in ascending order : \n");
print(A,size);
end = clock();
printf("Time taken to perform insertion sort %f",(double)(end-start)/CLOCKS_PER_SEC);
return 0;
}