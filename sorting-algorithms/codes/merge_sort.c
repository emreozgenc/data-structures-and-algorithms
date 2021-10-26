#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void printArray(int *, int);
void swap(int *, int *);
int *mergeSort(int *, int);
int *merge(int *, int *, int, int);

void main(int argc, char **args)
{
    int arr[] = {5, 6, 7, 15, 3, 4, 55, 12};
    int *sortedArr;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("First state of the array : ");
    printArray(arr, size);

    sortedArr = mergeSort(arr, size);

    printf("\nState of the array after sorting : ");
    printArray(sortedArr, size);
    getch();
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}

int *mergeSort(int *arr, int size)
{

    if (size <= 1)
        return arr;

    int middle = size / 2;
    int index = 0;
    int *result = (int *)malloc(sizeof(int) * size);
    int *left;
    int rightSize;
    int *right;

    if (size % 2 == 0)
        rightSize = middle;
    else
        rightSize = middle + 1;

    left = (int *)malloc(sizeof(int) * middle);
    right = (int *)malloc(sizeof(int) * rightSize);

    for (int i = 0; i < middle; i++)
        left[i] = arr[index++];

    index = 0;

    for (int i = middle; i < size; i++)
        right[index++] = arr[i];

    left = mergeSort(left, middle);
    right = mergeSort(right, rightSize);
    result = merge(left, right, middle, rightSize);

    return result;
}

int *merge(int *left, int *right, int leftSize, int rightSize)
{
    int resultSize = leftSize + rightSize;
    int *result = (int *)malloc(sizeof(int) * (resultSize));

    int resultIndex = 0;
    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (left[leftIndex] <= right[rightIndex])
            result[resultIndex++] = left[leftIndex++];

        else
            result[resultIndex++] = right[rightIndex++];
    }

    if (leftIndex < leftSize)
    {
        while (leftIndex < leftSize)
            result[resultIndex++] = left[leftIndex++];
    }

    if (rightIndex < rightSize)
    {
        while (rightIndex < rightSize)
            result[resultIndex++] = right[rightIndex++];
    }

    return result;
}