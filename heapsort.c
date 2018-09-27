#include <stdio.h>

void heapIf(int num_arr[], int size, int n)
{
    
    int largest = n, temp;
    int leftChild = 2 * n + 1;
    int rightChild = 2 * n + 2;
    
    if(leftChild < size && num_arr[leftChild] > num_arr[largest]){
        largest = leftChild;
    }
    
    if(rightChild < size && num_arr[rightChild] > num_arr[largest]){
        largest = rightChild;
    }
    
    if(largest != n){
      temp = num_arr[n];
      num_arr[n] = num_arr[largest];
      num_arr[largest] = temp;
      heapIf(num_arr, size, largest);
    }
}

void heapSort(int num_arr[], int s){
    int temp;
    for(int c = s / 2 -1; c >= 0; c--){
        heapIf(num_arr, s, c);
    }
    
    for(int c = s - 1; c >= 0; c--){
        temp = num_arr[0];
        num_arr[0] = num_arr[c];
        num_arr[c] = temp;
        heapIf(num_arr, c, 0);
    }
}

void printArray(int num_arr[], int s){
    for(int c = 0; c < s; c++){
       printf("%d, ", num_arr[c]);
    }
    printf("\n");
}


int main()
{
    printf("Heapsort \n");
    int num_arr[] = {12, 33, 10, 45, 3, 15};
    int size = sizeof(num_arr)/sizeof(num_arr[0]);
    
    heapSort(num_arr, size);
    printf("Sorting completed \n");
    printArray(num_arr, size);
    
    return 0;
}
