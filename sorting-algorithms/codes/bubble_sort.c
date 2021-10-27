#include <stdio.h>
#include <conio.h>

void bubbleSort(int *, int);
void swap(int *, int *);
void printArray(int *, int);

void main(int argc, char **args)
{
    int arr[] = {7, 8, 9, 0, 2, 3, 7, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("First state of the array : ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("\nState of the array after sorting : ");
    printArray(arr, size);
    getch();
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j=0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}