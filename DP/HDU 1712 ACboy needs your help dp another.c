#include <stdio.h>
#include <string.h>
#define mem(a,b) memset(a, b, sizeof(a))
int f[102], d[102][102];

int max(int x, int y)
{
    return x > y ? x : y;
}
int main(void)
{
    int m, n, i, k, j;
    while(scanf("%d%d", &n, &m) && (m || n))
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                scanf("%d", &d[i][j]);
            }
        }
        mem(f, 0);
        for(i = 1; i <= n; i++)
        {
            for(j = m; j >= 0; j--)
            {
                for(k = 1; k <= j; k++)
                {
                    f[j] = max(f[j] , f[j - k] + d[i][k]);
                }
            }
        }
        printf("%d\n", f[m]);
    }

    return 0;
}
