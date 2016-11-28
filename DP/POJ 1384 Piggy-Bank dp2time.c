#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
int w[505], v[505], f[10004];
int min(int x, int y)
{
    return x < y ? x : y;
}
int main(void)
{
    int t, n, m, i, j, m1, m2;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m1, &m2);    m = m2 - m1;
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
            scanf("%d%d", &v[i], &w[i]);
        for(i = 0; i <= m; i++) f[i] = INF;
        f[0] = 0;
        for(i = 1; i <= n; i++)
        {
            for(j = w[i]; j <= m; j++)
            {
                f[j] = min(f[j], f[j - w[i]] + v[i]);
            }
        }
        if(f[m] == INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", f[m]);
    }
    return 0;
}
