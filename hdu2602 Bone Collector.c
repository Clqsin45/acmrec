#include <stdio.h>
long long int w[1002], c[1002], f[1002][1002] = {0};

int main(void)
{
    int t, n, v, i, j;
    long long int max;
    scanf("%d",&t);
    while(t --)
    {
        max = 0;
        scanf("%d%d", &n, &v);
        for(i = 1; i <= n; i++)  scanf("%lld", &w[i]);
        for(i = 1; i <= n; i++)  scanf("%lld", &c[i]);

        for(i = 1; i <= n; i++)
        {
            for(j = 0; j <= v; j++ )
            {
                if(j - c[i] >= 0)
                    f[i][j] = (f[i - 1][j] > (f[i - 1][j - c[i]] +w[i])? f[i - 1][j] :(f[i - 1][j - c[i]] + w[i]));
                else
                    f[i][j] = f[i - 1][j];
                if(max < f[i][j]) max = f[i][j];
            }
        }
        printf("%lld\n", max);
        memset(f, 0, sizeof(f));
    }
    system("pause");
    return 0;
}
