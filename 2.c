#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d, e;
    printf("nhap lan luot gia tri cua a, b, c, d, e: ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    if (e == 0)
    {
        printf("nhap lai e (e != 0): ");
        scanf("%d", &e);
    }

    float result = pow((a + b), c) - ((float)d / e);
    printf("result = %.2f", result);
}