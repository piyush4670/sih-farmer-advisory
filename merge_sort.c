#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int b[20], i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[6] = {5, 2, 8, 1, 9, 3};
    int i;

    mergeSort(a, 0, 5);

    printf("Sorted array: ");

    for (i = 0; i < 6; i++)
        printf("%d ", a[i]);

    return 0;
}
