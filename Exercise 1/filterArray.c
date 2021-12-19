#include <stdio.h>
#include <stdlib.h>
// filter out values lesser than th from an array
int* filter(int* arr, int n, int th, int* nth) {

    *nth = 0;
    int* newArr = (int*)malloc(n * sizeof(int));
    if (!newArr) {
        printf("ERROR");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < th) {
            newArr[*nth] = arr[i];
            (*nth)++;
        }
    }
    if (*nth != n) //reallocate if new array is smaller than the original after filtering 
        realloc(newArr, *nth * sizeof(int));
    return newArr;
}

int main(void)
{
    int arr[] = { 1, 3, 5, 15, 12, 9, 6, 100 };
    int n = sizeof(arr) / sizeof(int);
    int nThreshold = 0;
    int threshold = 10;
    int* newArr = filter(arr, n, threshold, &nThreshold);
    for (int i = 0; i < nThreshold; i++)
        printf("%d ", newArr[i]);
    return 0;
}