#include <stdio.h>
#include <stdlib.h>

int a[100], n;

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
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

/* Simple Sort */
void sort(int start, int end)
{
    int i, j, temp;

    for (i = start; i < end - 1; i++)
    {
        for (j = i + 1; j < end; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

/* Merge */
void merge(int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid, k = 0;

    while (i < mid && j < high)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i < mid)
        temp[k++] = a[i++];

    while (j < high)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[low + i] = temp[i];
}

/* Polyphase Merge Sort */
void polyphase()
{
    int mid = n / 2;

    sort(0, mid);
    sort(mid, n);

    merge(0, mid, n);

    printf("Sorted Array: ");
    display();
}

/* Main */
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Input\n");
        printf("2. Display\n");
        printf("3. Polyphase Merge Sort\n");
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
                polyphase();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}