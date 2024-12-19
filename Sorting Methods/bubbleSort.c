#include <stdio.h>
#include <stdbool.h>

// bubble Sort
void BubbleSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        // it require only (len-1-i) recursions
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
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

    BubbleSort(arr, len);

    // display array
    DisplayArray(arr, len);

    return 0;
}
