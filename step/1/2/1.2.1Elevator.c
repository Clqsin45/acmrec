#include<stdio.h>
int main(void)
{
    int n, a, i, t, sum;
    while(scanf("%d", &n) && n)
    {
        t = 0;  sum = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            if(a > t)   sum += ((a - t) * 6);
            else sum += ((t - a) * 4);
            t = a;
        }
        sum += (n * 5);
        printf("%d\n",sum);
    }

    return 0;
}
