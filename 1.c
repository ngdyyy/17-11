#include <math.h>
#include <stdio.h>

void sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);

        sum = sum + arr[i];
    }
    printf("sum = %d", sum);
}

int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);

    int arr[n];
    sum(arr, n);
}