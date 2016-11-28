#include <stdio.h>
#include <string.h>

int f[102][102];

int findmin(int x, int y)
{
    return x < y ? x : y;
}

void floyd(int n)
{
    int i, j , k;
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n ; j++)
                f[i][j] = findmin(f[i][j], f[i][k] + f[k][j]);
        }
    }
}
int main(void)
{
    int n, i, j, t, cp, ct, min, max;
    while(scanf("%d", &n) && n)
    {
        memset(f,44,sizeof(f));
        for(i = 1; i <= n ;  i++)
        {
            scanf("%d", &t);
            for(j = 1; j <= t; j++)
            {
                scanf("%d%d", &cp, &ct);
                f[i][cp] = ct;
            }
        }
        floyd(n);
        min = f[0][0];
        for(i = 1; i <= n; i++)
        {
            max = 0;
            for(j = 1; j <= n; j++)
                if(i!=j) max = (max > f[i][j]? max:f[i][j]);
            if(min > max)
            {
                cp = i;
                min = max;
            }
        }
        printf("%d %d\n", cp, min);
    }
    return 0;
}
