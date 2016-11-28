#include <stdio.h>

int main(void)
{
    double a, sum = 0;
    int t = 12;
    while(t --)
    {
        scanf("%lf", &a);
        sum += a;
    }
    sum /= 12;
    printf("$%.2f\n", sum);
    system("pause");
    return 0;
}
