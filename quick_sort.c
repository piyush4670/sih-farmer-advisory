#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low-1, j, temp;

    for(j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;

    return i+1;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(a, low, high);

        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Unsorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    quickSort(a, 0, n-1);

    printf("\nSorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
