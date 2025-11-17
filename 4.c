#include <math.h>
#include <stdio.h>

void enterNum(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    int arr[n];
    enterNum(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("array sau khi sap xep: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}