#include <stdio.h>
#include <stdlib.h>

int a[100], n;

/* Swap two elements */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Find median of first, middle and last */
int medianOfThree(int low, int high)
{
    int mid = (low + high) / 2;
    int left = a[low];
    int center = a[mid];
    int right = a[high];

    if ((left <= center && center <= right) ||
        (right <= center && center <= left))
    {
        return mid;
    }

    if ((center <= left && left <= right) ||
        (right <= left && left <= center))
    {
        return low;
    }

    return high;
}

/* Partition */
int partition(int low, int high)
{
    int pivotIndex = medianOfThree(low, high);
    int pivot = a[pivotIndex];
    int i = low - 1;

    swap(&a[pivotIndex], &a[high]);

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

/* Quick Sort */
void quickSort(int low, int high)
{
    if (low < high)
    {
        int p = partition(low, high);

        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

/* Input */
void input()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

/* Display */
void display()
{
    printf("Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

/* Main */
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Input Array\n");
        printf("2. Display Array\n");
        printf("3. Median-of-Three Quick Sort\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                input();
                break;

            case 2:
                display();
                break;

            case 3:
                quickSort(0, n - 1);
                printf("Array sorted successfully.\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}