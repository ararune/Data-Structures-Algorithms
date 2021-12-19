#include <stdio.h>
#include <stdlib.h>
// splits an array into 2, creating copies of both parts 
int** splitArray(int* arr, int n) {
    int* firstArr = (int*)malloc((n / 2) * sizeof(int));
    int* secondArr = (int*)malloc((n / 2) * sizeof(int));
    int** pointerArray = (int**)malloc(2 * sizeof(int*));

    for (int i = 0, j = 0; i < (n / 2) * 2; i++) {
        if (i < (n / 2))
            firstArr[i] = arr[i];
        else
            secondArr[j] = arr[i], j++;
    }
    pointerArray[0] = firstArr;
    pointerArray[1] = secondArr;
    return pointerArray;

}

int main(void)
{
    int arr[] = { 1, 8, 9, 6, 3, 4, 2, 7, 1 };
    int n = sizeof(arr) / sizeof(int);
    int** newArr = splitArray(arr, n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            printf("%d ", newArr[i][j]);
        }
        printf("\n");
    }

    return 0;
}