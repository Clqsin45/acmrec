#include <stdio.h>
#include <string.h>

#define INF 6000000
int d[504], w[504], f[10002] ;
int min(int x, int y)
{
    return x < y ? x : y;
}
int main(void)
{
    int t, n, m1, m2, m, i, j;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &m1, &m2);
        m = m2 - m1;
        scanf("%d",&n);
        for(i = 1; i <= 10002; i++) f[i] = INF;
        for(i = 1; i <= n; i++) scanf("%d%d", &d[i], &w[i]);
        f[0] = 0;

        for(i = 1; i <= n; i++)
        {
            for(j = w[i]; j <= m; j++)
            {
                if(j - w[i] >= 0)
                    f[j] = min(f[j], f[j - w[i]] + d[i]);
            }
        }
        if(f[m] == INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",f[m]);
    }
    system("pause");
    return 0;
}
