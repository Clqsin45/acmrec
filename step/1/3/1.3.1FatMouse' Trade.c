#include <stdio.h>

int r[1002];
double p[1002],a[1002], c[1002];
void swap(int x, int y)
{
    int t = r[x];
    r[x] = r[y];    r[y] = t;
    return;
}
int main(void)
{
    int i, j;
    double sum, z, m, n;
    while(scanf("%lf%lf", &m, &n))
    {
        sum = 0;
        if(m == -1 && n == -1)  break;
        for(i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &a[i], &c[i]);
            if(!c[i])   p[i] = 10000000;
            else    p[i] = a[i] / c[i];
            r[i] = i;
        }
        for(i = 1; i <= n ; i++)
        {
            for(j = 1; j <= n - i; j++)
            {
                 if(p[r[j]] < p[r[j + 1]]) swap(j , j + 1);
            }

        }
        for(i = 1; i <= n; i++)
        {
            if(c[r[i]] <= m)
            {
                 sum += a[r[i]];
                 m -= c[r[i]];
            }
            else
            {
                sum += m /c[r[i]] * a[r[i]]; break;
            }
        }

        printf("%.3f\n", sum);

    }
    return 0;
}
