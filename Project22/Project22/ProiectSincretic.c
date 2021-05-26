#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void QuickSort(int* number, int first, int last) {
    int i, j, pivot, temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j) {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }

        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        QuickSort(number, first, j - 1);
        QuickSort(number, j + 1, last);

    }
}

void ShellSort(int* arr, int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for (k = j - i; k >= 0; k = k - i)
            {
                if (arr[k + i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k + i];
                    arr[k + i] = tmp;
                }
            }
        }
    }
}

void BubbleSort(int* arr, int n)
{
    int swap;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
}

void display(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

}

int main()

{
    srand(time(NULL));

    clock_t t;

    int n;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int* randArray1 = (int*)malloc(n * sizeof(int));
    int* randArray2 = (int*)malloc(n * sizeof(int));
    int* randArray3 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        randArray1[i] = rand() % 100;   
        randArray2[i] = randArray1[i];
        randArray3[i] = randArray1[i];
    }

    
    printf("\nElements of the array:");
    display(randArray1, n);

    t = clock();
    ShellSort(randArray1, n);
    if (n <= 20)
    {
        printf("\nElements of the array after ShellSort:");
        display(randArray1, n);
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; 

    printf("\nShellsort took %f seconds to execute \n", time_taken);

    
    t = clock();
    QuickSort(randArray2, 0, n);
    if (n <= 20)
    {
        printf("\nElements of the array after QuickSort:");
        display(randArray2, n);
    }
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nQuicksort took %f seconds to execute \n", time_taken);

    
    t = clock();
    BubbleSort(randArray3, n);
    if (n <= 20)
    {
        printf("\nElements of the array after BubbleSort:");
        display(randArray3, n);
    }
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC; 

    printf("\nBubbleSort took %f seconds to execute \n", time_taken);

    return 0;
}