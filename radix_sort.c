#include <stdio.h>
#include <stdlib.h>

int a[100], n;

void input()
{
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display()
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int getMax()
{
    int max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void radixSort()
{
    int max = getMax();
    int output[100], count[10];
    int place, i, digit;

    for (place = 1; max / place > 0; place *= 10)
    {
        for (i = 0; i < 10; i++)
            count[i] = 0;

        for (i = 0; i < n; i++)
        {
            digit = (a[i] / place) % 10;
            count[digit]++;
        }

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--)
        {
            digit = (a[i] / place) % 10;
            output[--count[digit]] = a[i];
        }

        for (i = 0; i < n; i++)
            a[i] = output[i];
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Input\n");
        printf("2. Display\n");
        printf("3. Radix Sort\n");
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
                radixSort();
                printf("Sorted: ");
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}