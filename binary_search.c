/******************************************************************************
*******************************************************************************/

#include <stdio.h>

int binarySearch(int arr[], int n, int c){
    int low = 0;
    int high = n - 1;
    
    while(low <= high){
        int mid = (low + high) / 2;
        if(c == arr[mid]){
            return mid;
        }else if(c < arr[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    
    return -1;
}

int main()
{
    int searchFor;
    printf("Enter number to search for: ");
    scanf("%d", &searchFor);
    
    int arr[] = {12, 45, 2, 23, 2, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = binarySearch(arr, size, searchFor);
    
    if(index != -1){
        printf("%d found at index %d", searchFor, index);
    }else{
        printf("Oops not able to find %d in array", searchFor);
    }

    return 0;
}
