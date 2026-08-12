#include <stdio.h>
#include <stdlib.h>

int a[100], n;

void input()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

/* Display Array */
void display()
{
    printf("Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

/* Interpolation Search */
void interpolationSearch()
{
    int target, low, high, pos;

    printf("Enter element to search: ");
    scanf("%d", &target);

    low = 0;
    high = n - 1;

    while (low <= high && target >= a[low] && target <= a[high])
    {
        pos = low + ((target - a[low]) )
                  / (a[high] - a[low]) * (high - low);

        if (a[pos] == target)
        {
            printf("Element found at position %d\n", pos + 1);
            return;
        }

        if (a[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    printf("Element not found\n");
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
        printf("3. Interpolation Search\n");
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
                interpolationSearch();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}