#include <stdio.h>

// Insertion sort
void InsertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// display array
void DisplayArray(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{

    int arr[] = {48, 15, 52, 12, 4, 19, 8, 5};

    // get length of given array
    int len = sizeof(arr) / sizeof(arr[0]);

    // sort
    InsertionSort(arr, len);

    // display array
    DisplayArray(arr, len);

    return 0;
}