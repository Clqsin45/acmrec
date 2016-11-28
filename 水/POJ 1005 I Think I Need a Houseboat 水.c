#include <stdio.h>
#include <math.h>

#define  pai 3.1415926
double tb[1002];
int main(void)
{
    int i, t, n = 1;
    double sum = 0, a, b;
    for(i = 1; i <= 1000; i++)
    {
        tb[i] = sqrt(100.0 / pai + sum * sum);
        sum = tb[i];
    }
    scanf("%d", &t);
    while(n <= t)
    {
        scanf("%lf%lf",&a, &b);
        a = sqrt(a*a + b * b);
        for(i = 1; tb[i] < a; i++);
        printf("Property %d: This property will begin eroding in year %d.\n",n, i);
        n++;
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
