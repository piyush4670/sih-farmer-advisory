#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1, j, temp;

    for (j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    int a[6] = {5, 2, 8, 1, 9, 3};
    int i;

    quickSort(a, 0, 5);

    printf("Sorted array: ");

    for (i = 0; i < 6; i++)
        printf("%d ", a[i]);

    return 0;
}
