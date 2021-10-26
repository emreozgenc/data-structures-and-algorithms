#include <stdio.h>
#include <conio.h>

int partition(int *, int, int);
void quickSort(int *, int, int);
void swap(int *, int *);
void printArray(int *, int);

void main(int argc, char **args)
{
    int arr[] = {1, 1, 1, 1, 1, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("First state of the array : ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quickSort(int *arr, int first, int last)
{
    if (first < last)
    {
        int pivot = partition(arr, first, last);
        quickSort(arr, first, pivot - 1);
        quickSort(arr, pivot + 1, last);
    }
}

int partition(int *arr, int first, int last)
{
    int left = first;
    int right = last - 1;
    int pivot = arr[last];

    while (left <= right)
    {
        if (arr[right] >= pivot)
        {
            right--;
            continue;
        }
        else if (arr[left] < pivot)
        {
            left++;
            continue;
        }

        swap(&arr[left], &arr[right]);
    }

    swap(&arr[left], &arr[last]);

    return left;
}
