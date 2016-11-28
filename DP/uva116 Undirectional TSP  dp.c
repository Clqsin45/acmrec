#include <stdio.h>

int a[12][102], f[12][102], r[12][102];
int main(void)
{
    int m, n,i, j, k, min, am = 2147483647, st;
    while(scanf("%d %d", &m, &n) == 2)
    {
        am = 2147483647;
        for(i = 1; i <= m; i++)
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &a[i][j]);
                if(j == n)
                {
                    f[i][j] = a[i][j];
                    r[i][j] = i;
                }

            }

        for(i = n - 1; i >= 1; i--)
        {
            for(j = 1; j <= m; j++)
            {
                min = 2147483647;
                for(k = -1; k <= 1; k++)
                {
                    if(j + k < 1)
                    {
                        if(f[m][i + 1] < min)
                        {
                            min = f[m][i + 1];
                            r[j][i] = m;
                        }
                    }
                    else if(j + k > m)
                    {
                        if(f[1][i + 1] <= min)
                        {
                            min = f[1][i + 1];
                            r[j][i] = 1;
                        }
                    }
                    else
                    {
                        if(f[j + k][i + 1] < min)
                        {
                            min = f[j + k][i + 1];
                            r[j][i] = j + k;
                        }
                        else if(f[j + k][i + 1] == min && (j + k < r[j][i]))   r[j][i] = j + k;
                    }
                }
                f[j][i] = min + a[j][i];
                if(i == 1 && f[j][1] < am)
                {
                    am = f[j][1];
                    st = j;
                }

            }
        }
        for(i = st, j = 1; j < n; i = r[i][j], j++)
            printf("%d ",i);
        printf("%d\n%d\n", i, am);
    }
    system("pause");
    return 0;
}
