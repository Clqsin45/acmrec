#include <stdio.h>
int f[55][55], a[55];
int main(void)
{
    int l, n, i, j ,k, min;

    while(scanf("%d", &l) == 1 && l)
    {
        scanf("%d", &n);
        a[0] = 0;   a[n + 1] = l;   f[0][1] = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            f[i][i + 1] = 0;
        }
        for(i = 2; i <= n + 1; i ++)
        {
            for(j = 0; j <= n - i + 1; j++)
            {
                min = 10000000;
                for(k =j + 1; k < (i + j); k++)
                {
                    if(min > (f[j][k] + f[k][i + j]) )  min = f[j][k] + f[k][i + j];
                }
                f[j][i + j] = min + a[i + j] - a[j];
            }
        }
        printf("The minimum cutting is %d.\n", f[0][n + 1]);
    }
    system("pause");
    return 0;
}
