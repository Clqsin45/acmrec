#include <stdio.h>
#include <string.h>
#define MIN -100000000

int max(int x, int y)
{
    return x > y ? x : y;
}

int f[102][102], d[102], w[102];

int main(void)
{
    int t, n, kd, nn ,s, i , j, k;
    while(scanf("%d%d", &n, &t) == 2)
    {
        memset(f,0, sizeof(f));
        for(i = 1; i <= n ; i++)
        {
            scanf("%d%d", &nn, &s);
            for(j = 1; j <= nn; j++)    scanf("%d%d", &w[j], &d[j]);
            switch(s)
            {
                case 0:
                    for(j = 0; j <= t; j++)    f[i][j] = MIN;
                    for(j = 1; j <= nn; j++)
                    {
                        for(k = t; k >= w[j]; k--)
                        {
                            f[i][k] = max(f[i][k],max(f[i- 1][k - w[j]] +d[j],f[i][k - w[j]] + d[j]));
                        }
                    }
                    break;
                case 1:
                    for(j = 0; j <= t; j++)     f[i][j] = f[i - 1][j];
                    for(j = 1; j <= nn; j++)
                        for(k = t; k >= w[j]; k--)
                            f[i][k] = max(f[i][k], f[i - 1][k - w[j]] + d[j]);
                    break;
                case 2:
                    for(j = 0; j <= t; j++)     f[i][j] = f[i - 1][j];
                    for(j = 1; j <= nn; j++)
                        for(k = t; k >= w[j]; k--)
                        {
                            f[i][k] = max(f[i][k], f[i][k - w[j]] + d[j]);
                        }
                    break;
            }
        }
        f[n][t] = max(f[n][t], -1);
        printf("%d\n", f[n][t]);
    }
    system("pause");
    return 0;
}
