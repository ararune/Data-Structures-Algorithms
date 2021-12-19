#include <stdio.h>
#include <stdlib.h>
// return an array that is a copy of original array from start to stop position
int* subArray(int* arr, int start, int stop) {
    int* newArr = (int*)malloc((stop - start) * sizeof(int));
    int j = 0;
    for (int i = start; i < stop + 1; i++, j++)
        newArr[j] = arr[i];
   
    return newArr;

}

int main(void)
{
    int arr[] = { 1,2,3,4,5,6,7,8 };
    int start = 2;
    int stop = 5;
    stop++;
    int* newArr = subArray(arr, start, stop);
    for (int i = 0; i < (stop - start); i++) {
        printf("%d ", newArr[i]);
    }

    return 0;
}